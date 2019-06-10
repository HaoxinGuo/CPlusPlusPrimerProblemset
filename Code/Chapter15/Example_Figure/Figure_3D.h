#pragma once
#include "Figure.h"
class Figure_3D :
	public Figure
{
public:
	Figure_3D();
	Figure_3D(const double &a, const double &b, const double &c) :Figure(a, b), zsize(c) {};
	virtual double area() const = 0;
	virtual double cubage() const = 0;
	virtual void print() const = 0;
	~Figure_3D();
protected:
	double zsize;
};

