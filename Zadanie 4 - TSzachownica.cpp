#include <iostream>

using namespace std;

class TPionek{ };

class TSzachownica{
private:
	int a,b;
	TPionek **sz;
public:
	TSzachownica(int x, int y);
	TSzachownica(TSzachownica &);
	~TSzachownica();
};

TSzachownica::TSzachownica(int x, int y){
	this->a=x;
	this->b=y;
	this->sz = new TPionek*[x];
	for (int i=0; i<x; i++) {
		this->sz[i]=new TPionek[y];
	}
}

TSzachownica::TSzachownica(TSzachownica &abc){
	this->a=abc.a;
	this->b=abc.b;
	this->sz=new TPionek*[abc.a];
    for (int i=0; i<abc.a; i++){
		this->sz[i]=new TPionek[abc.b];
    }
}

TSzachownica::~TSzachownica(){
	for (int i=0; i < this->a; i++){
 		delete[] this->sz[i];
	}
	delete[] this->sz;

}

int main(){
    TSzachownica s1(5,3);
    string a = "asdasd";
return 0;
}
