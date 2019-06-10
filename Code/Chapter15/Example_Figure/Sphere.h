#pragma once
#include "Figure_3D.h"
class Sphere :
	public Figure_3D
{
public:
	Sphere();
	Sphere(const double &a, const double &b, const double &c) :Figure_3D(a, b, c) {};
	double cubage() const override;
	double area() const override;
	void print() const override;
	~Sphere();
};

