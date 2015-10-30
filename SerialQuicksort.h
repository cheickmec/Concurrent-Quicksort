#ifndef _SERIAL_HEADER
#define _SERIAL_HEADER

template <typename T>
class SerialQuicksort
{
public:
	SerialQuicksort();
	virtual ~SerialQuicksort();
	void operator()(T& theArray, int first, int last);
};
#endif