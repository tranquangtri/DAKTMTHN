#include <string>
#include "QInt.h"

// XOAY TRÁI QINT
QInt QInt::XoayTrai()
{
	// Đầu tiên lấy bit trái nhất của nhóm 1
	// Dịch trái QInt 1 bit rồi thêm bit trái vừa lấy và bit phải nhất của nhóm 2 
	// (lúc này bit phải nhất của nhóm hai là 0)
	QInt ketQua = *this;
	unsigned long long maskBitTrai = ((unsigned long long)1) << 63;
	unsigned long long bitTrai = ketQua.arrayBits[0] & maskBitTrai;
	unsigned long long bitPhai = bitTrai >> 63;
	ketQua = ketQua << 1;
	ketQua.arrayBits[1] = ketQua.arrayBits[1] | bitPhai;
	return ketQua;
}
// XOAY PHẢI QINT
QInt QInt::XoayPhai()
{
	// TƯỞNG TƯ XOAY TRÁI
	QInt ketQua = *this;
	unsigned long long maskBitPhai = 1;
	unsigned long long bitPhai = ketQua.arrayBits[1] & maskBitPhai;
	unsigned long long bitTrai = bitPhai << 63;
	ketQua = ketQua >> 1;
	unsigned long long maskBitTrai0 = 9223372036854775807; // Bit trái nhất là 0, 63 bit còn lại là 1
	ketQua.arrayBits[0] = ketQua.arrayBits[0] & maskBitTrai0 | bitTrai;
	return ketQua;
}