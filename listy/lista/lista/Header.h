#pragma once
struct element;
void addToFront(element *& head, int value);
void addSorted(element *& head, int value);
void printList(element * head);
void deleteElement(element * head, int value);