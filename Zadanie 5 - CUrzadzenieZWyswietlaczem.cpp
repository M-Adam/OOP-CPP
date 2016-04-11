#include <iostream>

using namespace std;

class CUrzadzenieZWyswietlaczem{
protected:
    int ile_pix_poziom, ile_pix_pion;
public:
    CUrzadzenieZWyswietlaczem(int a, int b);
    void wyswietl();
};

class CIPod:public CUrzadzenieZWyswietlaczem{
public:
    CIPod(int a, int b):CUrzadzenieZWyswietlaczem(a,b) { }
    void zagraj();
    void wcisnij_klawisz(int nr_klawisza);
};

class CIPaaad:public CIPod{
public:
    CIPaaad(int a, int b):CIPod(a,b){ }
    void wczytaj_tekst(char*);
};

CUrzadzenieZWyswietlaczem::CUrzadzenieZWyswietlaczem(int a, int b){
    this->ile_pix_poziom=a;
    this->ile_pix_pion=b;
}
void CUrzadzenieZWyswietlaczem::wyswietl(){
    cout << "Jestem wyswietlaczem o wymiarach: "<<this->ile_pix_poziom<<" x "<<this->ile_pix_pion<< endl;
}
void CIPod::zagraj(){
    cout << endl << "pip" << endl;
}
void CIPod::wcisnij_klawisz(int nr_klawisza){
    this->zagraj();
    cout << "Nacisnales klawisz o nr: " << nr_klawisza << endl;
}
void CIPaaad::wczytaj_tekst(char* napis){
    for (int i=0; napis[i]!=NULL; i++)
        this->wcisnij_klawisz(napis[i]);
}


int main()
{
    CIPaaad a(3,5);
    a.wczytaj_tekst("cos");

    return 0;
}
