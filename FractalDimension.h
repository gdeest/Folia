#ifndef FRACTALDIMENSION_H_
#define FRACTALDIMENSION_H_

#include <Magick++.h>
#include <vector>
#include <iostream> 

using namespace std;

class FractalDimension
{
public:
	FractalDimension(const Magick::Image&);
	virtual ~FractalDimension();
	double calculate(void);
	
	Magick::Image image;
	
private:
	
	void calculateSlope(void);
	void calculateAverages(void);
	int calculateBoxes(int);
	bool ownOneBlackPixel(int,int,int);
	
	vector<double> xs;
	vector<double> ys;
	
	double avXs;
	double avYs;
	
	double sXY;
	double sXX;
	
	double pente;
	
};

#endif /*FRACTALDIMENSION_H_*/
