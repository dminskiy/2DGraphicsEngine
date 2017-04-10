/*
 * Circle.cpp
 *
 *  Created on: 6 Dec 2016
 *      Author: dm00314
 */

#include "Circle.h"
#include "math.h"
#define PI 3.14159265359

Circle::Circle():Polygon(),Radius(0),numpoints(0)
{
}

std::istream& operator>>(std::istream & in, Circle &a)
{

	char header;
	in>>header;
	if (header!='[')
		throw BadHeaderException();

	std::string tp;
	in>>tp;

	if(tp!="colour")
	{
		throw BadColourException();
	}
	else
	{
		float red, green, blue;
		in >> red >> green >> blue >>std::ws;
		a.setcolor(red, green, blue);
	}

	tp.clear();
	in>>tp;

	if(tp!="radius")
	{
		throw badRadiusException{};
	}
	else
	{
		in >> a.Radius >> std::ws;
	}

	tp.clear();
	in>>tp;

	if(tp!="num_segments")
	{
		badNumPointsException{};
	}
	else
	{
		in>>a.numpoints>>std::ws;
	}

	char footer;
	in>>footer;
	if (footer!=']')
		throw BadFooterException();

	a.CreateArrs(a.numpoints);
	a.setnvrtxs(a.numpoints);

    for (int i=0;i<a.numpoints;i++)
    {
        float Angle = i*(2*PI/a.numpoints);

        float x = cos(Angle)*a.Radius;
        float y = sin(Angle)*a.Radius;
        float z = 0;
        a.addVrtxToArr(x, y, z);
    }
    std::cout<<"Circle read"<<std::endl;

    return in;
}

void Circle::print(){
	std::cout<<"circle ["<<std::endl;
	std::cout<<"colour "<< Polygon::color[0]<<" "<<Polygon::color[1]<<" "<<Polygon::color[2]<<" "<<std::endl;
	std::cout<<"radius "<<Radius<<std::endl;
	std::cout<<"num_segments "<<numpoints<<std::endl;
	std::cout<<"]"<<std::endl;
}

