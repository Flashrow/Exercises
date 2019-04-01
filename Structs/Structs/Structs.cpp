#include <iostream>
#include <vector>
#include <string>

#include "structHead.h"

using namespace std;

struct structData {
	int yyyy,
		mm,
		dd;
};

struct structStudent {
	int id;
	string nazwisko;
	vector<double> oceny;
	enum zaliczenie {tak,nie};
	zaliczenie zal = nie;
	pair <double, structData> srednia;
};

int main()
{
	structStudent *studentWsk[7][15][35];
	/*
	structData d1;
	structData d2;
	initiateData(d2, 2000, 10, 10);
	initiateData(d1, 2000, 10, 10);
	printData(d1);
	printData(d2);
	if (equalData(d1, d2))
		cout << "equal";
	else
		cout << "not equal";
	cin.get();
	*/

	for (int i = 0; i < 7;i++)
		for (int k = 0;k < 15; k++)
			for (int s = 0;s < 35;s++) {
				studentWsk[i][k][s] = new structStudent;
			}
	printStudent(*studentWsk[1][1][1]);
	cin.get();
	return 0;
}

void initiateData(structData& d1, int y, int m, int d) {
	d1.yyyy = y;
	d1.mm = m;
	d1.dd = d;
}

void printData(const structData d1) {
	cout << d1.yyyy << " " << d1.mm << " " << d1.dd<<endl;
}

bool equalData(const structData d1, const structData d2) {
	if ((d1.yyyy == d2.yyyy) && (d1.mm == d2.mm) && (d1.dd == d2.dd))
		return true;
	else
		return false;
}


void setNazwisko(structStudent student) {
	cin >> student.nazwisko;
}

void printStudent(const structStudent student) {
	cout << "Informacje o studencie:" << endl;
	cout << "Id: " << student.id<<endl;
	cout << "Nazwisko: " << student.nazwisko<<endl;
	for (auto o: student.oceny)
		cout << o << ", ";
	switch (student.zal) {
	case structStudent::tak:
			cout << "zaliczone" << endl;
			break;
	case structStudent::nie:
		cout << "niezaliczone" << endl;
				break;
	}
	cout << "Srednia: " << get<0>(student.srednia);
}