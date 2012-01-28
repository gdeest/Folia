#include <QtDebug>
#include <QPicture>
#include <QFileDialog>

#include "FoliaMainWindow.h"
#include "NewClassDialog.h"
#include "NewSampleDialog.h"
#include "FoliaException.h"
#include "DefaultExtractor.h"

FoliaMainWindow::FoliaMainWindow(const QString &dbFile, QWidget *parent) :
	QMainWindow(parent)
{
	setupUi(this);
	m_model = new FoliaModel(dbFile);
	classes_model = new QSqlQueryModel(this);
	samples_model = new QSqlQueryModel(this);
	params_model = new QSqlQueryModel(this);
	distributions_model = new QSqlQueryModel(this);
	classes_model->setQuery(m_model->getClassList());
	classListBox->setModel(classes_model);
	m_model->computeDistributions();
	m_model->perfTest();
}

void FoliaMainWindow::on_newClassButton_clicked()
{
	NewClassDialog dialog(this);
	
	if (dialog.exec() == QDialog::Accepted && m_model->addClass(dialog.name()))
	{
		classes_model->setQuery(m_model->getClassList());
		classListBox->setModel(classes_model);
		classListBox->setCurrentIndex(classListBox->findText(dialog.name()));
	}	

}

void FoliaMainWindow::on_addSample_clicked()
{
	NewSampleDialog dialog(this);
	if (dialog.exec() == QDialog::Accepted) {
		QStringList frontSamples = dialog.getFront();
		QStringList backSamples = dialog.getBack();

		qDebug() << "Adding front samples: ";
		
		DefaultExtractor extractor(this);
		
		foreach(QString sampleImage, frontSamples) {
			qDebug() << sampleImage;
			QHash<QString, double> sample;
			extractor.getFeatures(sample, sampleImage, QString());
			m_model->addSample(sample, classListBox->itemText(classListBox->currentIndex()));
		}
		
		qDebug() << "Adding back samples: ";
		
		foreach(QString sampleImage, backSamples) {
			qDebug() << sampleImage;
			QHash<QString, double> sample;
			extractor.getFeatures(sample, QString(), sampleImage);
			m_model->addSample(sample, classListBox->itemText(classListBox->currentIndex()));
		}
		
		m_model->computeDistributions();
		
		on_classListBox_currentIndexChanged(classListBox->currentIndex());
	}
}

void FoliaMainWindow::on_classListBox_currentIndexChanged(int index)
{
	QString class_name = classListBox->itemText(index);
	
	params_model->setQuery(QSqlQuery());
	samplesList->setModel(0);
	samples_model->setQuery(m_model->getSamples(class_name));
	samplesList->setModel(samples_model);
	
	distTable->setModel(0);
	distributions_model->setQuery(m_model->getDistributions(class_name));
	distTable->setModel(distributions_model);
}

void FoliaMainWindow::on_samplesList_clicked(const QModelIndex &index)
{
	QMap<int, QVariant> data = samples_model->itemData(index);
	
	paramsTable->setModel(0);
	params_model->setQuery(m_model->getFeatures(data[0].toInt()));
	paramsTable->setModel(params_model);
}

void FoliaMainWindow::on_selFileToClassify_clicked()
{
	QString file = QFileDialog::getOpenFileName(this, trUtf8("Sélectionnez le fichier à classifier"));
	if (file != QString()) {
		fileLabel->setText(file);
	}
}

void FoliaMainWindow::on_classifyButton_clicked()
{
	if (fileLabel->text() != QString()) {
		idLabel->setText(QString());
		
		QString className;
		
		DefaultExtractor extractor(this);
		
		QHash<QString, double> features;
		if (radioFront->isChecked())
			extractor.getFeatures(features, fileLabel->text(), QString());
		else
			extractor.getFeatures(features, QString(), fileLabel->text());
		
		if (m_model->classify(features, className)) {
			idLabel->setText(trUtf8("Feuille identifiée: %1").arg(className));
		} else {
			idLabel->setText(trUtf8("Feuille non identifiée. Plus probable: %1").arg(className));
		}
	}
}

FoliaMainWindow::~FoliaMainWindow()
{
	delete m_model;
}
