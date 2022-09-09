#include <QVariant>
#include <QString>
#include <QDebug>
#include <QVector>
#include <iostream>
#include "listFileRec.h"
#include "qdir.h"

using namespace std;

ListFiles::ListFiles()
{

}

QVector<QString> ListFiles::filevec(QString path){

	QDir dir;
	dir.setPath(path);
	dir.setNameFilters(QStringList("*.xlsx"));
	dir.setFilter(QDir::Files | QDir::NoDotAndDotDot | QDir::NoSymLinks);
	QVector<QString> fvec;

	QStringList fileList = dir.entryList();
	for (int i=0; i<fileList.count(); i++)
	{
		QString temp = path+fileList.at(i);
		fvec.push_back(temp);
	}

	return fvec;
}
