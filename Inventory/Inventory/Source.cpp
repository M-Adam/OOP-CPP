//Create an application which manages an inventory of products.Create a product class which has a price, id, and quantity on hand.Then create an inventory class which keeps track of various products and can sum up the inventory value.

#include <iostream>

using namespace std;

class CProduct{
	public:
	double price;
	unsigned int id;
	int quantity;
public:
	CProduct(double p = 1.0, int q = 1){
		this->price = p;
		this->id = CProduct::ilosc;
		this->quantity = q;
		CProduct::ilosc++;
	}
	static int ilosc;
	void wyswietl(){
		cout << "cena " << this->price << endl << "ID " << this->id << endl << "ilosc w magazynie: " << this->quantity<< endl;
		cout << "ilosc produktow" << CProduct::ilosc << endl;
	}
	double getPrice(){ return this->price; }
	int getQuantity(){ return this->quantity; }
	unsigned int getID(){ return this->id;  }
};

class CInventory{
public:
	static double sumuj(CProduct **a){
		double suma = 0;
		for (int i = 0; i < CProduct::ilosc; i++)
			suma += a[i]->getPrice() * a[i]->getQuantity();
		return suma;
	}
	static int minQ(CProduct **a){
		int min = a[0]->getQuantity(), indeks = 0;
		for (int i = 1; i < CProduct::ilosc; i++)
		{
			if (a[i]->getQuantity() < min){
				min = a[i]->getQuantity();
				indeks = a[i]->getID();
			}
		}
		return indeks;
	}
	static int minP(CProduct **a){
		double min = a[0]->getPrice();
		int indeks = 0;
		for (int i = 1; i < CProduct::ilosc; i++)
		{
			if (a[i]->getPrice() < min){
				min = a[i]->getPrice();
				indeks = a[i]->getID();
			}
		}
		return indeks;
	}
	static double sumaID(CProduct **a, int di){
		return a[di]->getPrice()*a[di]->getQuantity();
	}
};

int CProduct::ilosc = 0;

int main(){
	int ile_chcesz = 5;
	CProduct **tablica = new CProduct*[ile_chcesz];
	
	for (int i = 0; i < ile_chcesz; i++)
		tablica[i] = new CProduct(i*5, 2*i);
	

	cout << CInventory::sumuj(tablica) << endl;
	cout << "Utworzono produktow: " << CProduct::ilosc << endl;
	cout << "Najmniej jest produktu o ID: " << CInventory::minQ(tablica) << endl;
	cout << "Najtañszy jest produkt o ID: " << CInventory::minP(tablica) << endl;
	cout << "Wartosc produktu o ID 2: " << CInventory::sumaID(tablica, 2) << endl;
	return 0;

}