class CMacierz{
public:
	int ilWierszy, ilKolumn, **macierz;
	CMacierz(int, int);
	~CMacierz();
};

class CMacierzDodawanie :public CMacierz{
public:
	void Dodaj(CMacierz*);
	CMacierzDodawanie(int a, int b) :CMacierz(a, b){};
};

class CMacierzOdwrotna : public CMacierz{
public:
	void Transponuj();
	CMacierzOdwrotna(int a, int b) :CMacierz(a, b){};
};