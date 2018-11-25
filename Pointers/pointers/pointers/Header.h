#pragma once

bool is_good();
void revert(int tab[], const int SIZE);
void printTab(int tab[], const int SIZE);
void functionF(const int N, void (*f[])(int[], const int), int t[], const int W);