/*
 * SceneGraph.h
 *
 *  Created on: 5 Dec 2016
 *      Author: dm00314
 */

#ifndef SCENEGRAPH_H_
#define SCENEGRAPH_H_


/*Header file for the Scene Graph which
**Stores a list of nodes after reading a file
**Also draws the whole scene
**Simply a container singleton class */

#include <iostream>
#include <fstream>
#include <string>
#include  <list>
#include "Polygon.h"
#include "Circle.h"
#include "Translate.h"
#include "Scale.h"
#include "Node.h"
#include "Window.h"

class BadFileException{};
class BadReadElementException{};
class WrongInputException{};

class SceneGraph {
private:
	SceneGraph();
	std::list <Node*> container;
	SceneGraph(const SceneGraph&);
public:
	static SceneGraph*  SGInstance;
	static SceneGraph* GetInstance();
	virtual ~SceneGraph();
	void draw(void);
	void read_file(std::string file_path);
	void print();
};

#endif /* SCENEGRAPH_H_ */
