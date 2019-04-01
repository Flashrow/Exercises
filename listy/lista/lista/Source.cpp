#include <iostream>
#include <random>
#include <chrono>

#include "Header.h"

using namespace std;

struct element {
	int val;
	element * headNext;
};

int main(int argc, char * argv[]){

	element *head = nullptr;

	const int N = 10;
	default_random_engine engine;
	engine.seed(std::chrono::system_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> distribution(1, 50);
	for (int i = 0; i < N; i++) {
		addSorted(head, distribution(engine));
	}

	printList(head);
	cout << endl;

	//addSorted(head, 16);
	printList(head);

	cin.get();
	return 0;
}

void addToFront(element *& head, int value) {
		head = new element{ value, head };
}

void addSorted(element *& head, int value) {
	element * headB = head;
	if (head) {
		if(headB->val>=value)
			head = new element{ value, head };
		else
		while (headB->headNext) {
			if (headB->headNext->val >= value) {
				headB->headNext = new element{ value, headB->headNext };
				break;
			}
			headB = headB->headNext;
		}
		if(!headB->headNext)
		headB->headNext = new element{ value, nullptr };
	}
	else
		head = new element{ value, head };
}

void printList(element * head) {
	while (head) {
		cout << head->val << " ";
		head = head->headNext;
	}
}

/*void deleteElement(element * head, int value) {
	element * headB = head;
	if(head->val==value){
		delete(head);
		head
	}else
	while (head->headNext->val==value) {
		
	}
}*/