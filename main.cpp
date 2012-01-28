#include <QApplication>
#include <QString>
#include <QtDebug>
#include "FoliaException.h"
#include "FoliaMainWindow.h"

#define DB_FILE "leaves.db"

int main (int argc, char *argv[])
{
	QApplication app(argc, argv);
	
	QString dbFile = argc > 1 ? argv[1] : DB_FILE;
	try {	
		FoliaMainWindow win(dbFile);
	
		win.show();
		return app.exec();
		
	} catch (FoliaException *e) {
		qDebug() << e->message();
		return -1;
	}
}