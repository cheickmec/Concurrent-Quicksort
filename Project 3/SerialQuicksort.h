#ifndef _SERIAL_HEADER
#define _SERIAL_HEADER
#include <iostream>

template <typename T>
class SerialQuicksort
{
public:
	SerialQuicksort() {}
	virtual ~SerialQuicksort() {}
	void operator()(T& theArray, std::size_t first, std::size_t last) {
		if (last <= first || last >= theArray.size()) return;
		std::size_t pivot = (first + last) >> 1;
		
		//partition
		pivot = pPartition(theArray, first, last, pivot);	
		
		// recursive calls
			(*this)(theArray, first, pivot-1);
			(*this)(theArray, pivot+1, last);
			
		
	}
	////////////////////////////////////////////////////////
	void show(T& arr, int first, int last) {
		for (int i = first; i <= last; ++i) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}
	////////////////////////////////////////////////////////
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