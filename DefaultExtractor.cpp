#include <QtDebug>
#include "DefaultExtractor.h"
#include "FractalDimension.h"
#include "Couleurs.h"
#include "FoliaException.h"
#include "Shape.h"
#include "Corners.h"

DefaultExtractor::DefaultExtractor(QObject *parent) :
	FeatureExtractor(parent)
{}

void DefaultExtractor::getFeatures(QHash<QString, double> &features, const QString &frontPath, const QString &backPath)
{
	qDebug() << "getFeatures()";
	Magick::Image front, back, contour;
	
	features.clear();
	
	if (!frontPath.isEmpty())
		front = Magick::Image(frontPath.toStdString());
	
	if (!backPath.isEmpty())
		back = Magick::Image(backPath.toStdString());
	
	// GeometricMoments momF(front);
	// GeometricMoments momD(back);
	
	FractalDimension backD(back);
	// FractalDimension frontD(front);
	FractalDimension frontD(front);
	
	Couleurs colF(front);
	Couleurs colD(back);
	
	// try {
	// 	front.equalize();
	// } catch (Magick::Exception e) {
	// 	
	// }
	// 
	// try {
	// 	back.equalize();
	// } catch (Magick::Exception e) {
	// 
	// }
	
	Shape shapeF(front);
	Shape shapeD(back);
	
	QHash<QString, double> color;
	
	if (!frontPath.isEmpty() && !backPath.isEmpty()) {
		throw new FoliaException("Both front path and back path are given !");
		// features["fractal_dimension"] = (frontD.calculate() + backD.calculate())/2;
		// 
		// color = colF.calculate();
		// 
		// features["avgy_front"] = color.y();
		// features["avgu_front"] = color.u();
		// features["avgv_front"] = color.v();
		// 
		// color = colD.calculate();
		// 
		// features["avgy_back"] = color.y();
		// features["avgu_back"] = color.u();
		// features["avgv_back"] = color.v();
		
	} else if (!frontPath.isEmpty() && backPath.isEmpty()) {
		features["fractal_dimension"] = frontD.calculate();
		
		shapeF.calculate();
		features["perimeter"] = shapeF.getPerimetre();
		features["aire"] = shapeF.getAire();
		
		Corners cornersF(shapeF.pixels);
		double i = cornersF.numCorners();
		features["num_corners"] = i;
		
		color = colF.calculate();
		features["avgy_front"] = 10000*color["y"];
		features["avgu_front"] = 10000*color["u"];
		features["avgv_front"] = 10000*color["v"];
		
		// features["geometric_11"] = momF.moment(1, 1);
		// features["geometric_12"] = momF.moment(1, 2);
		// features["geometric_21"] = momF.moment(2, 1);
		// features["geometric_22"] = momF.moment(2, 2);
		// features["geometric_13"] = momF.moment(1, 3);
		// features["geometric_31"] = momF.moment(3, 1);
		// features["geometric_23"] = momF.moment(2, 3);
		// features["geometric_32"] = momF.moment(3, 2);
		// features["geometric_33"] = momF.moment(3, 3);
		
	} else if (frontPath.isEmpty() && !backPath.isEmpty()) {
		features["fractal_dimension"] = backD.calculate();
		
		shapeD.calculate();
		features["perimeter"] = shapeD.getPerimetre();
		features["aire"] = shapeD.getAire();
		
		Corners cornersD(shapeD.pixels);
		double i = cornersD.numCorners();
		features["num_corners"] = i;
		
		color = colD.calculate();
		features["avgy_back"] = 10000*color["y"];
		features["avgu_back"] = 10000*color["u"];
		features["avgv_back"] = 10000*color["v"];
		
		// features["legendre_11"] = legD.legendre(1, 1);
		// features["legendre_12"] = legD.legendre(1, 2);
		// features["legendre_21"] = legD.legendre(2, 1);
		// features["legendre_22"] = legD.legendre(2, 2);
		// features["legendre_13"] = legF.legendre(1, 3);
		// features["legendre_31"] = legF.legendre(3, 1);
		// features["legendre_23"] = legF.legendre(2, 3);
		// features["legendre_32"] = legF.legendre(3, 2);
		// features["legendre_33"] = legF.legendre(3, 3);
		
	} else {
		throw new FoliaException("Error: Both path are empty !");
	}
}

QStringList DefaultExtractor::getFeatureList()
{
	QStringList list;
	list << "fractal_dimension";
	list << "num_corners";
	list << "avgy_front";
	list << "avgu_front";
	list << "avgv_front";
	list << "avgy_back";
	list << "avgu_back";
	list << "avgv_back";
	list << "perimeter";
	// list << "geometric_11";
	// list << "geometric_12";
	// list << "geometric_21";
	// list << "geometric_22";
	// list << "geometric_13";
	// list << "geometric_31";
	// list << "geometric_23";
	// list << "geometric_32";
	// list << "geometric_33";
	// list << "legendre_11";
	// list << "legendre_12";
	// list << "legendre_21";
	// list << "legendre_22";
	// list << "legendre_13";
	// list << "legendre_31";
	// list << "legendre_32";
	// list << "legendre_23";
	// list << "legendre_33";
	list << "aire";
	return list;
}
