#include <iostream>
#include <string>
#include <vector>
#include <ctime>   // time
#include <cmath>
#include <thread>
//#include <graphics.h>
//#include <conio.h>

using namespace std;



class Ball{
 int x;
 int y;
public:
	Ball(int tx, int ty): x(tx), y(ty){}
	void show(){
		cout << "x=" << x << endl;
		cout << "y=" << y << endl;
	}
	~Ball() {
		cout << "я есть деструктор" << endl;

	}
};


int main(){
	auto unq = make_unique<Ball>(10,11);
	unq->show();

 return 0;


	}