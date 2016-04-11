#include <iostream>
#include "Header.h"

using namespace std;

int main() {
	int a;
	CSrodekTransportu *w;

	cin >> a;
	if (a % 2 == 0)
		w = new CSamochod;
	else
		w = new CSamolot;

	w->rozpocznij(); 
	w->wyswietl(); 
	w->porusz(); 
	w->porusz();
	w->wyswietl(); 
	w->zakoncz(); 
	w->wyswietl();

	delete w;

	cin.ignore();
	return 0;
}