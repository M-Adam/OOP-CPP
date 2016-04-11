#include <iostream>
#include "class.h"

using namespace std;

long CSmietnik::E = 0;

CSmietnik::CSmietnik() :F(-13){
	this->A = 1;
	this->B = 2.5;
	for (int i = 0; i < 15; i++)
		this->C[i] = 'a';
	this->D = NULL;
}

CSmietnik::CSmietnik(int a) :F(-13){
	this->D = new short[a];
	for (int i = 0; i < a; i++)
		this->D[i] = i-5;
}

CSmietnik::CSmietnik(int x, float y):F(-13){
	this->A = x;
	this->B = y;
	this->D = NULL;
}

void CSmietnik::wyswietl(){
	cout << this->A << " " << this->B << " " << this->E << " " << this->F;
	for (int i = 0; i < 15; i++)
		cout << " " << this->C[i];
	cout << endl;
}

void CSmietnik::zwiekszLicznik(int a){
	cout << endl;
}

CSmietnik::~CSmietnik(){
	if (this->D != NULL)
		delete this->D;
}