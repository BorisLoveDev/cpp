#include <iostream>
#include <string>
#include <vector>
#include <ctime> 
#include <cmath>
using namespace std;

const int START_MONEY = 500;

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
	int get_money(){
		return money;
	}
	void edit_bet(int x){
		cout << name << ", ваш баланс:" << money << endl;
		while(x > money){
		cout << name << ", у Вас недостаточно денег для такой ставки! Заложите квартиру и повторите" << endl;
		cout << name << ", ваша ставка?" << endl;
		cin >> x;
		}
		while ((x < 0) || (x > money)){
		cout << name << ", ваш баланс:"<< money << ", неккоректная ставка! повторите ввод" << endl;//разные оповещения 
		cout << name << ", ваша ставка?" << endl;
		cin >> x;
		}
		bet = x;
	}
	string get_name()
	{return name;}
	void win(){
		edit_money(bet);
		cout << name << ", поздрявляем! Ваш баланс: " << money << endl;
	}
	void lose(){
		edit_money(-bet);

		cout << name << ", не отчаивайся! Ведь, твой баланс: " << money << endl;
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
private:			//	как пофиксить public
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
		cout << first.get_name() <<", баланс:" << first.get_money() << " ваша ставка?" << endl;
		cin >> bet;
		first.edit_bet(bet);
		cout << second.get_name() << ", ваша ставка?" << endl;
		cin >> bet;
		second.edit_bet(bet);
	

	}

	Player get_first(){
		return first;
	}

	Player get_second(){
		return second;
	}
	int get_ang(Player a){
		return a.what_angle();
	}


	int get_angle(Player one){
		return (one.what_angle());

	}

	int get_speed(Player one){
		return (one.what_speed());
	}
	Player who_win(bool entry1, int diff1, bool entry2, int diff2){

		if (entry1 == true && entry2 == false){
			first.win();
			second.lose();
			cout << "Победил:";
			return first;	
			}	
		else if (entry1 == false && entry2 == true){
			first.lose();
			second.win();
			cout << "Победил:";
			return second;
		}
		else if (entry1 == false && entry2 == false)
			cout << "Ничья!" << endl << "ставки возращены!" << endl;
		else if (entry1 == true && entry2 == true){
			if (diff1 > diff2){
				cout << "Победил:"; 
				return first;
			}
			else if (diff2 > diff1){
				first.lose();
				second.win();
				cout << "Победил:";
				return second;
			}
			else cout << "Ничья!" << endl << "ставки возращены!" << endl;
		}	
	}

};


int main(){
	srand(time(NULL));
	int differnce1;
	int difference2;
	int in_area1;
	int in_area2;
	Game play;

	while ((play.get_first().get_money() != 0) || (play.get_second().get_money() != 0)){	
	Ball ball;
	Base base(rand()%100+1);


	play.init_players();
	play.bets();
	base.print_coord();


	ball.edit_angle(play.get_first().what_angle());
	ball.edit_speed(play.get_first().what_speed());
	differnce1 = base.get_difference(ball.distance());
	in_area1 = base.checker(differnce1);
//в отдельные функцию + выравнивание 
	ball.edit_angle(play.get_second().what_angle());
	ball.edit_speed(play.get_second().what_speed());
	difference2 = base.get_difference(ball.distance());
	in_area2 = base.checker(difference2);


	cout << play.who_win(in_area1, differnce1, in_area2, difference2).get_name() << endl;
	}
}	
/* изменение баланса
ужасный листненг 
повыносить в функции или классы?
f после цифр зачем Максимов?
*/
