#include <iostream>

using namespace std;

class CPunkt{
private:
	float x, y;
public:
	CPunkt(){
		this->x = 0;
		this->y = 0;
	}
	CPunkt(float a, float b){
		this->x = a;
		this->y = b;
	}

	float getX(){
		return this->x;
	}
	float getY(){
		return this->y;
	}

	void setX(float a){
		this->x = a;
	}
	void setY(float a){
		this->y = a;
	}
};

int main(){
	CPunkt p1;
	p1.setX(5.0);
	p1.setY(2.5);

	cout << endl << "X = " << p1.getX() << endl << "Y = " << p1.getY() << endl;

	return 0;
}