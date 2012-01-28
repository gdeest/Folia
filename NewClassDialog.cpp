#include "NewClassDialog.h"

NewClassDialog::NewClassDialog(QWidget *parent) :
	QDialog(parent)
{
	setupUi(this);
	connect(this, SIGNAL(accepted()), SLOT(onAccepted()));
}

QString NewClassDialog::name()
{
	return m_name;
}

void NewClassDialog::onAccepted()
{
	m_name = className->text();
}
