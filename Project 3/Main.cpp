#include <random>
#include <vector>
#include <chrono>
#include <iostream>
#include "ConcurrentQuicksort.h"
#include "SerialQuicksort.h"


typedef std::vector<int> ArrayType;

int main() {
	ArrayType myarray = { 45,65,84,54,658,548,1,8,8,5 };
	
	ConcurrentQuicksort<ArrayType> sorter;
	sorter(myarray, 0, myarray.size()-1);

	sorter.show(myarray,0,myarray.size()-1);
	return 0;

}