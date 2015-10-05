#include <iostream>
#include "QInt.h"
// CÁC TOÁN TỬ DỊCH BIT PHẢI
QInt QInt::operator>>(int num)
{
	// Lưu lại bit phải nhất của nhóm 1
	// Dịch phải luận lý nhóm hai
	// Thêm bit vừa lưu lại vào bit trái nhất nhóm 2
	// Rồi dịch phải số học nhóm 1
	unsigned long long nhomBitHai = arrayBits[1];
	long long nhomBitDau = arrayBits[0];
	unsigned long long maskBitCuoiBenPhai = 0;
	for (int i = 1; i <= num; i++)
	{
		maskBitCuoiBenPhai = (nhomBitDau & 1);
		nhomBitHai = nhomBitHai >> 1;
		nhomBitHai = nhomBitHai | (maskBitCuoiBenPhai << 63);
		nhomBitDau = nhomBitDau >> 1;
	}
	return QInt(nhomBitDau, nhomBitHai);

}

// CÁC TOÁN TỬ DỊCH BIT TRÁI
QInt QInt::operator<<(int num)
{
	// Tưởng tự dịch phải
	long long nhomBitHai = arrayBits[1];
	long long nhomBitDau = arrayBits[0];
	unsigned long long maskBitCuoiBenTrai = 0;
	long long _mask = 1;
	_mask = _mask << 63;
	for (int i = 1; i <= num; i++)
	{
		maskBitCuoiBenTrai = (nhomBitHai & _mask);
		nhomBitDau = nhomBitDau << 1;
		nhomBitDau = nhomBitDau | (maskBitCuoiBenTrai >> 63);
		nhomBitHai = nhomBitHai << 1;
	}
	return QInt(nhomBitDau, nhomBitHai);
}