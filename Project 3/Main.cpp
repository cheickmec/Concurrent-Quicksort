#include <random>
#include <vector>
#include <chrono>
#include <iostream>
#include "ConcurrentQuicksort.h"
#include "SerialQuicksort.h"


typedef std::vector<int> ArrayType;

int main() {
	ArrayType myarray = { 45,65,84,54,658,548,1,8,8,5 };
	
	SerialQuicksort<ArrayType> sorter;
	sorter(myarray, 0, myarray.size()-1);

	for (std::size_t i = 0; i < myarray.size(); i++) {
		std::cout << myarray[i] << " ";
	}
	std::cout << " count" << count;
	return 0;

}