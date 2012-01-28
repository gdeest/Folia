#include "Couleurs.h"

using namespace Magick;

Couleurs::Couleurs(Magick::Image image)
{
	//Initialisation
	this->image = image;
	this->imageRows = this->image.rows();
	this->imageCols = this->image.columns();
	
	nbCouleurs = 0;
	
	sumY = 0.0;
	sumU = 0.0;
	sumV = 0.0;
}

Couleurs::~Couleurs()
{
}

/*
 * Il manquait cette méthode dans Magick++
 * 
 */
void Couleurs::whiteThreshold(double coeff)
{
	
	this->image.normalize();
	
	for(int row = 0; row < this->imageRows; row++)
	{
		for(int col = 0; col < this->imageCols; col++)
		{
			ColorYUV pixelColor = this->image.pixelColor(col,row);
			
			double couleurY = pixelColor.y();
			
			if(couleurY > coeff)
			{
				try 
				{
					this->image.pixelColor(col,row,ColorMono(true));
				}
				catch (Magick::ErrorOption e) 
				{
					cout << e.what() << endl;
				}
				
			}
		}
	}
	
}

QHash<QString, double> Couleurs::calculate()
{
	whiteThreshold(0.80);
	
	for(int row = 0; row < this->imageRows; row++)
	{
		for(int col = 0; col < this->imageCols; col++)
		{
			ColorYUV pixelColor = this->image.pixelColor(col,row);
			
			if(pixelColor.y() != 1) // Différent de blanc
			{
				addYUV(pixelColor.y(), pixelColor.u(), pixelColor.v());
			}
		}
	}
	
	calculerMoyenne();
	
	QHash<QString, double> hash;
	hash["y"] = paramCouleurs.y();
	hash["u"] = paramCouleurs.u();
	hash["v"] = paramCouleurs.v();
	
	return hash;
}

void Couleurs::calculerMoyenne()
{
	paramCouleurs = ColorYUV(sumY/nbCouleurs, sumU/nbCouleurs, sumV/nbCouleurs);
	
	cout << "La moyenne des couleurs : (Y,U,V) = (" << paramCouleurs.y() << "," << paramCouleurs.u() << "," << paramCouleurs.v() << ")" << endl; 
}

void Couleurs::addYUV(double y, double u, double v)
{

	this->sumY += y;
	this->sumU += u;
	this->sumV += v;
	
	//cout << "Ajout de la couleur (Y,U,V) = (" << y << "," << u << "," << v << ")" << endl;
	//cout << sumY << "," << sumU << "," << sumV << endl;
	
	this->nbCouleurs ++;
}	

