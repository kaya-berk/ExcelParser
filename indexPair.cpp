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
#include "indexPair.h"

using namespace std;
using namespace QXlsx;

IndexPair::IndexPair()
{

}

QVector <QPair<int, int> > IndexPair::index(QString file)
{
	Document filename(file);
	QVector<QPair<int, int> > vec;
	if (filename.load()) // load excel file
	{

		int row;
		int indexStart = 0;
		int indexEnd = 0;
		int rowTemp = 4;
		for( row = 4; row < filename.dimension().lastRow() ; row++ ){
			int v = 0;
			Cell* cell1 = filename.cellAt(rowTemp, 1); // get cell1 pointer.
			Cell* cell2 = filename.cellAt((row+1),1); // get cell2 pointer.
			if(cell2==NULL)
				break;
			QVariant var1 = cell1->readValue();// read cell1 value (number(double), QDateTime, QString ...)
			QVariant var2 = cell2->readValue();// read cell2 value (number(double), QDateTime, QString ...)
			if(var1.isNull())
				break;
			QString str1 = var1.toString();
			QString str2 = var2.toString();

			if(str1==str2)
			{
				continue;
			}
			else
			{
				indexEnd = row;
				indexStart = rowTemp;
				vec.push_back({indexStart,indexEnd});
				rowTemp = (indexEnd+1);
				v++;
			}
		}
	}
	return vec;
}
