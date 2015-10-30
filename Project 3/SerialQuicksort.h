#ifndef _SERIAL_HEADER
#define _SERIAL_HEADER
int count = 0;
template <typename T>
class SerialQuicksort
{
public:
	SerialQuicksort() {}
	virtual ~SerialQuicksort() {}
	void operator()(T& theArray, int first, int last) {
		count++;
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
			(*this)(theArray, first, j);
		if (i < last)
			(*this)(theArray, i, last);
	}
};

#include "SerialQuicksort.cpp"
#endif