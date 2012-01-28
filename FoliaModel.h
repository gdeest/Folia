#include <QMainWindow>
#include <QString>
#include <QHash>
#include <QList>
#include <QtSql>

class FoliaModel :
	public QObject
{
	Q_OBJECT
public:
	FoliaModel(const QString &dbFile);
	
	bool classify(const QHash<QString, double> &leaf, QString &name);
	
	bool addClass(const QString &name);
	bool addSample(const QHash<QString, double> &leaf, const QString &class_name);
	
	QSqlQuery getClassList();
	QSqlQuery getClasses();
	QSqlQuery getSamples(const QString &class_name=QString());
	QSqlQuery getFeatures(int sample_id);
	QSqlQuery getDistributions(const QString &class_);
	
	void computeDistributions();
	void perfTest();
	
private:
	void addParam(const QString &param);
	void addParams();
	
	int getClassId(const QString &class_);
	int getParamId(const QString &param);
	
	void addFeature(int sample_id, const QString &param, double value);
	struct Distribution
	{
		double average, deviation;
		Distribution() {}
		Distribution(double avg, double dev) : average(avg), deviation(dev) {}
	};
	
	long double evaluateDensity(const QHash<QString, double> &leaf, const QString class_, const QString param);
	long double evaluateDensity(const QHash<QString, double> &leaf, const QString class_);
	
	void reloadDb();
	void computeDistributions(int class_id);
	void loadDistributions();
	
	int paramCount();
	
	QString m_dbFile;
	QSqlDatabase m_db;
	
	QStringList m_classes;
	QStringList m_params;
	QHash<QString, QHash<QString, Distribution> > m_distributions;
};