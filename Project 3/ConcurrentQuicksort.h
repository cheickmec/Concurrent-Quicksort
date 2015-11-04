#ifndef _CONCURRENT_HEADER
#define _CONCURRENT_HEADER
#include <thread>
#include <future>
#include <algorithm>

const unsigned long SWITCH_SIZE = 6000;
static bool create =false;
//pass number of threads as an argument
//lower bound 300
template<typename T>
class ConcurrentQuicksort
{
public:
	ConcurrentQuicksort() {};
	virtual ~ConcurrentQuicksort() {};
	void operator()(T& theArray, std::size_t first, std::size_t last) {

		if (last <= first ||  last >= theArray.size() ) return;
		std::size_t pivot = (first + last ) >> 1;

		//partition
		pivot = pPartition(theArray,first,last,pivot);

		if ((last - first) > SWITCH_SIZE && numbThreads > 0) {
			create = true;
			auto fut1 = std::async(std::launch::async,[&]() {return quickSort(theArray, first,pivot,--numbThreads);});
			auto fut2 = std::async(std::launch::async,[&]() {return quickSort(theArray, pivot+1,last,--numbThreads);});
			fut1.get();
			fut2.get();
		}
		else {
			(*this)(theArray, first, pivot - 1);
			(*this)(theArray, pivot + 1, last);
		}
		return;
	}
	/////////////////////// DISPLAY function///////////////////////////
	void show(T& arr, int first, int last) {
		for (int i = first; i <= last; ++i) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}
	///////////////////// PARTITION function /////////////////////////
	inline std::size_t pPartition(T& arr, std::size_t first, std::size_t last, std::size_t pivot) {
		auto pivotElem = arr[pivot];
		while (first<last) {
			while (arr[first] < pivotElem)
				++first;
			while (arr[last] > pivotElem)
				--last;
			if (arr[first] >= arr[last]) {
				std::swap(arr[first], arr[last]);
			}
		}
		return first;
	}
	//private:
	///// stores maximum number of threads
	std::size_t numbThreads = 650;

    void quickSort(T& theArray, std::size_t first, std::size_t last, std::size_t nThreads){
        if (last <= first ||  last >= theArray.size() ) return;
		std::size_t pivot = (first + last ) >> 1;

		//partition
		pivot = pPartition(theArray,first,last,pivot);
		if ((last - first) > SWITCH_SIZE && --nThreads >0 ) {
			//threading
			auto fut1 = std::async(std::launch::async,[&]() {return quickSort(theArray, first,pivot,--numbThreads);});
			auto fut2 = std::async(std::launch::async,[&]() {return quickSort(theArray, pivot+1,last,--numbThreads);});
			fut1.get();
			fut2.get();
		}
		else {
			quickSort(theArray, first, pivot - 1,nThreads);
			quickSort(theArray, pivot + 1, last,nThreads);
		}
		return;
	}
};
#endif
