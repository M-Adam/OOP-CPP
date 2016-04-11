#include "Header.h"
#include <iostream>
#include <string>

using namespace std;

void Poczta::setNadawca(string a){
	this->nadawca = a;
}
void Poczta::setOdbiorca(string a){
	this->odbiorca = a;
}
void Poczta::setTemat(string a){
	this->temat = a;
}
void Poczta::setTresc(string a){
	this->tresc = a;
}

string Poczta::getNadawca(){
	return this->nadawca;
}
string Poczta::getOdbiorca(){
	return this->odbiorca;
}
string Poczta::getTemat(){
	return this->temat;
}
string Poczta::getTresc(){
	return this->tresc;
}
void Poczta::wypisz(){
	cout << endl <<
		"Nadawca wiadomosci: " << this->nadawca << endl <<
		"Odbiorca wiadomosci: " << this->odbiorca << endl <<
		"Temat wiadomosci: " << this->temat << endl <<
		"Tresc wiadomosci: " << this->tresc << endl;
}
void Poczta::wprowadz(){
	cout << endl << "Podaj nadawcê" << endl;
	cin >> this->nadawca;
	cout << "Podaj odbiorcê" << endl;
	cin >> this->odbiorca;
	cout << "Podaj temat" << endl;
	cin >> this->temat;
	cout << "Podaj tresc" << endl;
	cin >> this->tresc;
	this->wypisz();
}