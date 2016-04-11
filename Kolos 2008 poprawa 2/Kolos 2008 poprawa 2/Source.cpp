#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;


void RysujAscii(int **M, int W, int K){
	
	fstream plik;
	plik.open("plik.txt", ios::out | ios::app);
	if (!plik.good()){
		cout << "Nie udalo sie otworzyc pliku" << endl;
		exit(0);
	}

	
	for (int i = 0; i < W; i++)
	{
		for (int j = 0; j < K; j++)
		{
			if (M[i][j] == 0) {
				cout << ' ';
				plik << ' ';
			}
			else if (M[i][j] == 1){
				cout << '*';
				plik << '*';
			}
			else{
				cout << '#';
				plik << '#';
			}
		}
		cout << endl;
		plik << endl;
	}
	
	plik << endl << endl;

	plik.close();
}


int main(int argvc, char *argv[]){
	int pierwsza[2][3]={
		{ 1, 0, 2 },
		{ 1, 0, 2 } 
	};
	int druga[2][5]={
		{ 0, 1, 2, 1, 0 },
		{ 2, 1, 0, 1, 2 }
	};
	int trzecia[5][5]={
		{1, 0, 0, 0, 1 },
		{0, 1, 0, 1, 0 },
		{0, 0, 2, 0, 0 },
		{0, 1, 0, 1, 0 },
		{1, 0, 0, 0, 1 }
	};

	
	int **wp = new int*[2];
	for (int i = 0; i < 2; i++)
	{
		wp[i] = new int[3];
	}
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			wp[i][j] = pierwsza[i][j];


	int **wd = new int*[2];
	for (int i = 0; i < 2; i++)
	{
		wd[i] = new int[5];
	}
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 5; j++)
			wd[i][j] = druga[i][j];

	int **wt = new int*[5];
	for (int i = 0; i < 5; i++)
	{
		wt[i] = new int[5];
	}
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			wt[i][j] = trzecia[i][j];

	
	
	if (argvc == 2){
		if (argv[1][0] == 'a' || argv[1][0] == 'A')
			RysujAscii(wp, 2, 3);
		else {
			if (argv[1][0] == 'b' || argv[1][0] == 'B')
				RysujAscii(wd, 2, 5);
			else
				RysujAscii(wt, 5, 5);
		}
	}
	else
		RysujAscii(wt, 5, 5);

	RysujAscii((int **)pierwsza, 2, 3);
	
	return 0;
}