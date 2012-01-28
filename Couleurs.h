#ifndef COULEURS_H_
#define COULEURS_H_

#include <Magick++.h>
#include <vector>
#include <iostream> 

#include <QHash>

using namespace std;

/*
 * Cette classe fait la moyenne de la couleur.
 * Elle utilise le mode YUV et fait la moyenne de chacun.
 * 
 */
class Couleurs
{
public:
	
	Couleurs(Magick::Image);
	virtual ~Couleurs();
	
	QHash<QString, double> calculate();
	void whiteThreshold(double);
	
private:


	void addYUV(double,double,double);
	void calculerMoyenne(void);


	Magick::Image image;
	
	int imageRows,imageCols;
	
	int nbCouleurs;
	
	double sumY;
	double sumU;
	double sumV;
	
	Magick::ColorYUV paramCouleurs;
	


};

#endif /*COULEURS_H_*/
