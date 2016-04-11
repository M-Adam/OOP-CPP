#include <iostream>
using namespace std;

void Fib(unsigned int, unsigned int);

int main(){
	unsigned int index, size;
	
	cin >> index;
	if (index <= 1)
		cout << index;
	else if (index <= 10000)
		size = 3000;
	else if (index <= 75000)
		size = 12000;
	else
		size = 30000;

	Fib(index, size);

	return 0;
}

void Fib(unsigned int index, unsigned int size) {
	bool notFirstRun = false;
	short *first = new short[size],
		*second = new short[size],
		*result = new short[size];
		
	for (int i = 0; i < size; i++) {
		first[i] = 0;
		second[i] = 0;
		result[i] = 0;
	}
	second[size - 1] = 1;

	while (index > 1) {
		if(notFirstRun)
			for (int i = 0; i < size; i++){
				first[i] = second[i];
				second[i] = result[i];
				result[i] = 0;
			}
		
		for (int i = size - 1; i >= 0; i--){
			if (first[i] + second[i] + result[i] > 9){
				result[i] += (first[i] + second[i]) - 10;
				result[i - 1] += 1;
			}
			else 
				result[i] += (first[i] + second[i]);
		}

		notFirstRun = true;
		index--;
	}

	for (int i = 0; i < size ; i++)	{
		if (result[i] != 0) {
			for (int j = i; j < size; j++)
				cout << result[j];
			return;
		}
	}

	delete[] first, second, result;
}