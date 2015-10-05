#include <string>
#include "QInt.h"

QInt QInt::operator*(QInt so)
{
	int k = 128;
	QInt A(0, 0);
	QInt Q = so;
	char bitThem = 0;
	unsigned long long maskBitTrai0 = 9223372036854775807; // Bit trái nhất là 0, 63 bit còn lại là 1
	// A Q C
	while (k > 0)
	{
		// Nếu hai bit cuối là 10 thì A = A - M
		if (((Q & QInt(0, 1)) == QInt(0, 1)) && (bitThem == 0))
		{
			A = A - *this;
		}
		// Nếu hai bit cuối là 10 thì A = A - M
		else if (((Q & QInt(0, 1)) == QInt(0, 0)) && (bitThem == 1))
		{
			A = A + *this;
		}
		// Dịch phải [A Q BitThem]
		unsigned long long bitCuoiA = A[127];
		bitThem = Q[127];
		// Dịch phải luận lý A
		A = (A >> 1);
		A.arrayBits[0] = A.arrayBits[0] & maskBitTrai0;
		// Thêm bit phải cuối của A vào bit đầu của Q
		Q = Q >> 1;
		Q.arrayBits[0] = (Q.arrayBits[0] & maskBitTrai0) | (bitCuoiA << 63);

		k--;
	}
	// Vì kết quả trả về QInt (128 bit) tương ứng với Q
	return Q;
}
