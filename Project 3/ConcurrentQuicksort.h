#ifndef _CONCURRENT_HEADER
#define _CONCURRENT_HEADER
#include <thread>
#include <future>

template<typename T>
class ConcurrentQuicksort
{
public:
	ConcurrentQuicksort() {};
	virtual ~ConcurrentQuicksort() {};
	void operator()(T& theArray, int first, int last) {
		int i = first, j = last;
		int tmp;
		int pivot = theArray[(first + last) >> 1];
		// array partition 
		while (i <= j) {
			while (theArray[i] < pivot)
				i++;
			while (theArray[j] > pivot)
				j--;
			if (i <= j) {
				std::swap(theArray[i++], theArray[j--]);
			}
		};
		if (first < j)
			auto fut1 = std::async(*this, std::ref(theArray), first, j);
		if (i < last)
			auto fut2 = std::async(*this, std::ref(theArray), i, last);
	}
	void show(T& arr, int first, int last) {
		for (int i = first; i <= last; ++i) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}

};
#endif
