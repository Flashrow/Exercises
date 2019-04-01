#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Header.h"

using namespace std;

const string IPATH = "studenci.txt";

struct Student {
	string nazwisko;
	vector<float> oceny;
	Student *pNext;
};



int main(int argc, char *argv[]) {
	return 0;
}


void odczytaj(Student *head, string filePath) {
	ifstream ifile;
	ifile.open(filePath);
	string name = "";
	int a;
	if(ifile.good())
		while (!ifile.eof()) {
			getline(ifile, name);
		//	while ();
		}
	ifile.close();
}

void add(Student *&head, std::string name, vector<float> oceny) {
	head = new Student{name, oceny, head};
}