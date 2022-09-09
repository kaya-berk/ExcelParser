#ifndef LISTFILEREC_H
#define LISTFILEREC_H

#include "qdir.h"
#include <QCoreApplication>
#include <QVariant>
#include <QString> // std::cout << s.toUtf8().constData();
#include <QDebug>
#include <QtGlobal>
#include <QVector>
#include <QPair>
#include <iostream>

class ListFiles
{
public:
	ListFiles();
	QVector<QString> filevec(QString path);
private:

};

#endif // LISTFILEREC_H
