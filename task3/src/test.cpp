#include <iostream>
#include <string>
#include <vector>
#include <ctime>   // time
#include <cmath>
#include <thread>
//#include <graphics.h>
//#include <conio.h>

using namespace std;



void thr_fun(){
	int i = 0;
	while (i < 10)
	cout << "Привет, из другого потока!\n" << i << endl;
}



int main(){
	
thread thr(thr_fun);

thr.join();

 return 0;


	}