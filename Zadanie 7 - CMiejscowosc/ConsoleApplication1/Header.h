class CMiejscowosc{
private:
	static int liczbaLudzi;
public:
	static void dodajCzlowieka();
	void wyswietl();
};

class CCzlowiek{
protected:
	int waga;
public:
	CCzlowiek(int);
	int getWaga();
};

class CUfok:public CCzlowiek{
private:
	int zielonosc;
public:
	CUfok(int, int);
	int getZielonosc();
};