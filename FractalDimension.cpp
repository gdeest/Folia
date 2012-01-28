#include "FractalDimension.h"
#include <math.h>

using namespace Magick;

FractalDimension::FractalDimension(const Magick::Image &image)
{
	this->image = image;
}

FractalDimension::~FractalDimension()
{
}


void FractalDimension::calculateAverages(void)
{
	this->avXs = 0.0;
	this->avYs = 0.0;
	
	for(int i=0; i < xs.size(); i++ )
	{
			this->avXs += this->xs[i];
			this->avYs += this->ys[i];
	}
	
	this->avXs = this->avXs / this->xs.size();
	this->avYs = this->avYs / this->ys.size();
	
	cout << "Averages is now " << this->avXs << " for the X and " << this->avYs << " for the Y." << endl;
}

bool FractalDimension::ownOneBlackPixel(int row, int col, int boxWidth)
{	
	for(int k=row; k<(row+boxWidth); k++)
	{
		for(int h=col; h<(col+boxWidth); h++)
		{
			//cout << k << "," << h << endl;
			if(k < this->image.rows() && h < this->image.columns())
			{
				ColorMono color = this->image.pixelColor(h,k);
							
				//cout << "Pixel at " << k << ", " << h << " is white : " << color.mono() << endl;
							
				if(!color.mono()) //pixel is black == false
				{
					return true;
				}
			}
			
		}
	}
	
	return false;
}

int FractalDimension::calculateBoxes(int boxWidth)
{
	int count = 0;
	int imageColumns = this->image.columns();
	int imageRows = this->image.rows();
	
	//cout << "Image columns=" << imageColumns << ", image rows=" << imageRows << endl;
	
	for(int row=0; row < imageRows; row=row+boxWidth)
	{	
		for(int col=0; col < imageColumns; col=col+boxWidth)
		{
			//cout << "the box at :" << row << "," << col << "got blacks pixels?" << endl;
			
			if(ownOneBlackPixel(row,col,boxWidth))
			{
				count++;
			}
		}
	}
	
	return count;
}

double FractalDimension::calculate(void)
{
	cout << "Calculate" << endl;
	
	this->xs.resize(1);
	this->ys.resize(1);
	
//	this->image.display();
	this->image.threshold(0.7*65535);
//	this->image.display();
	
	this->xs.at(0) = 0;
	this->ys.at(0) = 0;
	
	for(int j=0; j<5; j++)
	{
		
		int i = pow(2,j);
		
		if(j == this->xs.size())
		{
			this->xs.resize(this->xs.size() + 1);
			this->ys.resize(this->ys.size() + 1);
		}
		
		int nbBoxes = this->calculateBoxes(i);
		cout << "Box width : " << i << ", number of boxes : " << nbBoxes << endl;
		
		this->xs.at(j) =  log((1.0*i)/this->image.columns());
		this->ys.at(j) =  log(nbBoxes);
	}
	
	this->calculateAverages();
	this->calculateSlope();
	return -(this->pente);
}

void FractalDimension::calculateSlope(void)
{
	this->sXX = 0.0;
	this->sXY = 0.0;
	
	for(int i=1; i < xs.size()+1; i++ )
	{
			this->sXY += (this->xs[i]-this->avXs)*(this->ys[i]-this->avYs);
			this->sXX += (this->xs[i]-this->avXs)*(this->xs[i]-this->avXs);
	}

	this->pente = sXY/sXX;
	
	cout << "Pente: " << this->pente << endl;
}
