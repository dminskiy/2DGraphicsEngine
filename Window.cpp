/*
 * Window.cpp
 *
 *  Created on: 8 Dec 2016
 *      Author: dm00314
 */
#include "Window.h"

window::window(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);
  glutInitWindowSize(500, 500);
  glutCreateWindow("C++ Assignment [Group 14]");
  glutDisplayFunc(&display);
  glutIdleFunc(&display);
  glutReshapeFunc(&reshape);
  glutKeyboardFunc(&keyboard);

  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glClearDepth(1.0);
  glDepthFunc(GL_LESS);
  glEnable(GL_DEPTH_TEST);
  glShadeModel(GL_SMOOTH);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  glMatrixMode(GL_MODELVIEW);
  glutMainLoop();
}

void window::reshape ( int w, int h )
{
  glViewport     ( 0, 0, w, h );
  glMatrixMode   ( GL_PROJECTION );
  glLoadIdentity ( );
  if ( h==0 )
    gluPerspective ( 80, ( float ) w, 1.0, 5000.0 );
  else
    gluPerspective ( 80, ( float ) w / ( float ) h, 1.0, 5000.0 );
  glMatrixMode   ( GL_MODELVIEW );
}

void window::keyboard( unsigned char key, int x, int y )
{
  switch ( key ) {
  case 27:
    exit ( 0 );
    break;
  default:
    break;
  }
}

void window::display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  glTranslatef(0.0f,0.0f,-6.0f);
  draw();
  glutSwapBuffers ( );
}



