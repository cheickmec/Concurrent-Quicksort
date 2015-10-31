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
		if (first < last && last <= theArray.size()) {
			std::size_t pivot = first;
			//partition
			auto pivotElem = theArray[first];
			for (std::size_t i = first + 1; i <= last; ++i) {
				if (theArray[i] <= pivotElem) {
					pivot++;
					std::swap(theArray[i], theArray[pivot]);
				}
			}
			std::swap(theArray[pivot], theArray[first]);
			//threading
				auto fut1 = std::async(*this, std::ref(theArray), first, pivot-1);
				auto fut2 = std::async(*this, std::ref(theArray), pivot+1, last);
		}
	}
	void show(T& arr, int first, int last) {
		for (int i = first; i <= last; ++i) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}

};
#endif
