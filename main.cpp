/*
 * main.cpp
 *
 *  Created on: 5 Dec 2016
 *      Author: dm00314
 */

#include "SceneGraph.h"
#include <iostream>

void draw(){
	SceneGraph* obj;
	obj = SceneGraph::GetInstance();
	obj->draw();
}


int main(int argc, char** argv){

	try{
		if(argc!=2){
			std::cerr<<"Only one argument expected. Which is the path to the file"<<std::endl;
		}
		else{
		
			SceneGraph* obj;
			obj = SceneGraph::GetInstance();
			obj->read_file(argv[1]);
			window w(argc, argv);
		}
	}

	/*Polygon+ScnenGr+Node Exceptions*/

	catch(BadHeaderException& e){
		std::cerr<<"BadHeaderException Occurred"<<std::endl;
	}
	catch(BadFooterException& e){
			std::cerr<<"BadFooterException Occurred"<<std::endl;
	}
	catch(BadColourArgumentException& e){
			std::cerr<<"BadColourArgumentException Occurred"<<std::endl;
	}
	catch(BadNumberOfVertArgumentException& e){
			std::cerr<<"BadNumberOfVertArgumentException Occurred"<<std::endl;
	}
	catch(BadFileException& e){
			std::cerr<<"BadFileException Occurred"<<std::endl;
	}
	catch(BadReadElementException& e){
			std::cerr<<"BadReadelementException Occurred"<<std::endl;
	}
	catch(WrongInputException& e){
			std::cerr<<"WrongInputException Occurred"<<std::endl;
	}
	catch(BadColourException& e){
				std::cerr<<"BadColourException Occurred"<<std::endl;
		}
	catch(badRadiusException& e){
					std::cerr<<"badRadiusException Occurred"<<std::endl;
			}
	catch(badNumPointsException& e){
						std::cerr<<"badNumPointsException Occurred"<<std::endl;
				}
	return 0;
}

