#include <cstring>
#include <string>
#include <iostream>

#include "Header.h"

void dodaj(Napis *&korzen,const char *n) {
	if (!korzen) {
		korzen = new Napis{ nullptr,nullptr, nullptr };
		korzen->nap = new char[strlen(n) + 1];
		strcpy_s(korzen->nap, strlen(n) + 1, n);
	}
	else 
		if (strcmp(n, korzen->nap)==-1)
			dodaj(korzen->lewy, n);
		else
			dodaj(korzen->prawy, n);
}



void wypisz(Napis *korzen) {
	if (korzen) {
		wypisz(korzen->lewy);
		std::cout << korzen->nap << std::endl;
		wypisz(korzen->prawy);
	}
}

void usun(Napis *&korzen) {
	if (korzen) {
		usun(korzen->lewy);
		usun(korzen->prawy);
		delete [] korzen->nap;
		delete korzen;
		korzen = nullptr;
	}
}