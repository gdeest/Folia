#include <QString>
#include "Shape.h"

using namespace std;
using namespace Magick;

Shape::Shape(const Magick::Image image)
{
	this->image = image;
	
	Magick::ColorRGB white(1.0, 1.0, 1.0);
	
	// Magick::
	
	//this->contour = Magick::Image(Magick::Geometry(image.columns(), image.rows(), 0, 0), white);
	this->contour = image;
	this->rows = this->image.rows();
	this->columns = this->image.columns();
	
	this->pixels.resize(5);
	
	this->index = 0;
	this->lenght = 0;
	this->aire = 0;
}

Shape::~Shape()
{
	
}

void Shape::calculate(void)
{
	cout << "Calculate Perimeter" << endl;
	
//	this->image.display();
	this->image.threshold(0.7*65535); // Noir et blanc
//	this->image.display();
	this->contour.threshold(0.7*65535);
	
	calculateAire();
	
	
	findFirstPixel();

	this->index = 0;	
	findNextPixels(pixel[0], pixel[1], dir);
	
	calculatePerimeter();
	cout << "Perimetre : " << this->lenght << " pixels" << endl;
	
	//this->image.write("" + this->fileName + "-shape.png");
//	this->contour.display();
}

double Shape::getAire()
{
	return aire;
}

double Shape::getPerimetre()
{
	return(this->lenght);
}

bool Shape::lastI(void)
{
	if(this->pixel[0] == this->rows-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Shape::lastJ(void)
{
	if(this->pixel[1] == this->columns-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Shape::calculateNextPosition(int lastDir)
{
	//if it is odd
	if(lastDir&1)
	{
		return((lastDir + 6) % 8);
		
	}else
	{
		return((lastDir + 7) % 8);
	}
	
	return 0;
}

bool Shape::isBlackPixel(int row, int col)
{
	ColorMono color = this->image.pixelColor(col,row);
	
	//cout << "Pixel color : " << color.mono() << endl;
	
	if(!color.mono()) //pixel is black == false
	{
		
		ColorRGB redColor(255.0, 0.0, 0.0);
		
		try 
		{
			this->contour.pixelColor(col,row,redColor);
		} catch (Magick::ErrorOption e) {
			cout << "Erreur �: (" << col << ", " << row << ")" << endl;
		}
		
		return true;
	}
	
	return false;
}

/*
 * Méthode qui calcule le périmètre à l'aide de la
 * chaîne de contour.
 * 
 */
void Shape::calculatePerimeter(void)
{
	
	for(int i=0; i < pixels.size(); i++ )
	{
		Step* step = pixels[i];
		
		if(step != NULL)
		{
			//if it is odd
			if(step->direction&1)
			{
				this->lenght += 1.414;
			}
			else
			{
				this->lenght += 1;
			}	
		}else
		{
			cout << "Un fautif : " << i << endl;
		}
	} 
}

void Shape::calculateAire()
{
	for(int row =0; row < this->rows; row++)
	{
		for(int col = 0; col < this->columns; col++)
		{
			ColorMono color = this->image.pixelColor(col,row);
			
			if(!color.mono()) // is black
			{
				this->aire ++;
			}
		}
	}
	
	cout << "L'aire de la feuille en pixels est : " << this->aire << endl;
}

void Shape::addPixelToVector(int i, int j, int dir)
{
	if(pixels.size() == index)
	{
		pixels.resize(index+2);
	}
	
	Step* step = new Step(i,j,dir);
	if(step == NULL)
	{
		cout << "Cr�ation du Step failed" << endl;
	}
	else
	{
		pixels[index] = step;
		index ++;
		//cout << "Pixel (" << i << "," << j << "), dir " << dir << " is added to vector" << endl;		
	}
}

bool Shape::isAtBegining(int i, int j)
{
	if(i == this->pZero[0] && j == this->pZero[1])
	{
		return true;
	}
	
	return false;
}

void Shape::iterationStep(int i, int j)
{
	if(isBlackPixel(i,j))
	{
		//Add pixel to vector
		this->addPixelToVector(pixel[0],pixel[1],dir);
		
		//Looking for next one
		pixel[0] = i;
		pixel[1] = j;
		
		dir = calculateNextPosition(dir);
		
		if(!isAtBegining(pixel[0],pixel[1]))
		{
			//Find next, recursive method
			findNextPixels(pixel[0], pixel[1], dir);	
		}
		else
		{
			return;
		}

	}
	else
	{
		findNextPixels(pixel[0], pixel[1], dir + 1);
	}
}

void Shape::findNextPixels(int pixelI, int pixelJ, int lastDir)
{
	
	pixel[0] = pixelI;
	pixel[1] = pixelJ;
	dir = lastDir;
	
	//cout << "Find next pixel for i : " << pixelI << ", j : " << pixelJ << ", dir : " << lastDir << endl;
	
	switch (lastDir)
	{ 
		case 0: //EAST SIDE 
			
			if(lastJ()) //Last column
			{
				findNextPixels(pixelI, pixelJ, lastDir + 1);
				return;
			}
			else //Not last column
			{
				//We check the pixel 
				iterationStep(pixelI,pixelJ+1);
				return;
			}
			
			return;
			break;
			
		case 1: //NORTH EAST SIDE
			
			if(lastJ() || pixelI == 0) //Last column or first row 
			{
				findNextPixels(pixelI, pixelJ, lastDir + 1);
				return;
			}
			else // Not last column and not first row
			{
				//We check the pixel
				iterationStep(pixelI-1,pixelJ+1);	
				return;
			}
			
			return;
			break;
			
		case 2: //NORTH SIDE
			
			if(pixelI != 0) //Not first row
			{
				//We check the pixel
				iterationStep(pixelI-1,pixelJ);
				return;
			}
			else //First row
			{
				findNextPixels(pixelI, pixelJ, lastDir + 1);
				return;
			}
			
			return;
			break;
			
		case 3: //NORTH WEST SIDE
			
			if(pixelI == 0 || pixelJ ==0) //First row or first column
			{
				findNextPixels(pixelI, pixelJ, lastDir + 1);
				return;
			}
			else //Not first row and not first column
			{
				//We check the pixel
				iterationStep(pixelI-1, pixelJ-1);
				return;
			}
			
			return;
			break;
			
		case 4: //WEST SIDE
			
			if(pixelJ != 0) //Not first column
			{
				//We check the pixel
				iterationStep(pixelI,pixelJ-1);
				return;
			}
			else //First column
			{
				findNextPixels(pixelI, pixelJ, lastDir + 1);
				return;
			}
			
			return;
			break;
			
		case 5: //SOUTH WEST SIDE
			
			if(lastI() || pixelJ ==0) //Last row or first column
			{
				findNextPixels(pixelI, pixelJ, lastDir + 1);
				return;
			}
			else //Not last row and not first column
			{
				//We check the pixel
				iterationStep(pixelI+1, pixelJ-1);
				return;
			}
			
			return;
			break;
			
		case 6: //SOUTH SIDE
			
			if(!lastI()) //Not last row
			{
				//We check the pixel
				iterationStep(pixelI+1, pixelJ);
				return;
			}
			else //Last row
			{
				findNextPixels(pixelI, pixelJ, lastDir + 1);
				return;
			}
			
			return;
			break;
			
		case 7: //SOUTH EAST
			
			if(lastI() || lastJ()) //Last row or last column
			{
				findNextPixels(pixelI, pixelJ, lastDir + 1);
				return;
			}
			else //Not last row and last column
			{
				//We check the pixel
				iterationStep(pixelI+1, pixelJ+1);
				return;
			}
			
			return;
			break;

		default: 

			lastDir = 0;
			findNextPixels(pixelI, pixelJ, lastDir);
			return;
			
			break; 
	} 
	
	return;
}

void Shape::findFirstPixel(void)
{
	for(int j=0; j <this->image.columns(); j++)
	{
		for(int i=0; i<this->image.rows(); i++)
		{
			
			if(isBlackPixel(i,j))
			{
				
				//We have our initial point
				this->pZero[0] = i;
				this->pZero[1] = j;
				
				//cout << "P0 = (" << i << "," << j <<")" << endl;
				
				//Add this initial point to vector
				this->pixel[0] = i;
				this->pixel[1] = j;
				
				this->dir = 5; // initial direction is 7 (8-Connectivity)
				
				//this->addPixelToVector(i,j,7); 
				
				return;
			}
		}
	}
}
