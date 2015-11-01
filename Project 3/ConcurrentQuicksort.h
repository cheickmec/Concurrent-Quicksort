#ifndef _CONCURRENT_HEADER
#define _CONCURRENT_HEADER
#include <thread>
#include <future>
#include <algorithm>

const int SWITCH_SIZE = 500;

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
		if ((last - first) > SWITCH_SIZE) {
			//threading
			auto fut1 = std::async(*this, std::ref(theArray), first, pivot);
			//(*this)(theArray, pivot + 1, last);
			auto fut2 = std::async(*this, std::ref(theArray), pivot + 1, last);
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
};
#endif
