/*
 * Polygon.h
 *
 *  Created on: 5 Dec 2016
 *      Author: dm00314
 */

#ifndef POLYGON_H_
#define POLYGON_H_

#include <iostream>
#include <string>
#include "Node.h"
#include <vector>

class BadHeaderException{};
class BadFooterException{};
class BadColourArgumentException{};
class BadNumberOfVertArgumentException{};

class Polygon :public Node {
protected:
	std::vector<float> color;
private:
	Polygon(const Polygon&);
	int n_vrtxs;
	int count;
	float *xArr,*yArr,*zArr;

public:
	Polygon();
	virtual ~Polygon();
	friend std::istream& operator>>(std::istream & in, Polygon &a);
	void draw();
	void setcolor(float, float, float);
	void setnvrtxs(int);
	int getnvrtxs() const;
	void CreateArrs(int);
	void addVrtxToArr(float, float, float);
	void getArrOfVrtxs(float*, float*, float*) const;
	void print();
};

#endif /* POLYGON_H_ */
