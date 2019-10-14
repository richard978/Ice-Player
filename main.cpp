#include "mainWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	mainWindow *w = new mainWindow;
	
	w->show();

	return a.exec();
}
