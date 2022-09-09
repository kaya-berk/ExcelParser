#ifndef BREAKPOINTCONTROLLER_H
#define BREAKPOINTCONTROLLER_H

#include <QCoreApplication>
#include <QVariant>
#include <QString> // std::cout << s.toUtf8().constData();
#include <QDebug>
#include <QtGlobal>
#include <QVector>
#include <QPair>
#include <iostream>

class BreakCont
{
public:
	BreakCont();
	QVector<QString> controller(QVector<QPair<int,int> >vecB, QString file);
private:

};

#endif // BREAKPOINTCONTROLLER_H
