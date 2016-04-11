#include <iostream>
#include <math.h>

using namespace std;

class Complex{
private:
	double r, i;
public:
	Complex(){
		this->r = 0;
		this->i = 0;
	}
	Complex(double a, double b){
		this->r = a;
		this->i = b;
	}
	double getR(){
		return this->r;
	}
	double getI(){
		return this->i;
	}
	double modul(){
		return sqrt(this->i*this->i + this->r*this->r);
	}
};

int main(){
	Complex a(5, 4);
	cout << a.modul() << endl;
	return 0;
}