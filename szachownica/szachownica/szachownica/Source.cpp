#include <iostream>
//#include <stdio.h>
#include <iomanip>
#include <random>
#include <chrono> 

using namespace std;

/** wyswietla szachownice
*/
void showChessmate(int x, int y);
/** @param(in,out) x wspó³rzêdna x konia
	@param(in,out) y wspó³rzêdna y konia
*/
void move(int &x, int &y);

int main() {
	int x = 0; //pozycja
	int y = 0; //konia
	showChessmate(x, y);
	do {
		cin.ignore(300, '\n');
		move(x, y);
		showChessmate(x, y);
	} while (cin.get() != 'n');
}

void move(int &x, int &y) {
	bool moved = false;
	int random;
	do {
		default_random_engine engine;
		engine.seed(std::chrono::system_clock::now().time_since_epoch().count());
		uniform_int_distribution<int> distribution(1, 4);
		random = distribution(engine);
		//cout <<"x: "<< x << endl << "y: " << y << endl << "random: " << random<<endl;
		switch (random) {
		case 1:

			if ((y + 2 < 8) && (x - 1 >= 0)) {
				x -=1;
				y += 2;
				moved = true;
			}
			else if ((y + 2 < 8) && (x + 1 < 8)) {
				x += 1;
				y += 2;
				moved = true;
			}
			break;
		case 2:
			if ((y + 1 < 8) && (x + 2 < 8)) {
				x += 2;
				y += 1;
				moved = true;
			}
			else if ((y - 1 >= 0) && (x + 2 < 8)) {
				x += 2;
				y -= 1;
				moved = true;
			}
			break;
		case 3:
			if ((y - 2 >= 0) && (x + 1 < 8)) {
				x += 1;
				y -=2;
				moved = true;
			}
			else if ((y - 2 >= 0) && (x - 1 >= 0)) {
				x -= 1;
				y -= 2;
				moved = true;
			}
			break;
		case 4:
			if ((y + 1 < 8) && (x - 2 >= 0)) {
				x -= 2;
				y += 1;
				moved = true;
			}
			else if ((y - 1 >= 0) && (x - 2 >= 0)) {
				y -= 1;
				x -= 2;
				moved = true;
			}
				break;
		}
	} while (!moved);
}

void showChessmate(int x, int y) {
	for (int i = 0;i < 10;i++)
		cout << endl;
	cout << "x = " << x+1 << " y =" << y+1 << " ";
	cout << "Kontynuowac? y/n"<<endl;
	for (int i = 0;i < 8;i++) {
		for (int k = 0;k < 8;k++) {
			if ((i == y) && (k == x))
				cout <<setw(3)<< "O";
			else
				cout<< setw(3) << "[]";
		}
		cout << endl;
	}
	for (int i = 0; i < 10; i++)
		cout << endl;
}