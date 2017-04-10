/*
 * Scale.h
 *
 *  Created on: 6 Dec 2016
 *      Author: dm00314
 */

#ifndef SCALE_H_
#define SCALE_H_

#include <iostream>
#include <string>
#include "Node.h"
#include "Polygon.h"
#include <vector>

class Scale :public Node {
private:
	Scale(const Scale&);
	std::vector<float> size;
public:
	Scale():size(3,0){};
	virtual ~Scale(){};
	void draw();
	void print();
	friend std::istream& operator >> (std::istream & in, Scale &a);
};


#endif /* SCALE_H_ */
