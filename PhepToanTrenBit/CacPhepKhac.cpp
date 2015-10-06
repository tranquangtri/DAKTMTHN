#include <iostream>
#include "QInt.h"
// HÀM GET BIT, TRẢ VỀ KÍ TỰ 0/1 THÊ HIỆN CHO BIT ĐÓ
char QInt::operator[](int index) const
{
	char bit = 0;
	if ((index > 127) || (index <0))
		return 0x7F;
	else if (index > 63)
	{
		index -= 64;
		bit = (arrayBits[1] & ((unsigned long long)1 << (63 - index))) >> (63 - index);
	}
	else
	{
		bit = (arrayBits[0] & ((unsigned long long)1 << (63 - index))) >> (63 - index);
	}
	return bit;
}
bool QInt::operator==(const QInt& so)
{
	return ((so.arrayBits[0] == arrayBits[0]) && (so.arrayBits[1] == arrayBits[1]));
}