#include <iostream>
#include "cmacierz.h"

using namespace std;

int main(){
	CMacierzDodawanie *D = new CMacierzDodawanie(3,5);
	CMacierzOdwrotna *O = new CMacierzOdwrotna(5,3);

	for (int i = 0; i < O->ilWierszy; i++)
	{
		for (int j = 0; j < O->ilKolumn; j++)
			cout << O->macierz[i][j] << " ";
		cout << endl;
	}

	O->Transponuj();
	D->Dodaj(O);
	cout << endl << endl;

	for (int i = 0; i < O->ilWierszy; i++)	{
		for (int j = 0; j < O->ilKolumn; j++)
			cout << O->macierz[i][j] << " ";
		cout << endl;
	}

	return 0;
}