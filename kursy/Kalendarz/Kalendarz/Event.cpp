#include <iostream>
#include "Event.h"
#include <string>

using namespace std;


Event::Event(string n, int y, int mon, int d, int h, int min) {
	this->name = n;
	this->year = y;
	this->month = mon;
	this->day = d;
	this->hour = h;
	this->minute = min;
}

Event::~Event(){
	//jakiœ kod
}

void Event::load() {
	cout << endl << "Podaj nazwe wydarzenia";
	cin >> this->name;
	cout << endl << "Podaj rok wydarzenia";
	cin >> this->year;
	cout << endl << "Podaj miesiac wydarzenia";
	cin >> this->month;
	cout << endl << "Podaj dzien wydarzenia";
	cin >> this->day;
	cout << endl << "Podaj godzine wydarzenia";
	cin >> this->hour;
	cout << endl << "Podaj minute wydarzenia";
	cin >> this->minute;
}

void Event::show() {
	cout << endl << this->name << ",  " << this->day << "-" << this->month << "-" << this->year << "r.; " << this->hour << "." << this->minute << endl;
}

