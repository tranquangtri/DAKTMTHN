#include <string>
#include "QInt.h"

QInt QInt::operator/(QInt so)
{
	QInt Q = *this;
	// Đưa hai số chia và bị chia về số dương, sau khi ra kết quả ta thêm dấu váo sau
	int sign = 1;
	if (Q[0] == 1)
	{
		sign = -sign;
		Q = Q.BuHai();
	}
	if (so[0] == 1)
	{
		sign = -sign;
		so = so.BuHai();
	}

	QInt A("0", 2);
	int k = 128;
	while (k > 0)
	{
		// Dịch trái [A,Q]
		char bitTraiQ = Q[0];
		Q = Q << 1;
		A = A << 1;
		A.arrayBits[1] = A.arrayBits[1] | bitTraiQ;
		// A = A - M
		A = A - so;
		// Nếu A < 0, Bit phải nhất của Q là 0 (mặc định sau khi dịch bit phải nhất Q đã là 0), A = A + M
		// Ngược lịa Bit phải nhất của Q là 1
		if (A[0] == 1)
		{
			A = A + so;
		}
		else
		{
			Q.arrayBits[1] = Q.arrayBits[1] | 1;
		}
		k--;
	}
	if (sign < 0)
		Q = Q.BuHai();
	return Q;
}