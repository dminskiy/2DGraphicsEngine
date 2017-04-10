/*
 * Polygon.cpp
 *
 *  Created on: 5 Dec 2016
 *      Author: dm00314
 */
#include "Polygon.h"
/*
** Set of functions aimed at reading and drawing Polynomials as well as drawing Circles
** TODO: check_footer/header in Node.cpp
*/

/*Constructor that initialises vars and created arrays of vertexes to be  used later */
Polygon::Polygon(): n_vrtxs(0), color(3, 0), count(0), xArr(NULL),yArr(NULL),zArr(NULL)
{
}

/*Virtual destructor*/
Polygon::~Polygon(){
	delete[] xArr;
	delete[] yArr;
	delete[] zArr;
	color.clear();
}

void Polygon::setcolor(float r, float g, float b) {
	color[0] = r; color[1] = g; color[2] = b;
}

void Polygon::setnvrtxs(int sz){
	 n_vrtxs = sz;
}

int Polygon::getnvrtxs() const{
	return n_vrtxs;
}

void Polygon::CreateArrs(int sz){
	try{
			xArr = new float[sz];
		}
	catch (const std::bad_alloc& e){
			std::cerr<<"xArr Allocation Failed: " << "\n";
		}
	try{
			yArr = new float[sz];
		}
	catch (const std::bad_alloc& e){
			std::cerr<<"yArr Allocation Failed: "  << "\n";
		}
	try{
			zArr = new float[sz];
		}
	catch (const std::bad_alloc& e){
			std::cerr<<"zArr Allocation Failed: " << "\n";
		}
}

void Polygon::addVrtxToArr(float x, float y, float z){
	xArr[count]=x;
	yArr[count]=y;
	zArr[count]=z;
	count++;
}

void Polygon::getArrOfVrtxs(float *x, float *y, float *z) const{
	x = xArr;
	y = yArr;
	z = zArr;
}

void Polygon::print(){
	if (xArr==NULL && yArr==NULL && zArr==NULL){std::cout<<"arrays are empty"<<std::endl;}
	std::cout<<"polygon ["<<std::endl;
	std::cout<<"colour "<< color[0]<<" "<<color[1]<<" "<<color[2]<<" "<<std::endl;
	std::cout<<"num_vert s"<<n_vrtxs<<std::endl;
	for (int i(0); i<n_vrtxs;i++){
		std::cout<< xArr[i]<<" "<< yArr[i]<<" "<< zArr[i]<<" "<<std::endl;
	}
	std::cout<<"]"<<std::endl;
}

/*
**Overloaded operator>>
**Reads all the info for a Polynomial using pre-written functions
*/
std::istream& operator>> (std::istream &in, Polygon &a) {

	char header;
	in>>header;
	if (header!='[')
		throw BadHeaderException();

	std::string temp;
	in >> temp;

	if (temp == "colour") {
		float r, g, b;
		in >> r >> g >> b >> std::ws;
		a.setcolor(r,g,b);
	}
	else {
		throw BadColourArgumentException();
	}

	temp.clear();
	in >> temp;

	if (temp == "num_vert") {
		int size;
		in >> size;
		a.setnvrtxs(size);
		a.CreateArrs(size);
		float x, y, z;
		for (int i(0); i < size; i++) {
			in >> x >> y >> z;
			a.addVrtxToArr(x, y, z);
		}
	}
	else {
		throw BadNumberOfVertArgumentException();
	}

	char footer;
	in>>footer;
	if (footer!=']')
		throw BadFooterException();

	std::cout<<"Polygon read"<<std::endl;
	return in;
}

/*
** Draws 50 vertexes max, might be extended by manually adding more lines and increasing MAX_NUMBER_OF_VERTEXES
** If ther're less than 50 vertexes the algorithm fills the difference with values equal to the last vertex values which doesnt change the shape.
 */
void Polygon::draw() {
	glColor3f(color[0],color[1],color[2]);
	glBegin(GL_LINE_LOOP);
	for(int i(0); i<n_vrtxs; i++)
		glVertex3f(xArr[i], yArr[i], zArr[i]);
	glEnd();
}



