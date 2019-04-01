#pragma once

struct el {
	int liczba;
	//char *napis;
	el *pop;
	el *nast;
};

void dodaj(el *&head, el *nowy);
void wypisz(el *head);
el *usunNajwiekszy(el *&head);
void testL(el *head);