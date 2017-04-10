#ifndef __TRANSLATE_H__
#define __TRANSLATE_H__

#include <iostream>
#include <string>
#include "Node.h"
#include "Polygon.h"
#include <vector>

class Translate :public Node {
private:
	Translate(const Translate&);
	std::vector<float> move;
public:
	Translate() :move(3,0){};
	virtual ~Translate(){};
	void draw();
	friend std::istream& operator >> (std::istream & in, Translate &a);
	void print();
};

#endif
