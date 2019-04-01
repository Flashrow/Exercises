#include <iostream>

using namespace std;

struct sDATA {
	int yyyy,
		mm,
		dd;
};

int main()
{	
	sDATA d1;
	d1.yyyy = 2000;
	cout << d1.yyyy;
    return 0;
}

