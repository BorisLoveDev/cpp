#include <iostream>
#include <cstdlib>	//	for srand()
#include <ctime>	//	чтоб задать ядро рандома
#include <unistd.h>	//	for sleep
//#include <conio.h>
#define DEAD 0
#define ALIVE 1
#define OFF 0
#define ON 1
#define NO 0
#define YES 1
#define w_min 5
#define h_min 1000
#define d_min 11


using namespace std;

class Flower {
private:
	bool flag_life;
	bool flag_lighted;
public:
	Flower(): flag_life(ALIVE), flag_lighted(OFF){}

	void set_flag_life(bool flag){
		flag_life = flag;
	}
	void set_flag_lighted(bool light){
		flag_lighted = light;
	}

	void check_flag_lighted(bool sun, bool lamp){
		if (sun == ON){
			flag_lighted = YES;
		}
		else if ( (sun == OFF) && (lamp == ON) ){
			flag_lighted = YES;
		}
		else{
		 flag_lighted = NO;
		}

	}

	void try_dead(){
		if (flag_lighted == NO){
			flag_life = DEAD;
			cout << "Цветок погиб!" << endl;
		
		}
	
		
	}
	bool get_flag_lighted(){
		return flag_lighted;
	}

	void print_status(){
		cout << "ЦВЕТОК: ";
		flag_life == ALIVE ? cout << "ЖИВ" : cout << "МЕРТВ";
		cout << endl;
	}
};

class Lamp{
private:
	bool mode;
public:
	Lamp(): mode(OFF){};

	void set_mode(bool tmp){
		mode = tmp;
		tmp == ON ? cout << "ЛАМПА ВКЛ." : cout << "ЛАМПА ВЫКЛ.";
		cout << endl;
	}

	bool get_mode(){
		return mode;
	}

	void print_status(){
		cout << "ЛАМПА:" << endl;
		mode == ON ? cout << "ВКЛЮЧЕНА" : cout << "ВЫКЛЮЧЕНА";
		cout << endl;
	}

};

class Cloud{
private:
	int width;
	int height;
	int distance;
public:
	Cloud(int w, int h, int d): width(w), height(h), distance(d){};
	void set_width(int w){
		width = w;
	}
	void set_height(int h){
		height = h;
	}
	void set_distance(int d){
		distance = d;
	}

	void print_status(){
		cout << "ТУЧА(";
		cout << distance << ":" << distance + width << ")" << endl;
	}

	void step(){
		if ( (distance + width) < 0)
			cout << "Туча прошла!" << endl;
		distance--;
	}

	int get_width(){
		return width;
	}

	int get_distance(){
		return distance;
	}

	int get_height(){
		return height;
	}
};

class Detector{
private:
	bool flag_cross;
	const int base_width = 3;
	const int delay = 1;
public:
	void set_flag_cross(bool tmp){
		flag_cross = tmp;
	}

	bool checker(int distance, int width){
		distance -= delay;
		if (distance <= base_width){
			cout << "Тучка закрыла солнце!" << endl;
			return ON;
		}
		else {
		 return OFF;
		//cout << "на небе не тучки" << endl;
		}


	}
};


int main(){
	Detector detector;
	Flower flower;
	Lamp lamp;


	srand(time(NULL));
	int width = (rand()%12) + w_min;
	int height = (rand()%1000) + h_min;
	int distance = (rand()%30) + d_min;
	Cloud cloud(width, height, distance);

	while(1){
	flower.print_status();
	cloud.print_status();
	lamp.set_mode(detector.checker(cloud.get_distance(), cloud.get_width()));
	//lamp.print_status();

	bool flag_sun, flag_lamp;
	flag_sun = !detector.checker(distance, width);
	flag_lamp = lamp.get_mode();
	flower.check_flag_lighted(flag_sun, flag_lamp);
	flower.try_dead();
	cloud.step();
	getchar();

	// sleep(1);
}

	return 0;
}
