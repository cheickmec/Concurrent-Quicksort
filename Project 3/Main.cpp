 
#include <random>
#include <vector>
#include <chrono>
#include <iostream>
#include "ConcurrentQuicksort.h"
#include "SerialQuicksort.h"
#include <fstream>

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
//====================MAIN=================================================//
typedef std::vector<double> ArrayType;

int main() {
	//std::ofstream std::cout;
	//std::cout.open("mydata.txt", std::ios::out);

	ConcurrentQuicksort<ArrayType> cSorter;
	SerialQuicksort<ArrayType> sSorter;
	const std::size_t sampleSize = 10;
	std::cout << "List Size\t\tSequential Time (s)\t\t Concurrent Time (s)" << std::endl;
	std::cout << "         \t\tmin\tmax\taverage\t\tmin\tmax\taverage" << std::endl;
	std::cout << "---------\t\t---\t---\t-------\t\t---\t---\t-------" << std::endl;
	std::chrono::time_point<std::chrono::system_clock> start, end;
	std::chrono::duration<double> diff1, diff2;
	static std::size_t total = 0;
	long N;
	for ( N = 10; N <= 100000; N *= 10) {
////////////////////////////////////////////////////////////////////////////////
//////////////////// Start Sampling  ///////////////////////////////////////////
		ArrayType myarray1(N);
		ArrayType myarray2(N);
		fill_normal d;
		std::chrono::duration<double> elapsed_seconds(0);
		///////////// Loop : Sequential	sorting ////////////////////////////////
		for (std::size_t i = 0; i < sampleSize; ++i) {
			for_each(myarray1.begin(), myarray1.end(), d);
			/////////////// timing of serial ///////////////////////////////////
			start = std::chrono::system_clock::now();
			sSorter(myarray1, 0, N - 1);
			end = std::chrono::system_clock::now();
			elapsed_seconds += (end - start);
		}
		diff1 = elapsed_seconds / sampleSize;
		std::cout << N << "\t\t" << diff1.count() <<"\t\t";
		
		////////////	Loop: Concurrent sorting ////////////////////////////////
		elapsed_seconds = start - start;
		for (std::size_t i = 0; i < sampleSize; ++i) {
			for_each(myarray2.begin(), myarray2.end(), d);
			/////////////// timing of concurrent ////////////////////////////////
			start = std::chrono::system_clock::now();
			cSorter(myarray2, 0, N - 1);
			end = std::chrono::system_clock::now();
			elapsed_seconds += (end - start);
		}
		diff2 = elapsed_seconds/sampleSize;
		std::cout << diff2.count() << "\tdifference: "<< diff1.count()/diff2.count() <<"\t"<<std::endl;
		if (diff1.count() / diff2.count() > 1) ++total;
	}
	//std::cout.close();
	std::cout << "DONE" << std::endl;
	return 0;
}
