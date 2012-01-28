#include <QMainWindow>
#include <QtSql>
#include "FoliaModel.h"

#include "ui_folia.h"

class FoliaMainWindow :
	public QMainWindow,
	private Ui::FoliaMain
{
	Q_OBJECT
	
public:
	FoliaMainWindow(const QString &dbFile, QWidget *parent=0);
	
	~FoliaMainWindow();
private:
	FoliaModel *m_model;
	QSqlQueryModel *classes_model;
	QSqlQueryModel *samples_model;
	QSqlQueryModel *params_model;
	QSqlQueryModel *distributions_model;
	// void fillClassListBox();
	
private slots:

	void on_newClassButton_clicked();
	void on_addSample_clicked();
	void on_classListBox_currentIndexChanged(int index);
	void on_samplesList_clicked(const QModelIndex &index);
	void on_selFileToClassify_clicked();
	void on_classifyButton_clicked();
};