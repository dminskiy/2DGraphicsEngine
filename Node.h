/*
 * Node.h
 *
 *  Created on: 5 Dec 2016
 *      Author: dm00314
 */

#ifndef NODE_H_
#define NODE_H_

#include <GL/gl.h>     // The GL Header File
#include <GL/glut.h>   // The GL Utility Toolkit (Glut) Header
#include <GL/glu.h>
#include <iostream>

class Node {

public:
	Node(){};
	virtual void draw() = 0;
	virtual void print() = 0;
	virtual ~Node(){};
private:
	Node(const Node&);
};

#endif /* NODE_H_ */
