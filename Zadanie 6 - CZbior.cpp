#include <iostream>

using namespace std;

class CZbior{
protected:
	int *tab, indeks;
public:
	CZbior();
	virtual void Dodaj(int);
	virtual double Oblicz() = 0;
	~CZbior();
};

class CZbiorSrednia :public CZbior{
public:
	CZbiorSrednia();
	double Oblicz();
};

class CZbiorMax :public CZbior{
public:
	CZbiorMax();
	double Oblicz();
	void Dodaj(int);
};



CZbior::CZbior(){
	this->tab = new int[100];
	this->indeks = 0;
	cout << "Konstruktor rodzica" << endl;
}
void CZbior::Dodaj(int wartosc){
	this->tab[this->indeks] = wartosc;
	this->indeks++;
}
CZbior::~CZbior(){
	cout << "Destruktor rodzica" << endl;
	delete[] this->tab;
}

CZbiorSrednia::CZbiorSrednia() :CZbior(){
	cout << "Konstruktor CZbiorSrednia" << endl;
}
double CZbiorSrednia::Oblicz(){
	double suma = 0;
	for (int i = 0; i<this->indeks; i++)
		suma += this->tab[i];
	return suma / indeks;
}

CZbiorMax::CZbiorMax() :CZbior(){
	cout << "Konstruktor CZbiorMax" << endl;
}
double CZbiorMax::Oblicz(){
	double maks = this->tab[0];
	for (int i = 1; i<this->indeks; i++)
		if (this->tab[i]>maks)
			maks = this->tab[i];
	return maks;
}
void CZbiorMax::Dodaj(int wartosc){
	if (this->indeks > 99)
		cout << "brak miejsca w tablicy" << endl;
	else {
		this->tab[this->indeks] = wartosc;
		this->indeks++;
	}
}

int main(){
	CZbior *wsk[4];
	wsk[0] = new CZbiorSrednia;
	wsk[1] = new CZbiorSrednia;
	wsk[2] = new CZbiorMax;
	wsk[3] = new CZbiorMax;

	for (int i = 0, j = 10, k=15; i<5; i++, j += 10, k+=15){
		wsk[0]->Dodaj(j);
		wsk[1]->Dodaj(k);
		wsk[2]->Dodaj(j);
		wsk[3]->Dodaj(k);
	}

	for (int i = 0; i<4; i++)
		cout << wsk[i]->Oblicz() << endl;

	for (int i = 0; i < 4; i++)
		delete wsk[i];

	return 0;
}
