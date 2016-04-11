#include <iostream>

class CPosiadajacaDwaWymiary{
protected:
	const int X;
	const int Y;
public:
	CPosiadajacaDwaWymiary(int , int);
	int getX();
	int getY();
	void print();
};

class CTablica :public CPosiadajacaDwaWymiary{
private:
	char** tab;
public:
	static int liczba;
	CTablica(int, int, char);
	~CTablica();
	friend void ustaw(CTablica*, char);
	void wysswietl();
	
};