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
		int pivot = (first + last) >> 1;
		while (i <= j) {
			while (theArray[i] < theArray[pivot])
				i++;
			while (theArray[j] > theArray[pivot])
				j--;
			if (i <= j) {
				std::swap(theArray[i], theArray[j]);
				i++;
				j--;
			}
		}
		if (first < j)
			auto fut1 = std::async(*this, std::ref(theArray), first, j);
		if (i < last)
			auto fut2 = std::async(*this, std::ref(theArray), i, last);
	}

};
#endif
