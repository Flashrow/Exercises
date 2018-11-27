#pragma once
#ifndef HEADER_H
#define HEADER_H

typedef int T;
struct element;

int generateRandom();
void addToFront(element *&head, T val);
void printFromStart(element * head);
void addRandom(element *& head);
void addSorted(element * & head, T val);
void addSortedReq(element * & head, T val);
void printFromStartReq(element * head, std::ostream&);
void printFromEndReq(element * head, std::ostream&);
element *findE(element * head, int val);
element *findEReq(element * & head, int val);
void deleteElement(element *&head, element *toDelete);
#endif // !HEADER_H