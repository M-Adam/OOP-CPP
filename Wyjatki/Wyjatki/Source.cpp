#include <iostream>
#include <string>
using namespace std;

class test {
public:
	void wyjatek() throw(char);
};

void test::wyjatek() throw(char) {
	throw 'A';
}

int sprawdz(int a, int b) throw(int) {
	if (a == b) throw 88;
	else return -1;
}

double Dziel(double a, double b) throw(string) {
	if (b == 0) {
		string wyjatek = "dzielenie przez zero!";
		throw wyjatek;
	}
	return a / b;
}

int main() {
	test T;
	int a = 1, b = 1;

	try {
		sprawdz(a, b);
		Dziel(a, 0);
		T.wyjatek();
	}
	catch (int e) {
		cout << "wyjatek to: " << e << endl;
	}
	catch (string s) {
		cout << "string: " << s;
	}
	catch (char c) {
		cout << "z testu: " << c;
	}
	catch (...) {
		cout << "z³apa³o wsyzstko" << endl;
	}

	return 0;
}
