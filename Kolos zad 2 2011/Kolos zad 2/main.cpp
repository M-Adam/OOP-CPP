#include <iostream>
#include "class.h"

using namespace std;

int main(){
	CTablica *T1 = new CTablica(5, 5, 'x'),
		*T2 = new CTablica(6, 7, 'y'),
		*T3 = new CTablica(1, 2, 'z'),
		*T4 = new CTablica(1, 1, 'k'), 
		*T5 = new CTablica(2, 2, 'l'),
		*T6 = new CTablica(8 ,7 ,'x');
	
	ustaw(T1, 'A');
	ustaw(T2, 'B');
	ustaw(T3, 'D');
	ustaw(T4, 'E');
	ustaw(T5, 'K');

	
	T2->wysswietl();
	
	cout << endl << CTablica::liczba << endl;
	delete T1, T2, T3, T4, T5;
	return 0;
}