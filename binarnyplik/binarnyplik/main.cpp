#include <iostream>
#include <fstream>

#include "Header.h"

using namespace std;
int main() {
	ofstream ofile;
	ofile.open("lol.txt");
	makeFile(ofile);
	ofile.close();
}