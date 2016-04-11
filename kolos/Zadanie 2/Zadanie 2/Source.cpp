#include <iostream>

using namespace std;

class Array{
public:
	int *wsk,rozmiar;
public:
	Array(int a){
		this->wsk = new int[a];
		this->rozmiar = a;
	}
	Array(Array &a){
		this->rozmiar = a.rozmiar;
		this->wsk = new int[this->rozmiar];
		for (int i = 0; i < this->rozmiar; i++)
			this->wsk[i] = a.wsk[i];
	}
	~Array(){
		delete[] this->wsk;
	}
	bool index_ok(int indeks){
		if (indeks < this->rozmiar)
			return true;
		else
			return false;
	}
	int & at(int indeks){
		if (this->index_ok(indeks))
			return this->wsk[indeks];
	}

	void uzupelnij(int a, int indeks){
		this->wsk[indeks] = a;
	}
	void wypisz(){
		for (int i = 0; i < this->rozmiar; i++)
			cout << this->wsk[i] << endl;
	}

};

int main(){
	Array a(5);
	

	for (int i = 0, k=4; i < 5; i++, k+=4){
		a.uzupelnij(k, i);
	}

	a.wypisz();

	for (int i = 0; i < 5;i++)
		cout << &a.wsk[i] << endl;

	Array b(a);

	b.wypisz();
	for (int i = 0; i < 5; i++)
		cout << &b.wsk[i] << endl;

	cout << endl << endl<< a.at(8)<< endl;

	return 0;

}