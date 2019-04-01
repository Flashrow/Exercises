#include <iostream>
#include <string>

using namespace std;

string imie;
int wiek;

int main() {
	cout<<"Obliczanie szczesliwego dnia" << endl << "Podaj imie: ";
	cin>>imie;

	do {
		cin.clear();
		cout << "Podaj wiek: ";
		cin.ignore(1, 'In');
		cin >> wiek;
	} while (cin.fail());

	cin.ignore(1, 'In');

	int suma= 0;
	
	for (int i = 0; i < imie.length();i++) {
		suma += (char)imie[i];
	}

	suma *= wiek;

	cout << endl;

	switch (suma % 7)
	{
	case 0:
		cout << "Szczesliwy dzien to poniedzialek";
		break;
	case 1:
		cout << "Szczesliwy dzien to wtorek";
		break;
	case 2:
		cout << "Szczesliwy dzien to sroda";
		break;
	case 3:
		cout << "Szczesliwy dzien to czwartek";
		break;
	case 4:
		cout << "Szczesliwy dzien to piatek";
		break;
	case 5:
		cout << "Szczesliwy dzien to sobota";
		break;
	case 6:
		cout << "Szczesliwy dzien to niedziela";
		break;
	}

	cin.get();
}