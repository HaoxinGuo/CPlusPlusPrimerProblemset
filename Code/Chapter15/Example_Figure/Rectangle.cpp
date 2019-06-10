#include "Rectangle.h"



Rectangle::Rectangle()
{
}


double Rectangle::area() const
{
	double area = xsize * ysize;
	return area;
}

double Rectangle::pcrimeter() const
{
	double peri = 2*(xsize+ysize);
	return peri;
}

void Rectangle::print() const
{
	Figure::print();
	cout << "the area is " << area() << " the pcrimeter is " << pcrimeter() << endl;
}

Rectangle::~Rectangle()
{
}
