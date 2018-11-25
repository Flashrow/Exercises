#include <iostream>
#include <string>
#include <random>
#include <chrono>

#include "Header.h"

using namespace std;

struct element{
	int value;
	element * pNext;
};

int main(int argc, char *argv[]) {

	element * head = nullptr;

	//for (int i = 0; i < 10; i++)
	//	addRandom(head);

	for (auto i : { 1,3,4,6,8,11 })
		addToFront(head, i);
	printFromStart(head);
	cout << endl;

	addSorted(head, 5);
	printFromStart(head);

	 cin.get();
	 return 0;
}

void addToFront(element * &head, int v) {
	head = new element {v, head};
}

void printFromStart(element * head) {
	while (head) {
		cout << head->value<<" ";
		head = head->pNext;
	}
}

void addRandom(element * &head) {
	default_random_engine engineR;
	engineR.seed(chrono::system_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> distribution(1, 100);
	head = new element{ distribution(engineR), head };
}

void addSorted(element * & head, T val) {
	element * headBefore = head;
	if (head)
		while (headBefore->pNext) {
			if (headBefore->pNext->value <= val) {
				headBefore->pNext = new element{ val, headBefore->pNext };
				break;
			}
			headBefore = headBefore->pNext;
		}
	else
		addToFront(head, val);
}

void addSortedReq(element * & head, T val) {
	if (head) {
		if(head->value>=val)
		addSortedReq(head->pNext, val);
	}

}