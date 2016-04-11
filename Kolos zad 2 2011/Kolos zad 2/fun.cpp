#include <iostream>
#include "class.h"

using namespace std;

int CTablica::liczba = 0;

void ustaw(CTablica *T, char C){
	if (T == NULL)
		cout << "parametr wskazuje wartosc NULL";
	else{
		for (int i = 0; i < T->getX(); i++)
			for (int j = 0; j < T->getY(); j++)
				T->tab[i][j] = C;
	}
	CTablica::liczba++;
}

CPosiadajacaDwaWymiary::CPosiadajacaDwaWymiary(int a, int b) :X(a), Y(b){}
int CPosiadajacaDwaWymiary::getX(){
	return this->X;
}
int CPosiadajacaDwaWymiary::getY(){
	return this->Y;
}

void CPosiadajacaDwaWymiary::print(){
	cout << this->X << " " << this->Y;
}

CTablica::CTablica(int X, int Y, char C) :CPosiadajacaDwaWymiary(X,Y){
	this->tab = new char*[X];
	for (int i = 0; i < X; i++)
		tab[i] = new char[Y];
	for (int i = 0; i < X; i++)
		for (int j = 0; j < Y; j++)
			tab[i][j] = C;
}

void CTablica::wysswietl(){
	for (int i = 0; i < this->getX(); i++)
	{
		for (int j = 0; j < this->getY(); j++)
		{
			cout << tab[i][j] << " ";
		}
		cout << endl;
	}
}
CTablica::~CTablica(){
	delete[] this->tab;
}