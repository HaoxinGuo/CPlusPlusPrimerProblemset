#include<iostream>
#include"Figure.h"
#include"Figure_2D.h"
#include"Rectangle.h"
#include"Circle.h"
#include"Sphere.h"
using namespace std;
/*
void Print_Figure_2D(ostream &os, const Figure &figure) {
	os<<"xsize "<< figure.xsize <<
}
*/


int main() {
	Figure item1(10, 20);
	item1.print();
	Rectangle item2(10, 20);
	item2.print();
	Circle item3(10, 10);
	item3.print();
	Sphere item4(10,10,10);
	item4.print();
	char ch;
	cin >> ch;
	return 0;
}
