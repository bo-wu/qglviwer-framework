/*
 * =====================================================================================
 *
 *       Filename:  myqglviewer.h      Created:  03/14/2015 10:19:09 AM
 *
 *    Description:  manage viewer inherited from qglviewer
 *
 *         Author:  Wu Bo (Robert), wubo.gfkd@gmail.com
 *		Copyright:	Copyright (c) 2015, Wu Bo
 *   Organization:  National University of Defense Technology
 *
 * =====================================================================================
 */
#ifndef MY_QGLVIEWER_H
#define MY_QGLVIEWER_H
#include <QGLViewer/qglviewer.h>
class Viewer : public QGLViewer
{
	Q_OBJECT
public:
	Viewer(QWidget *parent=0);
protected:
	virtual void draw();
	virtual void init();
public slots:
	void toggle_show();
signals:

private:
	bool b_show;
};

#endif

