/*
 * =====================================================================================
 *
 *       Filename:  myqglviewer.cpp      Created:  03/14/2015 10:21:55 AM
 *
 *    Description:  manage display
 *
 *         Author:  Wu Bo (Robert), wubo.gfkd@gmail.com
 *		Copyright:	Copyright (c) 2015, Wu Bo
 *   Organization:  National University of Defense Technology
 *
 * =====================================================================================
 */
#include <math.h>
#include "myqglviewer.h"
Viewer::Viewer(QWidget *parent) : QGLViewer(parent)
{
	restoreStateFromFile();
	b_show = true;
}

void Viewer::init()
{
	restoreStateFromFile();
	setAxisIsDrawn(false);
}

void Viewer::draw()
{
	if(b_show == true)
	{
		const float nbSteps = 200.0;
		glBegin(GL_QUAD_STRIP);
		for (float i = 0; i < nbSteps; ++i)
		{
			float ratio = i / nbSteps;
			float angle = 21.0 * ratio;
			float c = cos(angle);
			float s = sin(angle);
			float r1 = 1.0 - 0.8 * ratio;
			float r2 = 0.8 - 0.8 * ratio;
			float alt = ratio - 0.5;
			const float nor = .5;
			const float up = sqrt(1.0 - nor*nor);
			glColor3f(1.0-ratio, 0.2f, ratio);
			glNormal3f(nor*c, up, nor*s);
			glVertex3f(r1*c, alt, r1*s);
			glVertex3f(r2*c, alt+0.05, r2*s);
		}
		glEnd();
	}
}
void Viewer::toggle_show()
{
	b_show = !b_show;
	updateGL();
}
