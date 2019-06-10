#include "Sphere.h"

static double PI = 3.141592653;
Sphere::Sphere()
{
}


double Sphere::cubage() const
{
	double cub = 3.0 / 4 * PI*(xsize / 2) *(xsize / 2)*(xsize / 2);
	return cub;
}

double Sphere::area() const
{

	double area = 4 * PI*(xsize / 2)*(xsize / 2);
	return area;
}

void Sphere::print() const
{
	cout << "thr radium is " << xsize / 2 << " the area is " << area() << " the cubage is " << cubage() << endl;
}

Sphere::~Sphere()
{
}
