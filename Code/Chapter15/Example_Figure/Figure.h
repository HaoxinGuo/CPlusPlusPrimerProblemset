#pragma once
#include<iostream>
using namespace std;
class Figure
{
public:
	Figure();
	Figure(const double &a,const double &b) :xsize(a), ysize(b) {};
	virtual void print() const { cout <<"xsize is "<< xsize << " ysize is " <<ysize << endl; }
	~Figure();
protected:
	double xsize, ysize;
};

