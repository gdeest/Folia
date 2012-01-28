#ifndef FEATURE_EXTRACTOR_H
#define FEATURE_EXTRACTOR_H

#include <QStringList>
#include <QObject>
#include <QHash>

class FeatureExtractor :
	public QObject
{
public:
	FeatureExtractor(QObject *parent=0);
	
	virtual void getFeatures(QHash<QString, double> &features, const QString &frontPath, const QString &backPath)=0;
	
	virtual QStringList getFeatureList()=0;
};

#endif