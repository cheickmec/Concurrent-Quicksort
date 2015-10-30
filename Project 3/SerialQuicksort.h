#pragma once
#include <algorithm>
template <typename T>
class SerialQuicksort
{
public:
	SerialQuicksort();
	virtual ~SerialQuicksort();
	void operator()(T& theArray, int first, int last);
};

