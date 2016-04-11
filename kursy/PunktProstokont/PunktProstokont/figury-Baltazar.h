class Prostokont; //¿eby czy_nalezy wiedzialo, co to jest Prostokont

class Punkt{
protected:
	int x, y;
public:
	Punkt(int=0, int=0);
	int getX();
	int getY();
	void setX(int);
	void setY(int);

	friend void czy_nalezy(Punkt &, Prostokont &);
};

class Prostokont{
private:
	int wspX, wspY, szer, wys;
public:
	Prostokont(int=0, int=0, int=1, int=1);
	int getWspX();
	int getWspY();
	int getSzer();
	int getWys();
	void setWspX(int);
	void setWspY(int);
	void setSzer(int);
	void setWys(int);
	int pole();

	friend void czy_nalezy(Punkt &, Prostokont &);
};

class Kolo : Punkt{
public:
	Kolo(int = 0, int = 0, int = 1);
	double pole();
	double obwod();
private:
	int r;
	const double pi=3.14;
};