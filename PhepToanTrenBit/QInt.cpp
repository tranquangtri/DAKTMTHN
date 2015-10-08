#include <string>
#include "QInt.h"

QInt::QInt()
{
	arrayBits[0] = 0;
	arrayBits[1] = 0;
}
// Chuyển chuỗi nhị phân sang QInt
void QInt::GetBinary(const string& binary)
{
	int n = binary.length();
	for (int i = 0; i < n; i++)
	{
		unsigned long long mask = binary[n - i - 1] - '0';
		if (i < 64)
		{
			arrayBits[1] = arrayBits[1] | (mask << i);
		}
		else if (i < 128)
		{
			arrayBits[0] = arrayBits[0] | (mask << (i - 64));
		}
		else
			break;
	}
}
// Chuyển QINT sang chuỗi theo hệ số cho trước
string QInt::ToString(int heSo)
{
	// Chuyển sang chuỗi biểu diễn nhị phân QINT
	if (heSo == 2)
	{
		string ketQua("");
		int index = 0;
		// Bỏ các số 0 dư thừa ở đầu
		// In ra các số kề tử số 1 đầu tiên bên trái
		while ((index <= 127) && ((*this)[index] != 1))
			index++;
		for (int i = 0; i <= 127 - index; i++)
		{
			ketQua += (*this)[i + index] + '0';
		}
		// Nếu cả đều là số 0 thì thì trả về 0
		return ketQua == "" ? "0" : ketQua;
	}
	// Trường hợp hệ số nhập không hợp lệ, nằm ngoài khả năng của chương trình
	return "<KHONG THE CHUYEN DOI SANG HE SO NAY>";
}