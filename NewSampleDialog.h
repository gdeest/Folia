#ifndef NEW_SAMPLE_DIALOG_H
#define NEW_SAMPLE_DIALOG_H

#include <QDialog>

#include "ui_newsample.h"

class NewSampleDialog :
	public QDialog,
	private Ui::NewSample
{
	Q_OBJECT
public:
	NewSampleDialog(QWidget *parent=0);
	
	QStringList getFront();
	QStringList getBack();
	
	QStringList m_front;
	QStringList m_back;
	
private slots:
	void accept();
	
	void on_selFront_clicked();
	void on_selBack_clicked();
};

#endif