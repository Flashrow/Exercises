#pragma once
#ifndef HEADER_H
#define HEADER_H

typedef int T;
struct element;

void addToFront(element *&head, T val);
void printFromStart(element * head);
void addRandom(element *& head);
void addSorted(element * & head, T val);
#endif // !HEADER_H