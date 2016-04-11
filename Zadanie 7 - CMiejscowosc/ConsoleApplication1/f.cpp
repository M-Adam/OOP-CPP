#include <iostream>
#include "Header.h"

using namespace std;

int CMiejscowosc::liczbaLudzi = 0;

void CMiejscowosc::dodajCzlowieka(){
	CMiejscowosc::liczbaLudzi++;
}

void CMiejscowosc::wyswietl(){
	if ((CMiejscowosc::liczbaLudzi >= 0) && (CMiejscowosc::liczbaLudzi <= 10))
		cout << endl << "Wiocha" << endl;
	else if ((CMiejscowosc::liczbaLudzi > 10) && (CMiejscowosc::liczbaLudzi <= 100))
		cout << endl << "Mieœcinka" << endl;
	else if ((CMiejscowosc::liczbaLudzi > 100) && (CMiejscowosc::liczbaLudzi <= 1000))
		cout << endl << "Miejscowosc" << endl;
	else
		cout << endl << "Miasto" << endl;
}

CCzlowiek::CCzlowiek(int a){
	if (a > 99)
		this->waga = 99;
	else if (a < 1)
		this->waga = 1;
	else
		this->waga = a;
	CMiejscowosc::dodajCzlowieka();
}

int CCzlowiek::getWaga(){
	return this->waga;
}

CUfok::CUfok(int w, int z) :CCzlowiek(w){
	this->zielonosc = z;
}

int CUfok::getZielonosc(){
	return this->zielonosc;
}

