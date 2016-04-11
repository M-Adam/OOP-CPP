#include <iostream>

using namespace std;

struct tablicaDoPosortowania {
	unsigned int *wyniki;
	unsigned int *proby;
	unsigned int iloscParDanych = 0;
	unsigned int ucietych = 0;
	bool trzebaSortowac = false;
};


void scal(tablicaDoPosortowania &tab){
	for (unsigned int i = 0; i < tab.iloscParDanych -1; i++){
		if (tab.wyniki[i] == tab.wyniki[i+1]){
			tab.proby[i+1] += tab.proby[i];
			tab.proby[i] = 0;
			tab.ucietych++;
		}
	}
}

void scal(tablicaDoPosortowania &wspolna, tablicaDoPosortowania &pierwsza, tablicaDoPosortowania &druga) {
	unsigned int p = 0, d = 0;
	wspolna.iloscParDanych = (pierwsza.iloscParDanych-pierwsza.ucietych) + (druga.iloscParDanych-druga.ucietych);

	for (unsigned int i = 0; i <= wspolna.iloscParDanych; i++)	{
		while (pierwsza.proby[p] == 0) 
			p++;
		while (druga.proby[d] == 0) 
			d++;

		if (pierwsza.wyniki[p] < druga.wyniki[d]) {
			wspolna.wyniki[i] = pierwsza.wyniki[p];
			wspolna.proby[i] = pierwsza.proby[p];
			p++;
		}
		else if (pierwsza.wyniki[p] > druga.wyniki[d]) {
			wspolna.wyniki[i] = druga.wyniki[d];
			wspolna.proby[i] = druga.proby[d];
			d++;
		}
		else if (pierwsza.wyniki[p] == druga.wyniki[d]) {
			wspolna.wyniki[i] = pierwsza.wyniki[p];
			wspolna.proby[i] = pierwsza.proby[p] + druga.proby[d];
			p++;
			d++;
			wspolna.iloscParDanych--;
		}

		if (p == pierwsza.iloscParDanych) {
			i++;
			while (d < druga.iloscParDanych){
				wspolna.wyniki[i] = druga.wyniki[d];
				wspolna.proby[i] = druga.proby[d];
				d++; i++;
			}
			return;
		}
		else if (d == druga.iloscParDanych) {
			i++;
			while (p < pierwsza.iloscParDanych)	{
				wspolna.wyniki[i] = pierwsza.wyniki[p];
				wspolna.proby[i] = pierwsza.proby[p];
				p++; i++;
			}
			return;
		}
	}
}

void sortujQuick(tablicaDoPosortowania &tab, int left, int right){
	long i = left, j = right;
	unsigned int temp, x = tab.wyniki[(left + right) >> 1];

	do	{
		while (tab.wyniki[i] < x)
			i++;

		while (tab.wyniki[j] > x)
			j--;

		if (i <= j)	{
			temp = tab.wyniki[i];
			tab.wyniki[i] = tab.wyniki[j];
			tab.wyniki[j] = temp;

			temp = tab.proby[i];
			tab.proby[i] = tab.proby[j];
			tab.proby[j] = temp;

			i++;
			j--;
		}
	} while (i <= j);

	if (left < j) 
		sortujQuick(tab, left, j);
	if (right > i) 
		sortujQuick(tab, i, right);
}

unsigned int szukaj(tablicaDoPosortowania &tab, unsigned int szukana){
	long sr, l = 0, p = tab.iloscParDanych - 1;

	while (l <= p)	{
		sr = ((l + p) >> 1);

		if (tab.wyniki[sr] == szukana)
			return tab.proby[sr];

		if (tab.wyniki[sr] > szukana)
			p = sr - 1;
		else
			l = sr + 1;
	}

	return 0;
}

void wyswietl(tablicaDoPosortowania &tab, tablicaDoPosortowania &szukane) {
	cout << tab.iloscParDanych-tab.ucietych << "\t";
	for (unsigned int i = 0; i < tab.iloscParDanych; i++)	{
		if (tab.proby[i] == 0) continue;
		cout << tab.wyniki[i] << " " << tab.proby[i] << " ";
	}

	for (unsigned int i = 0; i < szukane.iloscParDanych; i++)	{
		szukane.proby[i] = szukaj(tab, szukane.wyniki[i]);
	}

	cout << endl;
	for (unsigned int i = 0; i < szukane.iloscParDanych; i++)	{
		cout << szukane.proby[i] << " ";
	}
}



int main(){

	unsigned int iloscTablic;
	cin >> iloscTablic;
	tablicaDoPosortowania *T = new tablicaDoPosortowania[iloscTablic];
// Wejœcie
	for (unsigned int i = 0; i < iloscTablic; i++)	{
		cin >> T[i].iloscParDanych;

		T[i].wyniki = new unsigned int[T[i].iloscParDanych];
		T[i].proby = new unsigned int[T[i].iloscParDanych];

		cin >> T[i].wyniki[0];
		cin >> T[i].proby[0];
		bool sprawdzaj = true;
		for (unsigned int j = 1; j < T[i].iloscParDanych; j++)		{
			cin >> T[i].wyniki[j];
			cin >> T[i].proby[j];
			if (sprawdzaj) {
				if (T[i].wyniki[j] > T[i].wyniki[j - 1]) {
					T[i].trzebaSortowac = true;
					sprawdzaj = false;
				}
			}
		}
	}

	tablicaDoPosortowania szukane;
	cin >> szukane.iloscParDanych;
	szukane.wyniki = new unsigned int[szukane.iloscParDanych];
	szukane.proby = new unsigned int[szukane.iloscParDanych];
	for (unsigned int i = 0; i < szukane.iloscParDanych; i++)	{
		cin >> szukane.wyniki[i];
		szukane.proby[i] = 0;
	}

	for (unsigned int i = 0; i < iloscTablic; i++)	{
		if(T[i].trzebaSortowac)
			sortujQuick(T[i], 0, T[i].iloscParDanych - 1);
		scal(T[i]);
	}
// Wyjœcie
	for (unsigned int i = 0; i < iloscTablic; i++)	{
		cout << T[i].iloscParDanych - T[i].ucietych << "\t";
		for (unsigned j = 0; j < T[i].iloscParDanych; j++)
		{
			if (T[i].proby[j] == 0) continue;
			cout << T[i].wyniki[j] << " " << T[i].proby[j] << " ";
		}
		cout << endl;
	}

	tablicaDoPosortowania wspolna, temp;
	bool wyswietlWspolna = false;

	if (iloscTablic == 1) {
		wyswietl(T[0], szukane);
		delete[] T;
		return 0;
	}
	else if (iloscTablic == 2) {
		//ustawianie wspolnej
		for (unsigned int i = 0; i < iloscTablic; i++)
		{
			wspolna.iloscParDanych += T[i].iloscParDanych-T[i].ucietych;
		}
		wspolna.proby = new unsigned int[wspolna.iloscParDanych];
		wspolna.wyniki = new unsigned int[wspolna.iloscParDanych];

		//scalanie
		scal(wspolna, T[0], T[1]);
		wyswietlWspolna = true;
	}
	else {

		//ustawianie wspolnej
		wspolna.iloscParDanych = 0;
		for (unsigned int i = 0; i < iloscTablic; i++)	{
			wspolna.iloscParDanych += T[i].iloscParDanych;
		}
		wspolna.proby = new unsigned int[wspolna.iloscParDanych];
		wspolna.wyniki = new unsigned int[wspolna.iloscParDanych];

		//przepisanie t0 do temp
		temp.iloscParDanych = T[0].iloscParDanych;
		temp.proby = new unsigned int[wspolna.iloscParDanych];
		temp.wyniki = new unsigned int[wspolna.iloscParDanych];
		for (unsigned int i = 0; i < temp.iloscParDanych; i++)	{
			temp.wyniki[i] = T[0].wyniki[i];
			temp.proby[i] = T[0].proby[i];
		}

		//scalanie
		unsigned int i = 1;
		while (i<iloscTablic - 1)
		{
			scal(wspolna, temp, T[i]);
			scal(temp, wspolna, T[i + 1]);
			i += 2;
			if (i == iloscTablic - 1) {
				scal(wspolna, temp, T[i]);
				wyswietlWspolna = true;
			}
		}
	}

	delete[] T;

	if (wyswietlWspolna)
		wyswietl(wspolna, szukane);
	else
		wyswietl(temp, szukane);

	return 0;
}