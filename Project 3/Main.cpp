#include <random>
#include <vector>
#include <chrono>
#include <iostream>
#include "ConcurrentQuicksort.h"
#include "SerialQuicksort.h"

// a normal distributed random number generator
class fill_normal
{
public:
	fill_normal()
	{
		std::random_device rd;
		gen.seed(rd());
	}
	void operator()(double & x)
	{
		x = p(gen);
	}
private:
	std::mt19937 gen;
	std::normal_distribution<double> p;
};

typedef std::vector<double> ArrayType;

int main() {
	ConcurrentQuicksort<ArrayType> cSorter;
	SerialQuicksort<ArrayType> sSorter;
	
	std::cout << "List Size\tSequential Time (s)\tConcurrent Time (s)" << std::endl;
	std::cout << "---------\t---------------------\t-------------------" << std::endl;
	for (long N = 10; N <= 1000000; N *= 10) {
		ArrayType myarray1(N);
		ArrayType myarray2(N);
		fill_normal d;
		for_each(myarray1.begin(), myarray1.end(), d);
		myarray2 = myarray1;
		std::chrono::time_point<std::chrono::system_clock> start, end;
		std::chrono::duration<double> elapsed_seconds;
		
		/////////////// timing of serial ////////////////////////////////////
		start = std::chrono::system_clock::now();
		sSorter(myarray1, 0, N - 1);
		end = std::chrono::system_clock::now();
		elapsed_seconds = end - start;
		std::cout << N << "\t\t" << elapsed_seconds.count() << "\t\t";
		/////////////// timing of concurrent ////////////////////////////////
		start = std::chrono::system_clock::now();
		cSorter(myarray2, 0, N - 1);
		end = std::chrono::system_clock::now();
		elapsed_seconds = end - start;
		std::cout << elapsed_seconds.count() << std::endl;
	}
	return 0;

}