#include <iostream>
#include "cmacierz.h"

using namespace std;

CMacierz::CMacierz(int ilWierszy, int ilKolumn){
	this->ilKolumn = ilKolumn;
	this->ilWierszy = ilWierszy;
	this->macierz = new int*[ilWierszy];
	for (int i = 0; i < ilWierszy; i++)
		this->macierz[i] = new int[ilKolumn];
	
	for (int i = 0; i < ilWierszy; i++)
		for (int j = 0; j < ilKolumn; j++)
			this->macierz[i][j] = 0;
}

CMacierz::~CMacierz(){
	for (int i = 0; i < this->ilWierszy; i++)
		delete[] this->macierz[i];
	delete[] this->macierz;
}

void CMacierzDodawanie::Dodaj(CMacierz *M){
	if (this->ilKolumn == M->ilKolumn && this->ilWierszy == M->ilWierszy){
		for (int i = 0; i < this->ilWierszy; i++)
			for (int j = 0; j < this->ilKolumn; j++)
				this->macierz[i][j] += M->macierz[i][j];
	}
	else
		cout << "Macierze maja rozne wymiary" << endl;
}

void CMacierzOdwrotna::Transponuj(){
	int **kopia = new int*[this->ilWierszy];

	for (int i = 0; i < this->ilWierszy; i++)
		kopia[i] = new int[this->ilKolumn];
	for (int i = 0; i < this->ilWierszy; i++)
		for (int j = 0; j < this->ilKolumn; j++)
			kopia[i][j] = this->macierz[i][j];

	this->macierz = new int*[this->ilKolumn];
	for (int i = 0; i < this->ilKolumn; i++)
		this->macierz[i] = new int[this->ilWierszy];
	for (int i = 0; i < this->ilKolumn; i++)
		for (int j = 0; j < this->ilWierszy; j++)
			this->macierz[i][j] = kopia[j][i];

	for (int i = 0; i < this->ilWierszy; i++)
		delete[] kopia[i];
	delete[] kopia;

	int pom = this->ilWierszy;
	this->ilWierszy = this->ilKolumn;
	this->ilKolumn = pom;

	
}