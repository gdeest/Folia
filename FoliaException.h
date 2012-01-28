#include <QString>

class FoliaException
{
public:
	FoliaException (QString msg=QString());
	
	QString message();
	
private:
	QString m_msg;	
};