#pragma once
#include "Figure.h"
class Figure_2D :
	public Figure
{
public:
	Figure_2D();
	Figure_2D(const double &a, const double &b) :Figure(a, b) {};
	virtual double area() const  = 0;		//求面积操作：纯虚函数
	virtual double pcrimeter() const  = 0;		//求周长操作：纯虚函数
	virtual void print() const = 0;
	~Figure_2D();
};

