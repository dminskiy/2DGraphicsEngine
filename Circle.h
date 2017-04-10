/*
 * Circle.h
 *
 *  Created on: 6 Dec 2016
 *      Author: dm00314
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_

#include <iostream>
#include <string>
#include "Polygon.h"

class BadColourException{};
class badRadiusException{};
class badNumPointsException{};



class Circle: public Polygon{
private:
	float Radius;
	int numpoints;
	Circle(const Circle&);
public:
	Circle();
	virtual ~Circle(){};
	friend std::istream& operator>>(std::istream &in, Circle &a);
	void print();
};



#endif /* CIRCLE_H_ */
