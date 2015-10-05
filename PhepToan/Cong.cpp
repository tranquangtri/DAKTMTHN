#include <string>
#include "QInt.h"
//	TOÁN TỬ CỘNG HAI QINT
//  THAM SỐ: QInt so, QInt cần cộng
//  TRẢ VỀ:	 Trả về một QInt mới là kết qua của phép cộng	
//	MÔ TẢ:	Lần lượt cộng từng nhóm 64bit của mỗi QInt lại với nhau
//
//			[Nhóm 64 bit . 1] [Nhóm 64 bit . 2]
//					+				  +
//			[Nhóm 64 bit . 1] [Nhóm 64 bit . 2]
//					+				   |
//				  [Dư]<-----------------								
//
QInt QInt::operator+(QInt so)
{
	//	Làm thế nào xác định xem phép cộng của nhóm 2 có dư không ? 
	//	Đầu tiên tách hai bit đầu tiên bên trái và cộng nó lại, nếu tổng lớn hơn 1 (có dư) -> ghi nhớ lại
	//				|0/1|63 BIT|
	//				  +
	//				|0/1|63 BIT|
	//
	//	Trường hợp nếu tổng là 1 thì chỉ cần xem bit trái nhóm 2 của kết quả cuối cùng sau khi cộng, nếu nó vẫn là 1
	//	thì không dư, nếu nó thay đổi thành 0 thì chứng tỏ có dư do có bit cộng dồn từ các bit bên phải
	//				|1|63 BIT| ---------------------------> |0|63 BIT|
	//		[Tông của hai bit trái nhóm 2]    	[Tổng của cả hai nhóm 64 bit nhóm 2]
	//
	//	Trường hợp nếu tổng hai bit trái là 0 thì chắc chắc không có dư, vì sau khi cọng QInt thì tối đa chỉ lên 1 -> không dư

	long long maskBitTraiDau = 1;
	maskBitTraiDau = maskBitTraiDau << 63;
	unsigned char bitTraiDau1 = ((unsigned long long)arrayBits[1] & maskBitTraiDau) >> 63;
	unsigned char bitTraiDau2 = ((unsigned long long)so.arrayBits[1] & maskBitTraiDau) >> 63;
	char tongHaiBitTrai = (bitTraiDau1 + bitTraiDau2) & 0x03;

	QInt ketQua = *this;
	ketQua.arrayBits[1] = so.arrayBits[1] + arrayBits[1];
	ketQua.arrayBits[0] = so.arrayBits[0] + arrayBits[0];

	if ((tongHaiBitTrai > 1) || ((tongHaiBitTrai == 1) && ((ketQua.arrayBits[1] & maskBitTraiDau) == 0)))
	{
		ketQua.arrayBits[0] += 1;
	}
	return ketQua;
}