#include <iostream>
#include "class.h"

using namespace std;

int main(){
	CSmietnik *tab = new CSmietnik[10];
	CSmietnik *a = new CSmietnik(5);

	for (int i = 0; i < 10; i++)
		tab[i].wyswietl();

	CSmietnik::zwiekszLicznik(9);
	
	return 0;
}