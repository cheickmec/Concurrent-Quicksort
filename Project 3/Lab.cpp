/*
#include <vector>
#include <algorithm>
#include <random>
#include <thread>
#include <future>
#include <iostream>
static unsigned int numThread = 0;
typedef std::vector<double> ArrayType;

// list size threshold for which we switch between
// serial and concurrent. Lists below this size
// are sorted using sequential mergesort
const int SWITCH_SIZE = 1000;

void merge(ArrayType& theArray, int first, int mid, int last)
{
	numThread++;
	ArrayType tempArray(theArray.size());

	int first1 = first;
	int last1 = mid;
	int first2 = mid + 1;
	int last2 = last;

	int index = first1;
	for (; (first1 <= last1) && (first2 <= last2); ++index) {
		if (theArray[first1] <= theArray[first2]) {
			tempArray[index] = theArray[first1];
			++first1;
		}
		else {
			tempArray[index] = theArray[first2];
			++first2;
		}
	}

	for (; first1 <= last1; ++first1, ++index)
		tempArray[index] = theArray[first1];

	for (; first2 <= last2; ++first2, ++index)
		tempArray[index] = theArray[first2];

	for (index = first; index <= last; ++index)
		theArray[index] = tempArray[index];
}
///////////// Optimized merge-sort ////////////////////////////
void msort(ArrayType& theArray, int first, int last)
{
	if (first < last) {

		int mid = (first + last) >> 1;

		if ((last - first) > SWITCH_SIZE) {
			// block scope forces furture destructor and thus wait on async calls
			auto fut0 = std::async(&msort, std::ref(theArray), first, mid);
			auto fut1 = std::async(&msort, std::ref(theArray), mid + 1, last);
		}
		else {
			msort(theArray, first, mid);
			msort(theArray, mid + 1, last);
		}

		merge(theArray, first, mid, last);
	}

}
/////////////    concurrent sort  /////////////////////////////
void msortConcur(ArrayType& theArray, int first, int last)
{
	if (first < last) {

		int mid = (first + last) >> 1;

			// block scope forces furture destructor and thus wait on async calls
			auto fut0 = std::async(&msortConcur, std::ref(theArray), first, mid);
			auto fut1 = std::async(&msortConcur, std::ref(theArray), mid + 1, last);
			merge(theArray, first, mid, last);
	}
}

/////////////    concurrent sort  /////////////////////////////
void msortSerial(ArrayType& theArray, int first, int last)
{
	if (first < last) {
		int mid = (first + last) >> 1;
		msortSerial(theArray, first, mid);
		msortSerial(theArray, mid + 1, last);
		merge(theArray, first, mid, last);
	}
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


int main()
{
	std::cout << "List Size\tSerial Time (s)\t\tOptimized Time (s)"<< std::endl;
	std::cout << "---------\t---------------\t\t------------------" << std::endl;
	for (long N = 10; N < 500000; N = 2 * N) {
		ArrayType data1(N);
		ArrayType data2(N);
		

		fill_normal d;
		for_each(data1.begin(), data1.end(), d);
		data2 = data1;
		std::chrono::time_point<std::chrono::system_clock> start, end;
		std::chrono::duration<double> elapsed_seconds;

			
		/////////////////////////////merge-sort serial/////////////////////////////////////////////
		start = std::chrono::system_clock::now();
		msortSerial(data1, 0, data1.size() - 1);
		end = std::chrono::system_clock::now();
		elapsed_seconds = end - start;
		std::cout <<N<<"\t\t"<<elapsed_seconds.count() << "\t\t";
		/////////////////////////////merge-sort optimized/////////////////////////////////////////////
		start = std::chrono::system_clock::now();
		msort(data2, 0, data2.size() - 1);
		end = std::chrono::system_clock::now();
		elapsed_seconds = end - start;
		std::cout << elapsed_seconds.count() << " -- threads: "<< numThread<<std::endl;
		numThread = 0;
	}

	return 0;
}
*/