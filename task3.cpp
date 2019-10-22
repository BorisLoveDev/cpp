#include <iostream>
#include <string>
#include <vector>
#include <ctime> 
#include <cmath>
using namespace std;

const int START_MONEY = 1000;

class Player {
private:
	int money = START_MONEY;
	int bet = 0;
	string name;


public:
	void add_name(string str){
		name = str;
	}
	void edit_money(int temp){
		money = money + temp; 

	}
	void edit_bet(int x){
		bet = x;
	}
	string get_name()
	{return name;}
	void win(){
		edit_money(bet);
	}
	void lose(){
		edit_money(-bet);
	}
	int what_angle(){
		int angle;
		cout << name << ", введите угол: " << endl;
		cin >> angle;
		return angle;
	}
	int what_speed(){
		int speed;
		cout << name << ", введите скорость:" << endl;
		cin >> speed;
		return speed;
	}

	};

class Ball {
private: 
	int pos_x = 0;
	int pos_y = 0;
	int speed;
	int angle;
public:
	void edit_speed(int temp){
		speed = temp;
	}
	void edit_angle(int x){
		angle = x;
	}
	int distance(){
		int x;
		double agl;
		agl = sin(2*angle*M_PI/180);
		x = speed*speed*agl/2;
		cout << "Вы швырнули мяч на:" << x << endl;
		return x;
	}
};

class Base {
private:
	const int width = 8;	//	ширина
	int center_x;
	int center_y = 0;

public:
	Base(int temp): center_x(temp)
	{}

	int get_difference(int distance){
		int difference;
		difference = abs(center_x - distance);
		return difference;
		}
	bool checker(int x_diff){
		if (x_diff <= width/2)
			return true;	//	win
		else
			return false;	//	lose
	}
	void print_coord(){
		cout << "координаты базы: (" << center_x-width/2 << "," << center_x+width/2 <<")" << endl;
	}	

};

class Game {
public:			//	как пофиксить public
	Player first;
	Player second;

public:
	void init_players(){
		string name1, name2;
		cout << "Введите имя первого игрока:" << endl;
		cin >> name1;
		cout << "Введите имя второго игрока:" << endl;
		cin >> name2;
		first.add_name(name1);
		second.add_name(name2);
	}
	void bets(){
		int bet;
		cout << first.get_name() << ", ваша ставка?" << endl;
		cin >> bet;
		first.edit_bet(bet);
		cout << second.get_name() << ", ваша ставка?" << endl;
		cin >> bet;
		second.edit_bet(bet);

	}
	int who_win(bool entry1, int diff1, bool entry2, int diff2){
		cout <<"1 попал?" << entry1 <<" растояние---" << diff1 << endl;
		cout <<"1 попал?" << entry2 <<" растояние---" << diff2  << endl;

		if (entry1 == true && entry2 == false)
			return 1;		
		else if (entry1 == false && entry2 == true)
			return 2;
		else if (entry1 == false && entry2 == false)
			return 0;
		else if (entry1 == true && entry2 == true){
			if (diff1 > diff2)
				return 1;
			else if (diff2 > diff1)
				return 2;
			else return 0;
		}	
	}

};


int main(){
	srand(time(NULL));
	int differnce1;
	int difference2;
	int in_area1;
	int in_area2;
	Ball ball;
	Base base(rand()%100+1);
	Game play;

	play.init_players();
	play.bets();
	base.print_coord();

	ball.edit_angle(play.first.what_angle());
	ball.edit_speed(play.first.what_speed());
	differnce1 = base.get_difference(ball.distance());
	in_area1 = base.checker(differnce1);

	ball.edit_angle(play.second.what_angle());
	ball.edit_speed(play.second.what_speed());
	difference2 = base.get_difference(ball.distance());
	in_area2 = base.checker(difference2);


	cout << "Победил игрок №" << play.who_win(in_area1, differnce1, in_area2, difference2) << endl;

}	
/* не кооректно выводит 
проверить как вычисляются значения
ужасный листненг 
паблик пофиксить
повыносить в функции или классы?
