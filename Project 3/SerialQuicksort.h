#ifndef _SERIAL_HEADER
#define _SERIAL_HEADER
#include <iostream>


template <typename T>
class SerialQuicksort
{
public:
	SerialQuicksort() {}
	virtual ~SerialQuicksort() {}
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
		// recursive calls
		if (first < j)
			(*this)(theArray, first, j);
		if (i < last)
			(*this)(theArray, i, last);

			}

	void show(T& arr, int first, int last) {
		for (int i = first; i <= last; ++i) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}
};

#endif