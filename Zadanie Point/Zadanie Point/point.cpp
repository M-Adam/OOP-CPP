#include <iostream>
#include <math.h>
#include "point.h"
using namespace std;

double d(double tab[3]) {
	double a = (tab[0] * tab[0]) + (tab[1] * tab[1]) + (tab[2] * tab[2]);
	return sqrt(a);
}

point::point(double a = 0, double b = 0, double c = 0) {
	this->tab[0] = a;
	this->tab[1] = b;
	this->tab[2] = c;
}

bool point::operator <(point p) {
	double d1 = d(this->tab);
	double d2 = d(p.tab);
	return (d1 < d2) ? true : false;
}

bool point::operator >(point p) {
	double d1 = d(this->tab);
	double d2 = d(p.tab);
	return (d1 > d2) ? true : false;
}

bool point::operator ==(point p) {
	double d1 = d(this->tab);
	double d2 = d(p.tab);
	return (d1 == d2) ? true : false;
}