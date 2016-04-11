class CSrodekTransportu {
public:
	virtual void rozpocznij() = 0;
	virtual void porusz() = 0;
	virtual void zakoncz() = 0;
	virtual void wyswietl() = 0;

};

class CSamochod :public CSrodekTransportu {
private:
	int x, y;
public:
	void rozpocznij();
	void porusz();
	void zakoncz();
	void wyswietl();
};

class CSamolot :public CSrodekTransportu {
private:
	int x, y, z;
public:
	void rozpocznij();
	void porusz();
	void zakoncz();
	void wyswietl();
};





/*
Napisz klas� CSrodekTransportu posiadaj�c� publiczne czysto - wirtualne metody :

a.        void rozpocznij()
b.       void porusz()
c.        void zakoncz()
d.       void wyswietl()

Napisz klas� CSamochod dziedzicz�c� publicznie po CSrodekTransportu, posiadaj�c�:
a.Prywatne pola int X, int Y � b�d�ce wsp�rz�dnymi samochodu,
b.Metod� rozpocznij() ustawia wszystkie pola na zero i wy�wietla tekst �Ruszam�,
c.Metod� porusz() zwi�ksza wsp�rz�dn� X o 10 i wsp�rz�dn� Y o 5,
d.Metod� zako�cz() wy�wietla tekst �Parkuj�,
e.Metod� wyswietl() wypisuje na ekran warto�ci swoich p�l klasy.
Napisz klas� CSamolot dziedzicz�c� publicznie po CSrodekTransportu, posiadaj�c�:
a.Prywatne pola int X, int Y, int Z � b�d�ce wsp�rz�dnymi samolotu,
b.Metod� rozpocznij() ustawia pola X, Y na zero, a pole Z na 1000 i wy�wietla tekst �Startuje�,
c.Metod� porusz() zwi�ksza wsp�rz�dn� X o 100 i wsp�rz�dn� Y o 50,
d.Metod� zakoncz() ustawia warto�� Z na 0 oraz wy�wietla tekst �L�duj�,
e.Metod� wyswietl() wypisuje na ekran warto�ci swoich p�l klasy.
W funkcji main() zadeklaruj tylko dwie zmienne : jedn� liczb� ca�kowit� i jeden wska�nik na CSrodekTransportu.Pobierz warto�� ca�kowit� od u�ytkownika i je�eli jest parzysta, to utw�rz dynamicznie instancj� samochodu, w przeciwnym przypadku instancj� samolotu.Nast�pnie wywo�aj sekwencj� instrukcji : rozpocznij(), wyswietl(), porusz(), porusz(), wyswietl(), zakoncz(), wyswietl().Pami�taj o zwalnianiu pami�ci.
*/