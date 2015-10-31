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
		
		if (first < last && last <= theArray.size()) {
			std::size_t pivot = first;
			//partition
			auto pivotElem = theArray[first];
			for (std::size_t i = first + 1; i <= last; ++i) {
				if (theArray[i] <= pivotElem) {
					pivot++;
					std::swap(theArray[i],theArray[pivot]);
				}
			}
			std::swap(theArray[pivot], theArray[first]);

			// recursive calls
				(*this)(theArray, first, pivot-1);
				(*this)(theArray, pivot+1, last);
		}
	}
	////////////////////////////////////////////////////////
	void show(T& arr, int first, int last) {
		for (int i = first; i <= last; ++i) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}
};

#endif