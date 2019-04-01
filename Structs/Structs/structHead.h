#pragma once
struct structData;
struct structStudent;

void initiateData(structData& d1, int y=0, int m=0, int d=0);
void printData(const structData d1);
bool equalData(const structData d1, const structData d2);

void setNazwisko(structStudent student);
void printStudent(const structStudent student);