#include <iostream>

#include "Header.h"

using namespace std;

int main() {
	el *head = nullptr;
	for (auto i:{3, 6, 1, 9, 10, 4, 7, 2, 8, 10}) {
		el *nowy = new el{ i,nullptr,nullptr };
		dodaj(head, nowy);
	}
	testL(head);
	cout << endl << endl;
	
	el *glowa = nullptr;
	
	while (head) {
		dodaj(glowa, usunNajwiekszy(head));
	}
	wypisz(glowa);
	cin.get();
return 0;
}