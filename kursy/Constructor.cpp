#include <string>
#include <iostream>

using namespace std;

class Figura {
public:
    virtual int pole() const = 0;
}; //virtual, z ktorego biora wszystkie podklasy-kszta³ty. automatycznie sprawdza podklase obiektu i bierz funkjce pola z tej podklasy

class Rectangle : public Figura
{
public:
    Rectangle()
        : _width{}, _height{}
    {
        //instrukcje wykonywane przy stworzeniu obkiektu
    }

    Rectangle(int initial_width, int initial_height)
        : _width{initial_width}, _height{initial_height}
    {
        //instrukcje wykonywane przy stworzeniu obiektu z parametrami
    }

    void wyswietl() {
        cout << this->_width <<endl << this->_height<< endl;
    }

    int getWidth() { return this->_width; }
    int getHeight() { return this->_height; }

    void rozmiar(int nowaSzerokosc, int nowaWysokosc) {
        this->_width = nowaSzerokosc;
        this->_height = nowaWysokosc;
    }

    int pole() const {
        return this->_width * this->_height;
    }

private:
    int _width;
    int _height;
};

class InszyTrojkat : public Rectangle {
public:
    InszyTrojkat() { }
    InszyTrojkat(string nazwa, int szerokosc, int wysokosc)
        : Rectangle{szerokosc, wysokosc}, _nazwa{nazwa}
        {  }

    string getNazwa() const { return this->_nazwa; }

private:
    string _nazwa;
};

void potega (int& x) {
    x=x*x;
}//referencja, leci po adresie zmiennej

int policz_pole(const Figura& ksztalt)   {
    return ksztalt.pole();
} //referencja typu Figura, dobiera sie do funkcji Pole tej funkcji. sam se dobiera podklase

int main() {
    Rectangle trojkatA{5,2},trojkatB{};
    InszyTrojkat trojkatC{}, trojkatD{"Pitagoras", 5, 10};
    trojkatA.wyswietl();
    trojkatB.wyswietl();

    int x{5};
    int& xref{x}; //stworzenie referencji
    xref+=2;
    potega(x);
    cout << endl << x << endl;

    cout << trojkatD.getNazwa() << endl;

    cout << policz_pole(trojkatA);

    return 0;
}
