#pragma once
#include "Figure_2D.h"
class Circle :
	public Figure_2D
{
public:
	Circle();
	Circle(const double &a, const double &b) :Figure_2D(a, b) {};
	double area() const override;
	double pcrimeter() const override;
	void print() const override;
	~Circle();
};

