#include <vector>
#include <chrono>
#include <iostream>
#include "SerialQuicksort.h"

typedef std::vector<double> ArrayType;

int main() {
	ArrayType myarray = { 45,65,84,54 };
	SerialQuicksort<ArrayType> sorter;
	sorter(myarray, 0, 3);

	for (std::size_t i = 0; i < myarray.size(); i++) {
		std::cout << myarray[i] << " ";
	}
	return 0;

}