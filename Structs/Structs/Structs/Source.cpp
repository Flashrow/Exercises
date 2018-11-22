#include <iostream>
#include <iomanip> 
#include <random>

#include "Header.h"

using namespace std;

struct myPoint {
	double x, y, z;
	void setMyPoint(double x, double y, double z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	void printMyPoint() {
		cout << "x: " << this->x << endl;
		cout << "y: " << this->y << endl;
		cout << "z: " << this->z << endl;
	}
};

int main() {
	myPoint pointA;
	pointA.setMyPoint(3, 2, 4);
	cout << "Point A:" << endl;
	pointA.printMyPoint();

	myPoint pointB;
	pointB.setMyPoint(4, 3, 6);
	cout << endl << "Point B:" << endl;
	pointB.printMyPoint();

	cout << endl << "Distance between A and B: " << setprecision(3) << myPointDistance(pointA, pointB);

	return 0;
}


double myPointDistance(const myPoint & a, const myPoint & b) {
	return sqrt((a.x-b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) + (a.z - b.z)*(a.z - b.z));
}

vector<myPoint> generatePoints(const int N) {
	vector<myPoint> pointsVector;

	for (int i = 0; i < N; i++) {

	}

	return pointsVector;
}

