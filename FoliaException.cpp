#include "FoliaException.h"

FoliaException::FoliaException(QString msg) :
	m_msg(msg)
{
}

QString FoliaException::message()
{
	return m_msg;
}