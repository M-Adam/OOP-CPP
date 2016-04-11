#include <string>

using namespace std;

class Poczta{
private:
	string nadawca, odbiorca, temat, tresc;
public:
	void setNadawca(string);
	void setOdbiorca(string);
	void setTemat(string);
	void setTresc(string);
	string getNadawca();
	string getOdbiorca();
	string getTemat();
	string getTresc();
	void wypisz();
	void wprowadz();
};