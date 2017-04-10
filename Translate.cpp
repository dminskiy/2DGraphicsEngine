/*
 * Translate.cpp
 *
 *  Created on: 6 Dec 2016
 *      Author: dm00314
 */
#include "Translate.h"
#include "Polygon.h"


std::istream& operator>> (std::istream & in, Translate &a) {

	char header;
	in>>header;
	if (header !='[')
		throw BadFooterException();

	in >> a.move[0] >>a.move[1] >>a.move[2]>> std::ws;

	char footer;
	in>>footer;
	if (footer !=']')
		throw BadFooterException();
	std::cout<<"Translate read"<<std::endl;
	return in;
}

void Translate::print(){
	std::cout<<"translate ["<<std::endl;
	std::cout<< move[0]<<" "<<move[1]<<" "<<move[2]<<" "<<std::endl;
	std::cout<<"]"<<std::endl;
}

void Translate::draw(){
	glTranslatef(move[0],move[1],move[2]);
}




