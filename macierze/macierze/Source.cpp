#include <iostream>
#include <iomanip>
#include "Header.h"

using namespace std;

int main() {
	int m1[10][10] = {};
	int m2[10][10] = {};
	int m3[10][10] = {};
	int x = 0;
	int y = 0;

	setRozmiar(x, y);
	cout << "Macierz 1";
	initiateMacierz(m1,x,y);
	initiateMacierz(m2, x, y);
	cout <<"Macierz: "<< endl;
	printMacierz(m1, x, y);
	cout << endl << "obrocenie macierzy: " << endl;
	swapMacierz(m1, x, y);
	printMacierz(m1, x, y);
	cin.ignore();
	cin.get();
}
void initiateMacierz(int t[10][10], int x, int y) {
	for (int i = 0;i < y;i++) {
		for (int k = 0;k < x;k++) {
			cout << "Podaj M[" << i + 1 << "][" << k + 1 << "]: ";
			cin >> t[i][k];
		}
	}
	cin.clear();
	cin.sync();
}

void setRozmiar(int &x, int &y) {
	cout << "Podaj szerokosc(maks 10): ";
	do {
		cin >> x;
	} while (x > 10);
	cout << "Podaj wysokosc(maks 10): ";
	do {
		cin >> y;
	} while (y > 10);
	cin.clear();
	cin.sync();
}

void sumMacierz(int tsum[10][10], const int t1[10][10],const int t2[10][10]) {
	tsum = {};
	for (int i = 0;i < 10;i++)
		for (int k = 0; k < 10; k++)
			tsum[i][k] = t1[i][k] + t2[i][k];
}

void printMacierz(const int t[10][10],int x,int y){
	for (int i = 0;i < y ; i++) {
		for (int k = 0;k < x;k++) {
			cout << setw(3) << t[i][k];
		}
		cout << endl;
	}
}

void swapMacierz(int t[10][10], int x, int y) {
	int bMacierz[10][10] = {};
	for (int i = 0;i < x; i++) 
		for (int k = 0; k < y; k++) 
			bMacierz[i][k] = t[k][i];

	for (int i = 0;i < x; i++)
		for (int k = 0; k < y; k++)
			t[i][k] = bMacierz[i][k];
}