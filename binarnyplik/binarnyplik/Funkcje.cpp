#include <random>
#include <chrono>

#include "Header.h"

void makeFile(std::ofstream &ofile) {
	for (int i = 0; i < 5; i++) {
		for (int k = 0; k < 5; k++) {
			ofile << getRandom();
		}
		ofile << "\n";
	}
}

int getRandom(){
std::default_random_engine engine;
std::normal_distribution<int> distribution(10,99);
engine.seed(std::chrono::system_clock::now().time_since_epoch().count());
return distribution(engine);
}