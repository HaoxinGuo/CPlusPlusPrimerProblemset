#pragma once
#include "Figure_2D.h"
class Rectangle :
	public Figure_2D
{
public:
	Rectangle();
	Rectangle(const double &a, const double &b) :Figure_2D(a, b) {};
	double area() const override;
	double pcrimeter() const override;
	void print() const override;
	~Rectangle();
};

