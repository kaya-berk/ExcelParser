#ifndef INDEXPAIR_H
#define INDEXPAIR_H

#include <QCoreApplication>
#include <QVariant>
#include <QString> // std::cout << s.toUtf8().constData();
#include <QDebug>
#include <QtGlobal>
#include <QVector>
#include <QPair>
#include <iostream>

class IndexPair
{
public:
	IndexPair();
	QVector<QPair<int,int> > index(QString file);
private:

};

#endif // INDEXPAIR_H
