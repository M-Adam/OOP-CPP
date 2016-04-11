#include <iostream>
#include <string>

using namespace std;

class rachunek {
    private:
        string imie, nazwisko, numer_konta;
        double saldo;

	public:
	    rachunek(string a="Imie", double b=0){
            this->imie=a;
            this->saldo=b;
	    }
        void Dodaj(double a) {
            this->saldo+=a;
        }
        void Odejmij(double a) {
            this->saldo-=a;
        }
        double Saldo() {
            return this->saldo;
        }
        void Pokaz() {
            cout << "Saldo rachunku wynosi: " << this->saldo << endl
            << this->imie << endl;
        }
};


int main() {
	rachunek jeden();
	double suma, roznica;


	cin >> suma >> roznica;


	jeden.Dodaj(suma);
    jeden.Odejmij(roznica);
    jeden.Pokaz();
	cout << endl << "===========" << endl << jeden.Saldo() << endl;

    return 0;
}
