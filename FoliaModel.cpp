#include <QtDebug>
#include <QStringList>
#include <math.h>

#include "FoliaModel.h"
#include "FoliaException.h"
#include "DefaultExtractor.h"

#include "DefaultExtractor.h"

#define SQRT2PI 2.5066

FoliaModel::FoliaModel(const QString &dbFile) :
	m_dbFile(dbFile)
{
	reloadDb();
	
}

bool FoliaModel::addClass(const QString &name)
{
	qDebug() << name;
	QSqlQuery query("INSERT INTO classes (name) VALUES (:name)");
	query.bindValue(":name", name);
	
	return query.exec();
}

void FoliaModel::perfTest()
{
	double nbSucces=0, total=0;
	
	QSqlQuery samples("SELECT samples.id, classes.name FROM samples, classes WHERE samples.class_id = classes.id");
	if (!samples.exec())
		throw new FoliaException("Error querying samples.");
	
	if (samples.first()) {
		do {
			QString name;
			int sampleId = samples.record().value("id").toInt();
			
			name = samples.record().value("name").toString();
			qDebug() << "Class name: " << name << " Sample Id: " << sampleId;
			
			QHash<QString, double> sample;
		
			QSqlQuery features("SELECT params.name, features.value from params, features, samples WHERE features.sample_id = :sample_id AND params.id = features.param_id");
			features.bindValue(":sample_id", sampleId);
			if (!features.exec())
				throw new FoliaException("Error querying features");
		
			if (features.first()) do {
				QString paramName = features.record().value("name").toString();
				qDebug () << "Feature: " << paramName;
				sample[paramName] = features.record().value("value").toDouble();
			} while (features.next());
		
			QString className;
		
			classify(sample, className);
		
			total += 1;
		
			if (className == name)
				nbSucces += 1;
		} while (samples.next());
		
		qDebug() << "Nombre d'échantillons: " << total;
		qDebug() << "Pourcentage de réussite: " << 100*(nbSucces/total);
	}
	
}

void FoliaModel::addFeature(int sample_id, const QString &param, double value)
{	
	qDebug() << "addFeature begin";
	QSqlQuery paramId("SELECT id FROM params WHERE name=:name");
	paramId.bindValue(":name", param);
	
	if (!paramId.exec() || !paramId.first())
		throw new FoliaException(QString("Error retrieving id for param: %1").arg(param));
	
	QSqlQuery insert("INSERT INTO features (param_id, sample_id, value) VALUES (:param_id, :sample_id, :value)");
	insert.bindValue(":param_id", paramId.record().value("id").toInt());
	insert.bindValue(":sample_id", sample_id);
	insert.bindValue(":value", value);
	if (!insert.exec())
		throw new FoliaException(QString("Error adding feature: %1 to sample: %2 with value: %3").
		arg(param).arg(sample_id).arg(value));
	qDebug() << "addFeature end";
}

bool FoliaModel::addSample(const QHash<QString, double> &leaf, const QString &class_name)
{
	// Retrieve class id
	QSqlQuery classId("SELECT id FROM classes WHERE name = :class_name");
	classId.bindValue(":class_name", class_name);
	
	if (!classId.exec() || !classId.first())
		throw new FoliaException(QString("Error trying to get id for class: %1").arg(class_name));
	
	qDebug() << "Adding to sample to class: " << class_name << " Id: " << classId.record().value("id").toInt();
	
	// Creating sample
	QSqlQuery newSample("INSERT INTO samples (class_id) VALUES (:class_id)");
	newSample.bindValue(":class_id", classId.record().value("id").toInt());
	
	if (!newSample.exec())
		throw new FoliaException(QString("Error adding sample to class: %1").arg(class_name));
	
	// Adding features
	int sample_id = newSample.lastInsertId().toInt();
	
	qDebug() << sample_id;
	
	QHash<QString, double>::const_iterator it = leaf.constBegin();
	while (it != leaf.constEnd())
	{
		qDebug() << "Adding feature: " << it.key() << " with value: " << it.value();
		addFeature(sample_id, it.key(), it.value());
		++it;
	}
	
//	computeDistributions(classId.record().value("id").toInt());
}

QSqlQuery FoliaModel::getClassList()
{
	QSqlQuery query = QSqlQuery("SELECT name FROM CLASSES ORDER BY name");
	if (!query.exec())
		throw new FoliaException("Error querying classes from database");
	return query;
}

QSqlQuery FoliaModel::getClasses()
{
	QSqlQuery query = QSqlQuery("SELECT * FROM classes ORDER BY name");
	if (!query.exec())
		throw new FoliaException("Error querying classes from database");
	return query;
}

QSqlQuery FoliaModel::getSamples(const QString &class_name)
{
	QSqlQuery query;
	
	if (class_name.isEmpty()) {
		query = QSqlQuery("SELECT * FROM samples");
		if (!query.exec())
			throw new FoliaException("Error querying samples from database");
		
		return query;
	}
	
	query = QSqlQuery("SELECT * FROM samples, classes WHERE samples.class_id = classes.id AND classes.name = :class_name");
	query.bindValue(":class_name", class_name);
	
	if (!query.exec())
		throw new FoliaException("Error querying samples from database");
	
	return query;
}

QSqlQuery FoliaModel::getFeatures(int sample_id)
{
	QSqlQuery query("SELECT params.name as Nom, features.value as Valeur FROM samples, params, features "
	"WHERE samples.id = :sampleid AND features.sample_id = samples.id AND params.id = features.param_id");
	
	query.bindValue(":sampleid", sample_id);

	if (!query.exec()) {
		qDebug() << QString("Error querying features from database: %1").arg(query.lastError().text());
		throw new FoliaException(QString("Error querying features from database: %1").arg(query.lastError().text()));
	}
	
	return query;
}

int FoliaModel::paramCount() {
	QSqlQuery params("SELECT id FROM params");
	if (!params.exec())
		throw new FoliaException("Error querying params from server");
	
	return params.size();
}

long double FoliaModel::evaluateDensity(const QHash<QString, double> &leaf, const QString class_, const QString param) {
	Distribution dist = m_distributions[class_][param];
	long double avg = dist.average, dev = dist.deviation;
	long double x = leaf[param];
	
	long double y = exp(-(x-avg)*(x-avg)/(2*dev*dev))/(dev*SQRT2PI);
	
	double y_ = y;
	
	QString class__ = class_;
	
	
	qDebug() << "Density for class: " << class__ << " and param: " << param << " ; " << y_;
	
	return y;
}

long double FoliaModel::evaluateDensity(const QHash<QString, double> &leaf, const QString class_) {
	long double density = 1;
	
	double density_ = density;
	QHash<QString, double>::const_iterator it = leaf.constBegin();
	QHash<QString, double>::const_iterator end = leaf.constEnd();
	
	while (it != end) {
		density_ = density;
		density = density * evaluateDensity(leaf, class_, it.key());
		++it;
	}
	
	
	qDebug() << "Density for class "<< class_ <<": " << density_;
	return density;
}

bool FoliaModel::classify(const QHash<QString, double> &leaf, QString &name) {
	QString maxClass, secClass;
	double maxDens=-1, secDens;
	
	long double sum=0;
	
	qDebug() << "Classify";
	
	foreach (QString class_, m_classes) {
		qDebug() << "Hello, " << class_;
		long double dens = evaluateDensity(leaf, class_);
		sum += dens;
		if (dens > maxDens) {
			secClass = maxClass;
			secDens = maxDens;
			maxClass = class_;
			maxDens = dens;
		} else if (dens > secDens) {
			secClass = class_;
			secDens = dens;
		}
	}
	
	name = maxClass;

	double confiance = maxDens/sum;
	qDebug() << "Indice de confiance: " << confiance;
	
	if (maxDens/sum > 0.9 && (maxDens > 0.2e-18)) 
		return true;
		
	return false;
}

void FoliaModel::reloadDb()
{
	m_db.close();
	m_classes.clear();
	m_params.clear();
	m_distributions.clear();
	
	m_db = QSqlDatabase::addDatabase("QSQLITE");
	m_db.setDatabaseName(m_dbFile);
	
	if (!m_db.open())
		throw new FoliaException("Error opening database");
	else
		qDebug() << "Database opened successfully.";
	
	if (m_db.tables().size() == 0) // No tables -> New db
	{
		qDebug() << "New database. Creating tables.";
		
		QSqlError err;
		
		err = m_db.exec("CREATE TABLE classes ("
			"id INTEGER PRIMARY KEY AUTOINCREMENT,"
			"name TEXT UNIQUE)").lastError();
		if (err.type() != QSqlError::NoError)
			qDebug() << err.text();
		
		err = m_db.exec("CREATE TABLE params ("
			"id INTEGER PRIMARY KEY AUTOINCREMENT,"
			"name TEXT UNIQUE)").lastError();
		if (err.type() != QSqlError::NoError)
			qDebug() << err.text();
		
		err = m_db.exec("CREATE TABLE distributions ("
			"id INTEGER PRIMARY KEY AUTOINCREMENT,"
			"class_id INTEGER,"
			"param_id INTEGER,"
			"average REAL,"
			"deviation REAL)").lastError();
		if (err.type() != QSqlError::NoError)
			qDebug() << err.text();
		
		err = m_db.exec("CREATE TABLE samples ("
		"id INTEGER PRIMARY KEY AUTOINCREMENT,"
		"class_id INTEGER"
		")").lastError();
		if (err.type() != QSqlError::NoError)
			qDebug() << err.text();
			
		err = m_db.exec("CREATE TABLE features ("
			"id INTEGER PRIMARY KEY AUTOINCREMENT,"
			"sample_id INTEGER,"
			"value REAL,"
			"param_id INTEGER)").lastError();
		if (err.type() != QSqlError::NoError)
			qDebug() << err.text();
	}
	else
	{
		qDebug() << "Reusing existing database.";
		loadDistributions();
	}
	
	addParams();
	computeDistributions();
}

void FoliaModel::loadDistributions()
{
	qDebug() << "Loading distributions";
	m_classes = QStringList();
	m_params.clear();
	m_distributions.clear();
	
	QSqlQuery classes("SELECT * FROM classes");
	QSqlQuery params("SELECT * FROM params");
	
	if (!classes.exec() || !params.exec())
		throw new FoliaException("Error querying database.");
	
	if (params.first()) do {
		m_params << params.record().value("name").toString();
	} while (params.next());
	
	if (classes.first()) do {
		QSqlRecord class_ = classes.record();
		QString className = class_.value("name").toString();
		qDebug() << "Adding class: " << className;
		m_classes << className;
		qDebug() << "Loading distributions for class: " << className;
		
		m_distributions[className] = QHash<QString, Distribution>();
		QHash<QString, Distribution> &dists = m_distributions[className];
		
		if (params.first()) do {
			QSqlRecord param = params.record();
			QString paramName = param.value("name").toString();
			qDebug() << "\tParam: " << paramName;
			
			QSqlQuery find("SELECT * FROM distributions WHERE class_id = :cid AND param_id = :pid LIMIT 1");
			find.bindValue(":cid", class_.value("id").toInt());
			find.bindValue(":pid", param.value("id").toInt());
			if (!find.exec())
				throw new FoliaException("Query error !");
			if (!find.first()) {
//				throw new FoliaException(QString("No distribution found for class_id=%1 and param_id=%2!").arg(class_.value("id").toInt()).arg(param.value("id").toInt()));
				qDebug() << QString("No distribution found for class_id=%1 and param_id=%2!").arg(class_.value("id").toInt()).arg(param.value("id").toInt());
			}
			
			double avg = find.record().value("average").toDouble();
			double dev = find.record().value("deviation").toDouble();
			
			qDebug() <<"\tAverage " << avg << " ; Deviation " << dev;
			dists[paramName] = Distribution(avg, dev);
		} while (params.next());
	} while (classes.next());
}

void FoliaModel::addParam(const QString &param)
{
	QSqlQuery query("INSERT INTO params (name) VALUES (:param)");
	query.bindValue(":param", param);
	if (!query.exec())
		throw new FoliaException(QString("Error adding param: %1").arg(param));
}

void FoliaModel::addParams()
{
	qDebug() << "Adding params";
	DefaultExtractor extractor(this);
	QStringList features = extractor.getFeatureList();
	
	foreach (QString param, features) {
		qDebug() << "Adding param: " << param;
		if (!m_params.contains(param))
			addParam(param);
	}
}

int FoliaModel::getClassId(const QString &class_)
{
	QSqlQuery query("SELECT id FROM classes WHERE name=:name");
	query.bindValue(":name", class_);
	if (!query.exec() || !query.first())
		throw new FoliaException("Error querying class id");
	return query.record().value("id").toInt();
}

int FoliaModel::getParamId(const QString &param)
{
	QSqlQuery query("SELECT id FROM params WHERE name=:name");
	query.bindValue(":name", param);
	if (!query.exec() || !query.first())
		throw new FoliaException("Error querying class id");
	return query.record().value("id").toInt();
}

void FoliaModel::computeDistributions(int class_id)
{
	qDebug() << "Computing distributions for class_id: " << class_id;
	QSqlQuery paramsId("SELECT DISTINCT params.id FROM samples, features, params "
		"WHERE samples.class_id = :class_id AND features.sample_id = samples.id AND features.param_id = params.id");
	paramsId.bindValue(":class_id", class_id);
	
	if (!paramsId.exec())
		throw new FoliaException("Error querying params IDs");
	
	QSqlQuery deleteQuery("DELETE from distributions WHERE class_id = :class_id");
	deleteQuery.bindValue(":class_id", class_id);
	deleteQuery.exec();

	if (paramsId.first()) do {
		
	// foreach(QString param, m_params) {
		int param_id = paramsId.record().value("id").toInt();
	// 	
		QSqlQuery query("select value from samples, features, params, classes where classes.id = :class_id AND params.id = :param_id "
		"AND samples.class_id = classes.id AND features.param_id = params.id AND features.sample_id = samples.id");
		
		query.bindValue(":class_id", class_id);
		query.bindValue(":param_id", param_id);
		
		if (!query.exec())
			throw new FoliaException(QString("Error querying features: %1").arg(query.lastError().text()));
		
		long double avgX=0, avgXX=0, avg, sigma;
		int count=0;
		
		if (query.first()) {
			do {
				count++;
				long double val = query.record().value("value").toDouble();
				double arf_ = val;
				
				qDebug() << "param_id: " << param_id << " val: " << arf_;
				avgX += val;
				avgXX += val*val;
			} while (query.next());
			avg = avgX/count;
			
			sigma = sqrt(avgXX/count - avg*avg);
			double sigma_ = sigma;
			
			QSqlQuery addDist("INSERT INTO distributions (class_id, param_id, average, deviation) "
				"VALUES(:class_id, :param_id, :average, :deviation)");
			addDist.bindValue(":class_id", class_id);
			addDist.bindValue(":param_id", param_id);
			double avg_ = avg; sigma_ = sigma;
			addDist.bindValue(":average", avg_);
			addDist.bindValue(":deviation", sigma_);
			if (!addDist.exec())
				throw new FoliaException("Error adding distribution.");
		}
	} while(paramsId.next());
	
	loadDistributions();
}

QSqlQuery FoliaModel::getDistributions(const QString &class_)
{
	QSqlQuery distributions("SELECT params.name, distributions.average, distributions.deviation FROM params, distributions, classes "
	"WHERE classes.name = :class_name AND distributions.class_id = classes.id AND distributions.param_id = params.id");
distributions.bindValue(":class_name", class_);
	
	if (!distributions.exec())
		throw new FoliaException("Error querying distributions.");
	
	return distributions;
}
void FoliaModel::computeDistributions()
{
	foreach(QString class_, m_classes) {
		computeDistributions(getClassId(class_));
	}
}