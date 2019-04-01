#pragma once
#include <fstream>
#include <string>
struct Student;
void odczytaj(Student *head, string filePath);
void add(Student *&head, std::string name, float a);