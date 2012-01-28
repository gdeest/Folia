#include <QDialog>

#include "ui_newclass.h"

class NewClassDialog :
	public QDialog,
	private Ui::NewClass
{
	Q_OBJECT
public:
	NewClassDialog(QWidget *parent=0);
	QString name();
private:
	QString m_name;

private slots:
	void onAccepted();
};
