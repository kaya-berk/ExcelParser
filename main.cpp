#include <QCoreApplication>
#include <QVariant>
#include <QString> // std::cout << s.toUtf8().constData();
#include <QDebug>
#include <QtGlobal>
#include <QVector>
#include <QPair>
#include <string.h>
#include <thread>
#include <chrono>
#include <iostream>
#include "breakPointController.h"
#include "indexPair.h"
#include "listFileRec.h"

using namespace std;

int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv);
	ListFiles lf;
	BreakCont bc;
	IndexPair ip;
	QVector<QString> files = lf.filevec("/home/mak/Desktop/");
	for(int a=0; a<files.size();a++)
	{
		QVector<QPair<int, int> > vec = ip.index(files.at(a));

		QVector<QString> bpMain = bc.controller(vec, files.at(a));

		for(int i = 0; i < bpMain.count(); i++){
			qDebug() << bpMain.at(i);
		}
	}

	return 0;
}
