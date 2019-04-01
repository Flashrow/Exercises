#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	int t[10][10] = {};//tablica
	int i = 0;   
	int k = 0;
	int direction = 0; //0 - w prawo, 1 - w dol, 2 - w lewo, 3 - w gore
	int counter = 0;
	
	while (counter < 100) {
		switch (direction % 4) {
		case 0: //w prawo
			if ((!t[i][k]) && (i < 10)) {
				t[i][k] = counter;
				counter++;
				i++;
			}
			else {
				direction++;
				i--;
				k++;
			}
			break;
		case 1: //w dol
			if ((!t[i][k]) && (k < 10)) {
				t[i][k] = counter;
				counter++;
				k++;
			}
			else {
				direction++;
				i--;
				k--;
			}
			break;
		case 2: //w lewo
			if ((!t[i][k]) && (i >= 0)) {
				t[i][k] = counter;
				counter++;
				i--;
			}
			else {
				direction++;
				i++;
				k--;
			}
			break;
		case 3: // w gore
			if ((!t[i][k]) && (k > 0)) {
				t[i][k] = counter;
				counter++;
				k--;
			}
			else {
				direction++;
				i++;
				k++;
			}
			break;
		}
	}

	for (int i = 0; i < 10;i++) {
		for (int k = 0;k < 10;k++)
			cout << setw(3) << t[k][i]<<" ";
		cout << endl<<endl;
	}


	cin.get();
	return 0;
}
