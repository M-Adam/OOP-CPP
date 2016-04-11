#include <iostream>
#include <cstdlib>
#include "Header.h"
#include <ctime>


using namespace std;

int main(){
	CMiejscowosc a;
	CCzlowiek **wsk = new CCzlowiek*[100];
	CUfok **ufo = new CUfok*[200];
	int waga_progowa, liczba_ludzi=0;

	srand(time(NULL));
	for (int i = 0; i < 100; i++)
		wsk[i] = new CCzlowiek(rand()%100);
	for (int i = 0; i < 200; i++)
		ufo[i] = new CUfok(rand()%100, rand()%100);
	
	cin >> waga_progowa;

	for (int i = 0; i < 100; i++)
		if (wsk[i]->getWaga() > waga_progowa)
			liczba_ludzi++;

	cout << "Liczba ludzi przekraczajacych wage: " << liczba_ludzi;
	
	a.wyswietl();

	delete[] wsk;
	delete[] ufo;

	return 0;
}