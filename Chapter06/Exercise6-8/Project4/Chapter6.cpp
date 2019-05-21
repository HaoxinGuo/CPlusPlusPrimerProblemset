#include"Chapter6.h"
#include<cmath>
int fact(int val) {
	if (val < 0)
		return -1;
	int ret = 1;
	for (int i = 1; i < val + 1; ++i)
		ret *= i;
	return ret;
}

double MyABS1(double val) {
	return (val > 0) ? val : (-val);
}

double MyABS2(double val) {
	return abs(val);
}