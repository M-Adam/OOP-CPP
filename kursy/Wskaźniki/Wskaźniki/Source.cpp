#include <iostream>
#include <stdlib.h>

using namespace std;



class test{
private:
	int param;
	int *wsk;
	int *wsk2;

public:
	test(int a, int b, int c){
		this->param = a;
		this->wsk = new int(b);
		this->wsk2 = new int(c);
	}

	test(test &abc){
		this->param = abc.param;
		this->wsk = new int(*abc.wsk);

		// this->wsk2 = abc.wsk2;  
		//p³ytkie kopiowanie. Zostaje skopiowana wartosc wskaznika wraz z adresem.
		// ¯eby sprawdziæ dzia³anie, skasowaæ delete wsk2 z destruktora

		this->wsk2 = new int(*abc.wsk2); 
		//kopiowanie g³êbokie, zostaje stworzony nowy wskaŸnik o nowym adresie, z wartoœci¹ wy³uskan¹ z abc
	}

	void setParam(int a){
		this->param = a;
	}
	void setWsk(int a){
		*this->wsk = a;
	}
	void setWsk2(int a){
		*this->wsk2 = a;
	}

	int getParam(){
		return this->param;
	}
	int getWsk(){
		return *this->wsk;
	}
	int getWsk2(){
		return *this->wsk2;
	}

	void adresWsk1(){
		cout << endl << "Adres Wsk1 = " << this->wsk << endl; 
	}
	void adresWsk2(){
		cout << endl << "Adres Wsk2 = " << this->wsk2 << endl;
	}

	~test(){
		delete wsk;
		delete wsk2;
		cout << "skasowano" << endl;
	}

};

int main(){
	test t1(5, 7, 100);
	test t2(t1);

	cout << t1.getParam() << endl;
	cout << t1.getWsk() << endl;
	cout << t1.getWsk2() << endl;
	
	cout << t2.getParam() << endl;
	cout << t2.getWsk() << endl;
	cout << t2.getWsk2() << endl;

	t1.adresWsk1();
	t1.adresWsk2();
	t2.adresWsk1();
	t2.adresWsk2();


	cout << endl;
	return 0;
}

