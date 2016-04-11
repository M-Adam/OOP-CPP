#include <iostream>

using namespace std;

class Pytanie {
public:
	Pytanie();
	~Pytanie();

	void wczytaj();
	void zadaj_pytanie();
	void sprawdz();
	void setNr_pytania(int x);
	int getPunkt();
	
	static int getWynik();
private:
	string tresc, OdpA, OdpB, OdpC, OdpD;
	string poprawna, odpowiedz;
	int nr_pytania;
	int punkt;

	static int Wynik;
};