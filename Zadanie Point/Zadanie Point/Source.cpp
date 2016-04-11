#include <iostream>
#include <string>
#include "point.h"

using namespace std;

int main(){

	point a(1, 1, 1), b(2, 2, 2), c(-1, -1, -1);
	if (a == c) cout << "rowne" << endl;
	if (b>a) cout << "wieksze" << endl;
	if (c<b) cout << "mniejsze" << endl;
	
	return 0;
}