#include "SerialQuicksort.h"
#include <algorithm>

template<typename T>
SerialQuicksort<T>::SerialQuicksort()
{
}

template<typename T>
SerialQuicksort<T>::~SerialQuicksort()
{
}

template<typename T>
void SerialQuicksort<T>::operator()(T& theArray, int first, int last) {
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