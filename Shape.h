/*
 * Shape
 * 
 * Cette classe sert à calculer tous les paramètres concernant 
 * la forme de la feuille. C'est donc ici que nous allons retrouver
 * le périmètre, l'aire.
 * 
 */


#ifndef SHAPE_H_
#define SHAPE_H_

#include <Magick++.h>
#include <QHash>
#include <vector> 
#include <iostream> 
#include "Step.h"

using namespace std;

class Shape
{
public:
	
	Shape(const Magick::Image);
	virtual ~Shape();
	
	void calculate(void);
	double getPerimetre(void);
	double getAire();
	
	//Attributes
	Magick::Image image;
	Magick::Image contour;
	
	vector<Step*> pixels;
	
	
	
private:
	
	//Méthodes
	void findFirstPixel(void);
	void findNextPixels(int, int, int);
	int calculateNextPosition(int);
	bool isBlackPixel(int, int);
	bool isAtBegining(int, int);
	void addPixelToVector(int,int,int);
	void iterationStep(int, int);
	
	bool lastI(void);
	bool lastJ(void);
	
	void calculatePerimeter(void);
	void calculateAire(void);
	
	//Données de direction et point
	int pZero[2];
	int pOne[2];
	int lastPixel[2];
	int pixel[2];
	int dir;
	
	int index;
	
	//Image
	int rows;
	int columns;
	
	//Perimetre
	int lenght;
	
	//Aire 
	int aire;
};

#endif /*SHAPE_H_*/
