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
Napisz klasê CSrodekTransportu posiadaj¹c¹ publiczne czysto - wirtualne metody :

a.        void rozpocznij()
b.       void porusz()
c.        void zakoncz()
d.       void wyswietl()

Napisz klasê CSamochod dziedzicz¹c¹ publicznie po CSrodekTransportu, posiadaj¹c¹:
a.Prywatne pola int X, int Y – bêd¹ce wspó³rzêdnymi samochodu,
b.Metodê rozpocznij() ustawia wszystkie pola na zero i wyœwietla tekst „Ruszam”,
c.Metodê porusz() zwiêksza wspó³rzêdn¹ X o 10 i wspó³rzêdn¹ Y o 5,
d.Metodê zakoñcz() wyœwietla tekst „Parkujê”,
e.Metodê wyswietl() wypisuje na ekran wartoœci swoich pól klasy.
Napisz klasê CSamolot dziedzicz¹c¹ publicznie po CSrodekTransportu, posiadaj¹c¹:
a.Prywatne pola int X, int Y, int Z – bêd¹ce wspó³rzêdnymi samolotu,
b.Metodê rozpocznij() ustawia pola X, Y na zero, a pole Z na 1000 i wyœwietla tekst „Startuje”,
c.Metodê porusz() zwiêksza wspó³rzêdn¹ X o 100 i wspó³rzêdn¹ Y o 50,
d.Metodê zakoncz() ustawia wartoœæ Z na 0 oraz wyœwietla tekst „L¹dujê”,
e.Metodê wyswietl() wypisuje na ekran wartoœci swoich pól klasy.
W funkcji main() zadeklaruj tylko dwie zmienne : jedn¹ liczbê ca³kowit¹ i jeden wskaŸnik na CSrodekTransportu.Pobierz wartoœæ ca³kowit¹ od u¿ytkownika i je¿eli jest parzysta, to utwórz dynamicznie instancjê samochodu, w przeciwnym przypadku instancjê samolotu.Nastêpnie wywo³aj sekwencjê instrukcji : rozpocznij(), wyswietl(), porusz(), porusz(), wyswietl(), zakoncz(), wyswietl().Pamiêtaj o zwalnianiu pamiêci.
*/