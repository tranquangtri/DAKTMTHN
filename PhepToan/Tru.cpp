#include <string>
#include "QInt.h"

//	TÌM BÙ HAI QINT
//  TRẢ VỀ:	 Trả về một QInt mới sau khi lấy bù hai của QInt cũ
QInt QInt::BuHai()
{
	QInt ketQua = ~(*this);
	ketQua = ketQua + QInt(0, 1);
	return ketQua;
}
QInt QInt::operator-(QInt so)
{
	return *this + so.BuHai();
}