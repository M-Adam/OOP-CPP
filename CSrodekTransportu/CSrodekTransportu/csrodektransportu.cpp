#include <iostream>
#include <string>
#include "Header.h"

using namespace std;

void CSamochod::rozpocznij() {
	this->x = 0;
	this->y = 0;
	cout << "Ruszam" << endl;
}

void CSamochod::porusz() {
	this->x += 10;
	this->y += 5;
}

void CSamochod::zakoncz() {
	cout << "Parkuje" << endl;
}

void CSamochod::wyswietl() {
	cout << x << " " << y << endl;
}


void CSamolot::rozpocznij() {
	this->x = 0;
	this->y = 0;
	this->z = 1000;
	cout << "Startuje" << endl;
}

void CSamolot::porusz() {
	this->x += 100;
	this->y += 50;
}

void CSamolot::zakoncz() {
	this->z = 0;
	cout << "L¹dujê" << endl;
}

void CSamolot::wyswietl() {
	cout << x << " " << y << " " << z << endl;
}