#include <random>
#include <vector>
#include <chrono>
#include <iostream>
#include "ConcurrentQuicksort.h"
#include "SerialQuicksort.h"
#include <fstream>
#include <iomanip>
#include <cassert>

template <typename T>
bool isSorted(T& theList, std::size_t first, std::size_t last) {
	if (first == last) return true;
	if (first < last) {
		unsigned long int i = 0;
		for (; i < last; ++i){
			if (theList[i] > theList[i + 1]) return false;
		}
		return true;
	}
	std::cout << "unproper range. last must be greater or equal to first" << std::endl;
	return false;
}

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
//====================MAIN=================================================//
int main() {
	std::ofstream fout;
	fout.open("mydata.txt", std::ios::out);
/////////////////////////  table header //////////////////////////////////////////////////////
	fout << "List Size" << std::setw(35) <<std::internal<< "Sequential Time (s)"  <<std::setw(45) << std::internal << "Concurrent Time (s)" << std::endl;	//
	fout << "         " << std::setw(15)<< std::internal << "min" << std::setw(15) << std::internal << "max" << std::setw(15) << std::internal << "average" << std::setw(15) <<
	std::setw(15)<< "min" << std::setw(15) << "max" << std::setw(15) << "average" << std::endl;		//
	fout << "---------"<<std::setw(16)<<"-----"<<std::setw(15) <<"-----"<<std::setw(14)<<"-------"<<std::setw(16)<<"-----"<<std::setw(15)<<"-----"<<std::setw(14)<<"-------" << std::endl;		//
//////////////////////////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------------------------//
	ConcurrentQuicksort<ArrayType> cSorter;
	SerialQuicksort<ArrayType> sSorter;
	const std::size_t sampleSize = 10;
	long N;

	for ( N = 10; N <= 1000000; N *= 10) {
////////////////////////////////////////////////////////////////////////////////
		std::chrono::time_point<std::chrono::system_clock> start, end;
		std::chrono::duration<double> elapsed_seconds1(0),elapsed_seconds2(0);
		std::chrono::duration<double> diff1(0), diff2(0),max1(0),max2(0), min1(0), min2(0);

//////////////////// Start Sampling  ///////////////////////////////////////////
        ArrayType myarray1(N);
        ArrayType myarray2(N);

		elapsed_seconds1 = elapsed_seconds2 = max1 = min1 = min2 = max2 = max2 - max2;
		///////////// Loop : Sequential	sorting ////////////////////////////////
		for (std::size_t i = 0; i < sampleSize; ++i) {
            fill_normal d;
			for_each(myarray1.begin(), myarray1.end(), d);
			myarray2 = myarray1;

			/////////////// timing of serial ///////////////////////////////////
			start = std::chrono::system_clock::now();
			sSorter(myarray1, 0, myarray1.size() - 1);
			end = std::chrono::system_clock::now();
			elapsed_seconds1 += (end - start);
			max1 = max1 >= (end - start) ? max1 : (end - start);
			if (i == 0) min1 = elapsed_seconds1;
			min1 = min1 <= (end - start) ? min1 : (end - start);
			assert(isSorted(myarray1, 0, myarray1.size() - 1));
			/////////////// timing of concurrent ////////////////////////////////
			start = std::chrono::system_clock::now();
			cSorter(myarray2, 0, myarray2.size() - 1);
			end = std::chrono::system_clock::now();
			elapsed_seconds2 += (end - start);
			max2 = max2 >= (end - start) ? max2 : (end - start);
			if (i == 0) min2 = elapsed_seconds2;
			min2 = min2 <= (end - start) ? min2 : (end - start);
            assert(isSorted(myarray1, 0, myarray1.size() - 1));

		}

		fout <<std::setw(18)<<std::left<< N << std::setw(15)<< min1.count() << std::setw(13) <<max1.count()<<std::setw(18)<<elapsed_seconds1.count()/sampleSize;
		fout << std::setw(15) << min2.count() << std::setw(13) << max2.count() << std::setw(12) << elapsed_seconds2.count()/sampleSize;

		//diff1 = elapsed_seconds1 / sampleSize;
		//diff2 = elapsed_seconds2/sampleSize;
		fout/* << "d: "<<diff1.count()/diff2.count()*/<<std::endl;

	}
	fout.close();
	std::cout << "DONE" << std::endl;
    //std::cout << SWITCH_SIZE<<std::endl;
	return 0;
}
