#include <iostream>
#include "figury.h"

using namespace std;

void czy_nalezy(Punkt &a, Prostokont &b){
	if (a.x >= b.wspX && a.x <= b.wspX + b.szer && a.y <= b.wspY && a.y >= b.wspY - b.wys)
		cout << endl << "Punkt znajduje siê w obrêbie prostok¹ta" << endl;
	else
		cout << endl << "Punkt znajduje siê poza prostok¹tem" << endl;
}

Punkt::Punkt(int a, int b){
	this->x = a;
	this->y = b;
}
int Punkt::getX(){
	return this->x;
}
int Punkt::getY(){
	return this->y;
}
void Punkt::setX(int a){
	this->x = a;
}
void Punkt::setY(int a){
	this->y = a;
}

Prostokont::Prostokont(int a, int b, int c, int d){
	this->wspX = a;
	this->wspY = b;
	this->szer = c;
	this->wys = d;
}
int Prostokont::getWspX(){
	return this->wspX;
}
int Prostokont::getWspY(){
	return this->wspY;
}
int Prostokont::getSzer(){
	return this->szer;
}
int Prostokont::getWys(){
	return this->wys;
}
void Prostokont::setWspX(int a){
	this->wspX = a;
}
void Prostokont::setWspY(int a){
	this->wspY = a;
}
void Prostokont::setSzer(int a){
	this->szer = a;
}
void Prostokont::setWys(int a){
	this->wys = a;
}
int Prostokont::pole(){
	return (this->szer*this->wys) > 0 ? (this->szer*this->wys) : -(this->szer*this->wys);
}

Kolo::Kolo(int a, int b, int p){
	this->x = a;
	this->y = b;
	this->r = p;
}
double Kolo::obwod(){
	return this->pi*this->r*2.0;
}
double Kolo::pole(){
	return this->pi*this->r*this->r;
}