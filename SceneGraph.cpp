/*
 * SceneGraph.cpp
 *
 *  Created on: 5 Dec 2016
 *      Author: dm00314
 */

#include "SceneGraph.h"

/*
**Singleton container class implementation
*/
SceneGraph* SceneGraph::SGInstance = NULL;

SceneGraph::SceneGraph(){
}

SceneGraph* SceneGraph::GetInstance(){
	if (SGInstance == NULL) {
		SGInstance = new SceneGraph();
	}
	return SGInstance;
}

SceneGraph::~SceneGraph()
{
	container.clear();
}

/*Reads an input file and creates a list of objects while checking errors
** @param input file path or name if the same directory
*/
void SceneGraph::read_file(std::string file_path) {

	std::ifstream file(file_path.c_str());
	if (!file.good()) {
		throw BadFileException();
	}
	int count(1);
	while (!file.eof()) {
		std::cout<<container.size()<<std::endl;

		std::string object_type;
		file >> object_type;

		std::cout<<"In Scene::While loop (times: "<< count++ <<")"<<std::endl;
		std::cout<<"Object type: "<<object_type<<std::endl;

		if (object_type == "polygon") {
			Polygon* polygonIn = new Polygon ;
			std::cout<<"In Scene::Creating Polygon"<<std::endl;
			file >> *(polygonIn);
			polygonIn->print();
			if (file.fail()){
				throw BadReadElementException();
			}
			container.push_back(polygonIn);
		}
		else if (object_type == "circle") {
			Circle* circleIn = new Circle;
			std::cout<<"In Scene::Creating Circle"<<std::endl;
			file >> *(circleIn);
			circleIn->print();
			if (file.fail()){
				throw BadReadElementException();
			}
			container.push_back(circleIn);
		}
		else if (object_type == "translate") {
			Translate* translateIn = new Translate;
			std::cout<<"In Scene::Creating Translate"<<std::endl;
			file >> *(translateIn);
			translateIn->print();
			if (file.fail()){
				throw BadReadElementException();
			}
			container.push_back(translateIn);
		}
		else if (object_type == "scale") {
			Scale* scaleIn = new Scale;
			std::cout<<"In Scene::Creating Scale"<<std::endl;
			file >> *(scaleIn);
			scaleIn->print();
			if (file.fail()){
				throw BadReadElementException();
			}
			container.push_back(scaleIn);
		}
		else if (object_type==""){
			break;
		}
		else
		{
			throw WrongInputException();
		}
	}
	std::cerr<<container.size()<<std::endl;
	print();

	file.close();
}

void SceneGraph::print() {
	std::cout<<"Print starts:"<<std::endl;
	for (std::list<Node*>::const_iterator /*auto*/ iter(container.begin()); iter != container.end();iter++) {
		(*iter)->print(); //QUESTION is this a right type of definition?
	}
}

/*
** Draws the scene using inheritance .draw() based on the object
*/
void SceneGraph::draw() {
	for (std::list<Node*>::const_iterator /*auto*/ iter(container.begin()); iter != container.end();iter++) {
		(*iter)->draw(); //QUESTION is this a right type of definition?
	}
}


