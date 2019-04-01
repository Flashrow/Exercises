#include <iostream>

#include "Header.h"

void dodaj(el *&head, el *nowy) {
	if (!head)
		head = nowy;
	else {
		nowy->nast = head;
		head->pop = nowy;
		head = nowy;
	}
}

void wypisz(el *head) {
	if (head) {
		std::cout << head->liczba << " ";
		wypisz(head->nast);
	}
}

void testL(el *head) {
	while (head->nast) {
		std::cout << head->liczba << " ";
		head = head->nast;
	}
	std::cout <<head->liczba << std::endl;

	while (head) {
		std::cout << head->liczba << " ";
		head = head->pop;
	}
}

el *usunNajwiekszy(el *&head) {
	el *headB = head;
	el *headMax = nullptr;
	int valMax = 0;
	while (headB) {
		if (headB->liczba > valMax) {
			valMax = headB->liczba;
			headMax = headB;
		}
		headB = headB->nast;
	}

	if (headMax == head) {
		head = head -> nast;
	}
	else if (!headMax->nast) {
		headMax->pop->nast = nullptr;
	}
	else {
		headMax->pop->nast = headMax->nast;
		headMax->nast->pop = headMax->pop;
	}

	headMax->pop = nullptr;
	headMax->nast = nullptr;

	return headMax;
}