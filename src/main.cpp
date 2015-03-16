/*
 * =====================================================================================
 *
 *       Filename:  main.cpp      Created:  03/14/2015 11:16:07 AM
 *
 *    Description:  main function
 *
 *         Author:  Wu Bo (Robert), wubo.gfkd@gmail.com
 *		Copyright:	Copyright (c) 2015, Wu Bo
 *   Organization:  National University of Defense Technology
 *
 * =====================================================================================
 */
#include <qapplication.h>
#include <QMainWindow>
#include "ui_gui_design.h"
class Window : public QMainWindow, Ui::MainWindow
{
	public:
		Window()
		{
			setupUi(this);
		}
};

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	Window win;
	win.show();
	return (app.exec());
}
