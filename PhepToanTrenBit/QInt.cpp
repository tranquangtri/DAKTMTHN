#include <string>
#include "QInt.h"

QInt::QInt(long long a1, long long a2)
{
	arrayBits[0] = a1;
	arrayBits[1] = a2;
}
QInt::QInt()
{
	arrayBits[0] = 0;
	arrayBits[1] = 0;
}