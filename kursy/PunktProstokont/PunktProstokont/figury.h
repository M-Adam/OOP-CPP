#include <math.h>

const double pi = 3.14;
class Prostokont; //¿eby czy_nalezy wiedzialo, co to jest Prostokont

class Punkt{
private:
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

class Kolo :public Punkt{
public:
	Kolo(int a = 0, int b=0, int p = 1);
	double pole();
	double obwod();
protected:
	int r;
};

class Kula :public Kolo{
public:
	Kula(int p = 1);
	double objetosc();
};