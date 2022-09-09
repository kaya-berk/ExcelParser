#include <QtGlobal>
#include <QCoreApplication>
#include <QtCore>
#include <QVariant>
#include <QDebug>

#include <iostream>
using namespace std;

// [0] include QXlsx headers
#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"
using namespace QXlsx;

int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv);

	// [2] Reading excel file(*.xlsx)
	Document xlsxR("/home/mak/Desktop/Export+to+Excel+Default.xlsx.xlsx");
	if (xlsxR.load()) // load excel file
	{
		int row = 1; int col = 1;
		Cell* cell = xlsxR.cellAt(row, col); // get cell pointer.
		if ( cell != NULL )
		{
			QVariant var = cell->readValue(); // read cell value (number(double), QDateTime, QString ...)
			qDebug() << var; // display value. it is 'Hello Qt!'.
		}
	}

	return 0;
}
