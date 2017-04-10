/*
 * Scale.cpp
 *
 *  Created on: 6 Dec 2016
 *      Author: dm00314
 */

#include "Scale.h"
#include "Polygon.h"


std::istream& operator>> (std::istream & in, Scale &a) {

	char header;
	in>>header;
	if (header !='[')
		throw BadFooterException();

		in >> a.size[0] >> a.size[1] >> a.size[2] >> std::ws;

		char footer;
		in>>footer;
		if (footer !=']')
			throw BadFooterException();
		//std::cout<<"Scale read"<<std::endl;
		return in;
}

void Scale::print(){
	std::cout<<"scale ["<<std::endl;
	std::cout<< size[0]<<" "<<size[1]<<" "<<size[2]<<" "<<std::endl;
	std::cout<<"]"<<std::endl;
}

void Scale::draw(){
	glScalef(size[0],size[1],size[2]);
}


