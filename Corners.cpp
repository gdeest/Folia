#include "Magick++.h"
#include <QtDebug>
#include "Corners.h"
#include "math.h"

Corners::Corners(vector<Step*>pixels) {
	m_pixels = pixels;
//	image =  Magick::Imageimages/philadelphus/philadelphus-f0$i.jpg
}

int mod(int i, int pixsize) {
	if (i >= 0)
		return i%pixsize;
	else
		return pixsize - (-i % pixsize);
}

double Corners::numCorners() {
	double count = 0;
	
	long double *dx = new long double[m_pixels.size()];
	long double *dy = new long double[m_pixels.size()];
	
	int pixsize = m_pixels.size() -1;
	
	for (int i =0; i< pixsize; i++) {		
		dx[i] = -1.0*m_pixels[mod((i-4),pixsize)]->pos[0] + 1.0*m_pixels[mod((i+4),pixsize)]->pos[0];
		dy[i] = -1.0*m_pixels[mod((i-4),pixsize)]->pos[1] + 1.0*m_pixels[mod((i+4),pixsize)]->pos[1];
	}
	
	for (int i =0; i< m_pixels.size()-1; i++) {
		long double dxx=0, dyy=0, courbure=0;
		dxx = -dx[mod((i-4),pixsize)] + dx[mod((i+4),pixsize)];
		dyy = -dy[mod((i-4),pixsize)] + dy[mod((i+4),pixsize)];
		courbure = (dx[i]*dyy + dy[i]*dxx)/powl(dx[i]*dx[i] + dy[i]*dy[i], 1.5);
		
		if (courbure > 2)
			count += 1;
	}
	
	qDebug() << "Num Corners: " << count;
	
	return count;
}