#pragma once
struct Napis {
	char *nap;
	Napis *prawy;
	Napis *lewy;
};

void dodaj(Napis *&korzen, const char *n);
void wypisz(Napis *korzen);
void usun(Napis *&korzen);
