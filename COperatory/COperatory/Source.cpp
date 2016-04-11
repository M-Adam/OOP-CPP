/*
Zadanie:
Stwórz klasê COperatory, która zawiera:
- prywatn¹ dynamiczn¹ tablicê liczb ca³kowitych
- publiczny konstruktor alokuj¹cy 10-elementow¹ tablicê i zeruj¹cy j¹,
- publiczny destruktor usuwaj¹cy tablicê,
- publiczny operator +, który dodaje odpowiednie elementy w tablicach obu parametrów i zwraca to w nowym obiekcie,
- publiczny operator [], który zwraca wartoœæ komórki o indeksie zadanym parametrem (funkcja zwraca 0, je¿eli indeks jest spoza
zakresu tablicy)
- operator == który zwraca prawdê gdy odpowiadaj¹ce sobie komórki w tablicach s¹ równe, fa³sz w p. p.
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

    // konstruktor kopiujacy potrzebny, ¿eby operatory dzia³a³y
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
