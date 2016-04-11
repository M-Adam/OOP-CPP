#include <iostream>
#include <math.h>

using namespace std;


class point {
public:
	double tab[3];
	bool operator>(point);
	bool operator<(point);
	bool operator==(point);
	point(double, double, double);
};

point::point(double a = 0, double b = 0, double c = 0) {
	this->tab[0] = a;
	this->tab[1] = b;
	this->tab[2] = c;
}

bool point::operator <(point p) {
	double d1 = (this->tab[0] * this->tab[0]) + (this->tab[1] * this->tab[1]) + (this->tab[2] * this->tab[2]);
	d1 = sqrt(d1);

	double d2 = (p.tab[0] * p.tab[0]) + (p.tab[1] * p.tab[1]) + (p.tab[2] * p.tab[2]);
	d2 = sqrt(d2);

	if (d1 < d2) return true;
	else
		return false;
	return (d1 < d2) ? true : false;
}

bool point::operator >(point p) {
	double d1 = (this->tab[0] * this->tab[0]) + (this->tab[1] * this->tab[1]) + (this->tab[2] * this->tab[2]);
	d1 = sqrt(d1);

	double d2 = (p.tab[0] * p.tab[0]) + (p.tab[1] * p.tab[1]) + (p.tab[2] * p.tab[2]);
	d2 = sqrt(d2);

	if (d1>d2) return true;
	else
		return false;

}

bool point::operator ==(point p) {
	double d1 = (this->tab[0] * this->tab[0]) + (this->tab[1] * this->tab[1]) + (this->tab[2] * this->tab[2]);
	d1 = sqrt(d1);

	double d2 = (p.tab[0] * p.tab[0]) + (p.tab[1] * p.tab[1]) + (p.tab[2] * p.tab[2]);
	d2 = sqrt(d2);

	if (d1 == d2) return true;
	else
		return false;
}


