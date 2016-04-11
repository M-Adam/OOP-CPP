#include "Header.h"
#include <iostream>

using namespace std;

void Trojkat::setPodstawa(double a){
	this->podstawa = a;
}

void Trojkat::setWysokosc(double a){
	this->wysokosc = a;
}

double Trojkat::getPodstawa(){
	return this->podstawa;
}

double Trojkat::getWysokosc(){
	return this->wysokosc;
}

void Trojkat::pole(){
	cout << endl << this->podstawa*this->wysokosc / 2 << endl;
}