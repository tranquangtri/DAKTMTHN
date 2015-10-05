#include <string>
#include "QInt.h"
QInt QInt::operator|(QInt so)
{
	QInt ketQua;
	ketQua.arrayBits[0] = arrayBits[0] | so.arrayBits[0];
	ketQua.arrayBits[1] = arrayBits[1] | so.arrayBits[1];
	return ketQua;
}
QInt QInt::operator&(QInt so)
{
	QInt ketQua;
	ketQua.arrayBits[0] = arrayBits[0] & so.arrayBits[0];
	ketQua.arrayBits[1] = arrayBits[1] & so.arrayBits[1];
	return ketQua;
}

QInt QInt::operator^(QInt so)
{
	QInt ketQua;
	ketQua.arrayBits[0] = arrayBits[0] ^ so.arrayBits[0];
	ketQua.arrayBits[1] = arrayBits[1] ^ so.arrayBits[1];
	return ketQua;
}

QInt QInt::operator~()
{
	QInt ketQua = *this;
	ketQua.arrayBits[0] = ~arrayBits[0];
	ketQua.arrayBits[1] = ~arrayBits[1];
	return ketQua;
}