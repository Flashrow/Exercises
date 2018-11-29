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

	for (auto i : { 2,4,5,11,2,5,73,2 })
		addToFront(head, i);
	printFromStart(head);
	cout << endl;

	element *foundElement = findE(head, 11);

	cout << foundElement->value << endl;
	printFromStart(head);
	cout << endl;
	deleteElement(head, head);

	printFromStart(head);
	deleteList(head);
	deleteList(head);

	for (auto i : { 2,4,6,21,4,64,23,4,13,4 })
	addToFront(head, i);

	cout << endl << endl;
	printFromStart(head); cout << endl;
	deleteElements(head,4);
	printFromStart(head);
	cout << endl<<endl;

	swapList(head);
	printFromStart(head); cout << endl;
	swapList(head);
	printFromStart(head);
	cout << endl << endl;


	 cin.get();
	 return 0;
}

void addToFront(element *&head, T val) {
	head = new element {val, head};
}

void printFromStart(element *head) {
	while (head) {
		cout << head->value<<" ";
		head = head->pNext;
	}
}

int generateRandom() {
	default_random_engine engineR;
	engineR.seed(chrono::system_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> distribution(1, 100);
	return(distribution(engineR));
}

void addRandom(element *&head) {
	default_random_engine engineR;
	engineR.seed(chrono::system_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> distribution(1, 100);
	head = new element{ distribution(engineR), head };
}

void addSorted(element * & head, T val) {
	element * headB = head;
	if (head) {
		if (headB->value >= val)
			head = new element{ val, head };
		else
			while (headB->pNext) {
				if (headB->pNext->value >= val) {
					headB->pNext = new element{ val, headB->pNext };
					break;
				}
				headB = headB->pNext;
			}
		if (!headB->pNext)
			headB->pNext = new element{ val, nullptr };
	}
	else
		head = new element{ val, head };
}

//TODO
void addSortedReq(element *&head, T val) {
	if (head) {
		addSortedReq(head->pNext, val);
		if (head->value >= val) {
			element * newElement = new element{val,head->pNext};
			head->pNext = newElement;
		}		
	}
}

void printFromStartReq(element *head, std::ostream &ss) {
	if (head) {
		ss << head->value << " ";
		printFromStartReq(head->pNext, ss);
	}
}
void printFromEndReq(element *head, std::ostream &ss) {
	if (head) {
		printFromStartReq(head->pNext, ss);
		ss << head->value << " ";
	}
}

element *findE(element * head, int val){
	while (head) {
		if (head->value == val)
			return head;
		else
			head = head->pNext;
	}
	return nullptr;
}

//TODO
element *findEReq(element * & head, int val) {

	if (findEReq(head->pNext, val)->value == val)
		return head;
	else
		return nullptr;
}

void deleteElement(element *&head, element *toDelete) {
	element * headBefore = head;
	element * headB = head;
	if (head == toDelete) {
		head = headB->pNext;
		delete(headB);
	}else
	while (headB) {
		if (headB == toDelete) {
			headBefore->pNext = headB->pNext;
			delete(headB);
			break;
		}
		headBefore = headB;
		headB = headB->pNext;
	}
}

void deleteElement(element *&head, T val){
	element * headB = head;
	element * headBefore = head;
	if (head) {
		if (head->value == val) {
			head = headB->pNext;
			delete(headB);
		}
		else
		while (headB) {
			if (headB->value == val) {
				headBefore->pNext = headB->pNext;
				delete(headB);
				break;
			}
			headBefore = headB;
			headB = headB->pNext;
		}
	}
}

void deleteElements(element *&head, T val) {
	element * headB = head;
	if (head) {
		if (head->value == val) {
			head = headB->pNext;
			delete(headB);
		}
		headB = head;
		element * headBefore = head;
		while (headB) {
			if (headB->value == val) {
				headBefore->pNext = headB->pNext;
				delete(headB);
				headB = headBefore->pNext;
			}
			else {
				headBefore = headB;
				headB = headB->pNext;
			}
		}
	}
}

void deleteList(element *&head) {
	if (head) {
		deleteList(head->pNext);
		delete(head);
		head = nullptr;
	}
}

void swapList(element *&head) {
	element *headBefore = head;
	element *headB = head->pNext;
	head->pNext= nullptr;
	head = headB;
	while (head) {
		headB = head->pNext;
		head->pNext = headBefore;
		headBefore = head;
		head = headB;
	}
	head = headBefore;
}

void removeRepetition(element *&head) {

}