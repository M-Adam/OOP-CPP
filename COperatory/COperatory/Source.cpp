/*
Zadanie:
Stw�rz klas� COperatory, kt�ra zawiera:
- prywatn� dynamiczn� tablic� liczb ca�kowitych
- publiczny konstruktor alokuj�cy 10-elementow� tablic� i zeruj�cy j�,
- publiczny destruktor usuwaj�cy tablic�,
- publiczny operator +, kt�ry dodaje odpowiednie elementy w tablicach obu parametr�w i zwraca to w nowym obiekcie,
- publiczny operator [], kt�ry zwraca warto�� kom�rki o indeksie zadanym parametrem (funkcja zwraca 0, je�eli indeks jest spoza
zakresu tablicy)
- operator == kt�ry zwraca prawd� gdy odpowiadaj�ce sobie kom�rki w tablicach s� r�wne, fa�sz w p. p.
*/



#include <iostream>

using namespace std;

class COperatory {
private:
	int *tab;
public:
	COperatory() {
		this->tab = new int[10];
		for (int i = 0;i < 10;i++)
			this->tab[i] = 0;
	}

    // konstruktor kopiujacy potrzebny, �eby operatory dzia�a�y
	COperatory(COperatory &a) {
		this->tab = new int[10];
		for (int i = 0; i<10; i++)
			this->tab[i] = a.tab[i];
	}

	~COperatory() {
		delete[] this->tab;
	}

	COperatory operator+(COperatory &a){
		COperatory nowy;
		nowy.tab = new int[10];
		for (int i = 0;i < 10;i++)
			nowy.tab[i] = this->tab[i] + a.tab[i];
		return nowy;
	}

	int& operator[](int a){
		if ((a >= 0) && (a < 10))
			return this->tab[a];
		else
			return this->tab[0];
	}

	bool operator==(COperatory &a){
		for (int i = 0; i < 10; i++)
		{
			if (this->tab[i] != a.tab[i])
				return false;
		}
		return true;
	}

	//dodatkowo operatory przypisania, inkrementacji i postiknrementacji

	COperatory& operator ++() {
		for (int i = 0; i<10; i++)
			this->tab[i]++;
		return *this;
	}

	COperatory& operator ++(int a) {
		COperatory nowy(*this);
		++(*this);
		return nowy;
	}


	COperatory operator=(COperatory &a) {
		for (int i = 0; i < 10; i++)
			this->tab[i] = a.tab[i];

		return *this;
	}
};

int main() {
	COperatory a, b;

	if (a == b) cout << "rowne";
	a[3]++;
	++a;
	b = a;
	cout << a[3] << " " << b[3];


	cout << endl;
	return 0;
}
