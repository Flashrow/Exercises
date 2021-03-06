#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
	int lettersCount[26] = {};
	string arg;
	for (int i = 1; i < argc; i++) {
		arg = argv[i];
		for (auto &c : arg) {
			c = toupper(c);
			if(c>64&&c<91)
			lettersCount[c-65]++;
			else
			{
				cout << "Exception: Wrong input";
					return 1;
			}
		}
		cout << arg << endl;
	}
	
	cout << endl<<"Ilosc liter: "<<endl;

	for (int i = 0; i < 26; i++) {
		if (lettersCount[i]) {
			cout << (char)(i + 65) << ": " << lettersCount[i] << endl;
		}
	}

return 0;
}
