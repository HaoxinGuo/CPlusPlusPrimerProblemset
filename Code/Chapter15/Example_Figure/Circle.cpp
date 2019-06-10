#include "Circle.h"

static double PI = 3.1415926;

Circle::Circle()
{
}


double Circle::area() const
{
	double area = PI * xsize*xsize / 4.0;
	return area;
}

double Circle::pcrimeter() const
{
	double pcri = PI * xsize;
	return pcri;
}

void Circle::print() const
{
	cout << "the radium is " << xsize / 2 << " the area is " << area() << " the pcrimeter is " << pcrimeter() << endl;
}

Circle::~Circle()
{
}
