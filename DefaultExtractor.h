#ifndef DEFAULT_EXTRACTOR_H
#define DEFAULT_EXTRACTOR_H

#include "FeatureExtractor.h"

class DefaultExtractor :
	public FeatureExtractor
{
public:
	DefaultExtractor(QObject *parent);
	
	virtual void getFeatures(QHash<QString, double> &features, const QString &frontPath, const QString &backPath);
	
	virtual QStringList getFeatureList();
};

#endif
