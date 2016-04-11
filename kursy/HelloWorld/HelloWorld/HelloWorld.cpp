// HelloWorld.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "moje.h"
#include <string>

using namespace std;

int main()
{
	int i(2);
	double k = 2.5;
	int p = static_cast<int>(k);
	auto a = 3 / 2;
	const int abc = 10;
	string powitanie = "siemasz!"  ;
	powitanie += " Jak tam?";
	cout << "Hello, World!" << endl << i << " " << k << " "<<p << " " << a << " " << abc << endl;

	if (i == 2)
		for (int petla = 0; petla < 3; petla++)
			cout << petla << " ";
	
	//cout << endl << "zmienna z petli: " << petla;

	//switch,while,trojargument takie samo 

	cout << endl << dodaj(i, a) << endl; //u¿ycie funkcji z pliku moje.h
	cout << powitanie ; //dzia³a, bo dodana biblio string
	getchar();
	return 0;
}

