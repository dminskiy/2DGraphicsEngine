/*
 * Window.h
 *
 *  Created on: 5 Dec 2016
 *      Author: dm00314
 */

#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <GL/gl.h>     // The GL Header File
#include <GL/glut.h>   // The GL Utility Toolkit (Glut) Header
#include <GL/glu.h>
#include <stdlib.h>

void draw(void);

class window {
public:
	window(int argc, char** argv);
	~window(){};

	static void reshape(int w,int h);
	static void keyboard ( unsigned char key, int x, int y );
	static void display();
};

#endif /* __WINDOW_H__ */
