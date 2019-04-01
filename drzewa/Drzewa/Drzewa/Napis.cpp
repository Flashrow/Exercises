#include <iostream>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "Header.h"

using namespace std;

int main(int argc, char *argv[]) {
	Napis *root = nullptr;
	dodaj(root, "Kasia");
	dodaj(root, "Ania");
	dodaj(root, "Basia");
	dodaj(root, "Roman");
	wypisz(root);

	usun(root);
	cin.get();
	_CrtDumpMemoryLeaks();
	return 0;
}