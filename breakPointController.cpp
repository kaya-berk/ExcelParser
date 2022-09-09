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
#include "xlsxdocument.h"
#include "breakPointController.h"

using namespace std;
using namespace QXlsx;

BreakCont::BreakCont()
{

}

QVector<QString> BreakCont::controller(QVector<QPair<int,int> > vecB, QString file)
{
	QVector<QString> breakPCont;
	Document filename(file);
	static QString strName;
	static QString strAct;

	if (!filename.load()){
		return {};
	}
	bool found = false;
	for(int row = 0; row < vecB.size() ; row++) {
		for(int j = vecB[row].first; j <= vecB[row].second; j++){
			Cell* caseName = filename.cellAt( j, 1); // get name of case pointer.
			QVariant varCase = caseName->readValue();
			Cell* act = filename.cellAt( j, 9); // get step action pointer.
			if(act==NULL)
				break;
			QVariant varAct = act->readValue();// read cell value (number(double), QDateTime, QString ...)
			if(varAct.isNull())
				break;
			strName = varCase.toString();
			strAct = varAct.toString();

			if(strAct.contains("BP", Qt::CaseInsensitive) || strAct.contains("Breakpoint", Qt::CaseInsensitive) ){
				found = false;
			}
			else{
				found = true;
			}
		}
		if(found == true){
			breakPCont.push_back(strName);
			}
	}
	return breakPCont;
}
