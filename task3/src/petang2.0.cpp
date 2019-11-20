#include <iostream>
#include <string>
#include <vector>
#include <ctime> 
#include <cmath>
using namespace std;

const int START_MONEY = 500;

class Player {
private:
	int money;
	int bet;
	int difference;
	bool flag_in_zone;
	string name;



public:
	Player(): money(START_MONEY), bet(0), flag_in_zone(false){}

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

	void edit_difference(int x)
	{ difference = x; }
	int get_difference()
	{ return difference;}
	void edit_flag_zone(bool logic)
	{ flag_in_zone = logic; }
	bool get_flag_zone()
	{ return flag_in_zone; }


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
		if (x_diff <= width/2){
		cout << "Вы попали в зону!" << endl;
			return true;	//	win
		}
		else{
			cout << "Ваш мяч не попал в зону!" << endl;
			return false;	//	lose
		}
	}
	void print_coord(){
		cout << endl << "---------------------------------" << endl;
		cout << "координаты базы: (" << center_x-width/2 << "," << center_x+width/2 <<")" << endl;
		cout << "---------------------------------" << endl << endl;
	}	

};

class 	Game{
private:
	vector<Player> all_players;
public: 

	void init_players(){
		Player temp;
		string name = "";
		unsigned int n;
		cout << "Введите кол-во игроков:" << endl;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cout << "Введите имя игрока:" << endl;
			cin >> name;
			temp.add_name(name);
			all_players.push_back(temp);

		}		

	}
	void bets(){
		int temp;
		for (int i = 0; i < all_players.size(); i++){
			cout << all_players[i].get_name() << ", ваш баланс: " << all_players[i].get_money();
			cout << ". Ваша ставка?" << endl;
			cin >> temp;
			all_players[i].edit_bet(temp);
		}
		cout << endl;
		cout << "Ставки сделаны! Ставок больше нет." << endl << endl;

	}

	void set_angle_speed(Base& buf){
		Ball temp;

		int x;
		for (int i = 0; i < all_players.size(); i++){
			temp.edit_angle(all_players[i].what_angle());
			temp.edit_speed(all_players[i].what_speed());
			x = temp.distance();
			x = buf.get_difference(x);
			all_players[i].edit_difference(x);
			all_players[i].edit_flag_zone(buf.checker(x));

		}
	}
	int who_win(){
		int numb_win = 0;
		int min_diff = all_players[0].get_difference();
		for (int i = 0; i < all_players.size(); i++){
			if (all_players[i].get_flag_zone() == true){
				if (all_players[i].get_difference() < min_diff){
					min_diff = all_players[i].get_difference();
					numb_win = i;
				}

			}

		}
		return numb_win;
	}
	void end_game(int win_nubmer){
		for (int i = 0; i < all_players.size(); i++ ){
			if ( i != win_nubmer)
				all_players[i].lose();
			else all_players[i].win();
		}
	}

	vector<Player> get_all_players()
	{ return all_players; }


};

int main(){
	srand(time(NULL));

	Game play;
	Base base(rand()%100+1);


	for(int i = 0; i < play.get_all_players().size(); i++)
	{}
	play.init_players();
	base.print_coord();
	play.bets();
	play.set_angle_speed(base);
	play.end_game(play.who_win());


	


	return 0;
}