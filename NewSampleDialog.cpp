#include <QtDebug>
#include <QFileDialog>

#include "NewSampleDialog.h"

NewSampleDialog::NewSampleDialog(QWidget *parent) :
	QDialog(parent),
	m_front(QStringList()),
	m_back(QStringList())
{
	setupUi(this);
}	

void NewSampleDialog::accept()
{
	done(QDialog::Accepted);
}

QStringList NewSampleDialog::getFront()
{
	return m_front;
}

QStringList NewSampleDialog::getBack()
{
	return m_back;
}

void NewSampleDialog::on_selFront_clicked()
{
	QFileDialog dialog(this, trUtf8("Ajouter des échantillons de face"));
	dialog.setFileMode(QFileDialog::ExistingFiles);
	
	if (dialog.exec() == QDialog::Accepted) {
		frontList->clear();
		frontList->addItems(dialog.selectedFiles());
		m_front = dialog.selectedFiles();
	}
}

void NewSampleDialog::on_selBack_clicked()
{
	QFileDialog dialog(this, trUtf8("Ajouter des échantillons de dos"));
	dialog.setFileMode(QFileDialog::ExistingFiles);
	
	if (dialog.exec() == QDialog::Accepted) {
		backList->clear();
		backList->addItems(dialog.selectedFiles());
		m_back = dialog.selectedFiles();
	}
}
