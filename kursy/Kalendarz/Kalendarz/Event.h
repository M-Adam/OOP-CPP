#include <iostream>


using namespace std;

class Event{
private:
	int year, month, day, hour, minute;
	string name;


public:
	Event(string="Armagjedon! :o", int=1994, int=2, int=3, int=6, int=66);
	~Event();

	void load();

	void show();
};