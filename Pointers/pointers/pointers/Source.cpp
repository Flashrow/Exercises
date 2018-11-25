#include <iostream>

#include "Header.h"

using namespace std;

int main(int argc, char * argv[]) {
	//pointer to integeer var
	int intVariable;
	int * a = & intVariable;

	//pointer to function returning bool, without parameters
	bool(*retTrue) ();
	retTrue = & is_good;
	if (!retTrue)
		cout << "works"<<endl;
	else
		cout << "false"<<endl;

	//pointer to function revert()
	void(* revertPtr) (int [], const int);
	revertPtr = & revert;
	const int N = 5;

	int t[N] = { 0,1,2,3,4 };
	printTab(t, N);
	revertPtr(t, N);
	printTab(t, N);

	//array of pointers to function revert()
	const int M = 3;
	void(*revertPtrArr[M]) (int[], const int);
	for (int i = 0; i < M; i++) {
		revertPtrArr[i] = &revert;
	}
	cout << endl;
	for (int i = 0; i < M; i++) {
		revertPtrArr[i](t, N);
		printTab(t, N);
	 }
	cout << endl;

	functionF(M, revertPtrArr, t, N);


	cin.get();
	return 0;
}

bool is_good() {
	return true;
}

void revert(int tab[], const int SIZE) {
	int tmp;
	for (int i = 0; i < SIZE / 2; i++)
	{
		tmp = tab[i];
		tab[i] = tab[SIZE - i - 1];
		tab[SIZE - i - 1] = tmp;
	}
}

void printTab(int tab[], const int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		cout << *(tab + i) << " ";
	}
	cout << endl;
}

void functionF(const int N, void(*f[])(int[], const int), int t[], const int W) {
	for (int i = 0; i < N; i++) {
		f[i](t, W);
		printTab(t, W);
	}

}