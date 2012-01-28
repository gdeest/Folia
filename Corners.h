#ifndef CORNER_H
#define CORNER_H


#include <vector>
#include <Magick++.h>
#include "Step.h"

using namespace std;

class Corners {
public:
	Corners(vector<Step*> pixels);
	
	double numCorners();

private:
	vector<Step *> m_pixels;
};

#endif