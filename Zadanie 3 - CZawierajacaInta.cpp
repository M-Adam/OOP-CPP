#include <iostream>
#include <stdlib.h>

using namespace std;



class CZawierajacaInta{
private:
	int *wsk;

public:
	CZawierajacaInta(){
		this->wsk = new int;
	}

	CZawierajacaInta(CZawierajacaInta &abc){
		this->wsk = new int(*abc.wsk);
	}

	~CZawierajacaInta(){
		delete this->wsk;
	}

	void setWsk(int a){
		*this->wsk = a;
	}

	void wyswWartosc(){
		cout << endl << *this->wsk << endl;
	}
	void wyswAdres(){
		cout << endl << this->wsk << endl;
	}
};

int main(){
	CZawierajacaInta a1;

	a1.setWsk(5);

	CZawierajacaInta a2=a1;

	a1.wyswWartosc();
	a1.wyswAdres();
	a2.wyswWartosc();
	a2.wyswAdres();
	cout << endl;
	return 0;
}

