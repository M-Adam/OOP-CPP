#include <iostream>
#include <string>

using namespace std;

class Stworek{
public:
	virtual void powiedz(string &) = 0;
};

class StworekJakajacy :public Stworek{
	void powiedz(string &a){
		cout << a[0] << a << endl;
	}
};

class StworekBezR :public Stworek{
	/* void powiedz(string &a){
		char * napis = new char[a.size() + 1];
		copy(a.begin(), a.end(), napis);
		napis[a.size()] = '\0';
		for (int i = 0;napis[i]; i++)
			if (napis[i] == 'r')
				napis[i] = 'l';
		for (int i = 0; i < napis[i]; i++)
			cout << napis[i];
		delete[] napis;
	}
	*/

	void powiedz(string &a){
		for (int i = 0; a[i]; i++) {
			if (a[i] == 'r'){
				cout << "l";
				i++;
			}
			else if (a[i] == 'R'){
				cout << "L";
				i++;
			}
			cout << a[i];
		}
		cout << endl;
	}
};

int main(){
	Stworek *wsk1, *wsk2;
	wsk1 = new StworekJakajacy();
	wsk2 = new StworekBezR();
	string a = "Jakis tekst", b = "RatatataraR ";
	wsk1->powiedz(a);
	wsk2->powiedz(b);
	return 0;
}