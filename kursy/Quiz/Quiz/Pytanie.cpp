#include <iostream>
#include "pytanie.h"
#include <fstream>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

int Pytanie::Wynik = 0;

void Start(Pytanie p[], int ilosc){

	for (int i = 0; i < ilosc; i++)
	{
		p[i].setNr_pytania(i);
		p[i].wczytaj();
		p[i].zadaj_pytanie();
		p[i].sprawdz();
	}
	cout << endl << "Koniec! Ilosc zdobytych punktow = " << Pytanie::getWynik() << endl;
}

Pytanie::Pytanie(){
	this->punkt = 0;
}

void Pytanie::wczytaj(){
	
	fstream plik;
	plik.open("quiz.txt", ios::in);

	if (plik.good() == false) {
		cout << "Nie uda³o siê otworzyæ pliku z pytaniami! :(";
		int out;
		cin >> out;
		exit(0);
	}
	
	int nr_linii = this->nr_pytania * 6 + 1;
	int aktualny_nr = 1;
	string linia;

	while (getline(plik,linia)){
		if (aktualny_nr == nr_linii) this->tresc = linia;
		if (aktualny_nr == nr_linii + 1) this->OdpA = linia;
		if (aktualny_nr == nr_linii + 2) this->OdpB = linia;
		if (aktualny_nr == nr_linii + 3) this->OdpC = linia;
		if (aktualny_nr == nr_linii + 4) this->OdpD = linia;
		if (aktualny_nr == nr_linii + 5) this->poprawna = linia;
		aktualny_nr++;
	}
	plik.close();
}

void Pytanie::zadaj_pytanie(){
	cout << endl << this->tresc << endl;
	cout << this->OdpA << endl;
	cout << this->OdpB << endl;
	cout << this->OdpC << endl;
	cout << this->OdpD << endl;
	cout << "------------" << endl;
	cout << "Odpowiedz: ";
	cin >> this->odpowiedz;
	transform(this->odpowiedz.begin(), this->odpowiedz.end(), 
		this->odpowiedz.begin(), ::tolower);
}

void Pytanie::sprawdz(){
	if (this->odpowiedz == this->poprawna)
		Wynik++;
}

void Pytanie::setNr_pytania(int x){ 
	this->nr_pytania = x; 
}

int Pytanie::getPunkt() { 
	return this->punkt; 
}

int Pytanie::getWynik() {
	return Wynik;
}

Pytanie::~Pytanie(){
	// cout << "Destruktor!";
}