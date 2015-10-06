#include <string>
using namespace std;
class QInt
{
private:
	long long arrayBits[2]; // Lưu hai nhóm 64bit của QInt
public:
	enum HESO
	{
		DEC = 10,
		BIN = 2,
		HEX = 16
	};

	// Hàm khởi tạo
	// Tham số: a1,a2 hai nhóm bit của QInt
	QInt(long long a1, long long a2);

	// Hàm khởi tạo
	// Tham số: khởi tạo QInt = 0
	QInt();

	// 1. [THUẬN] Chuyển từ bin, dec, hex sang QInt
	// Tham số đầu vào là một chuỗi dạng nhị phân, thập phân hoặc thập lục phần
	// Nhiêm vụ là đưa chuỗi đó về dạng số và lưu trữ trong arrayBits
	void GetBin(string bin);
	void GetDec(string dec);
	void GetHex(string hex);

	// 2. [TIẾN] Chuyển từ QInt sang nhị phân (ToBin), sang thập phân (ToDec), sang thập lục phân (ToHex)
	// Hàm sẽ trả về một chuỗi nhị phân, thập phân hoặc thập lúc phân
	// Nhiệm vụ là làm sao đó đưa dãy 128 bit cuar arrayBits về dạng chuỗi theo hệ số tương ứng
	string ToBin();
	string ToDec();
	string ToHex();

	// Operator +
	// Tham số:	QInt so, số cần cộng
	// Trả về: Trả về QInt mới là tổng hai của QInt được cộng
	QInt operator+(QInt so);

	// Operator -
	// Tham số:	QInt so, số cần trừ
	// Trả về: Trả về QInt mới là hiệu hai của QInt được cộng
	QInt operator-(QInt so);

	// Operator *
	// Tham số:	QInt so, số cần nhân
	// Trả về: Trả về QInt mới là tích hai của QInt
	QInt operator*(QInt so);

	// Operator /
	// Tham số:	QInt so, số cần chia
	// Trả về: Trả về QInt mới là thương của hai QInt
	QInt operator/(QInt so);

	// Xoay trái
	// Trả về: Trả về QInt mới có được khi xoay trái QInt
	QInt XoayTrai();

	// Xoay phải
	// Trả về: Trả về QInt mới có được khi xoay phải QInt
	QInt XoayPhai();

	// Tìm số bù hai của QInt
	// Trả về: Trả về QInt mới có được khi lấy bù hai QInt
	QInt QInt::BuHai();

	// Operator ==
	// So sánh hai QInt
	bool operator==(const QInt& so);
	
	// Operator |
	// Tham số:	QInt so, số cần or với
	// Trả về: Trả về QInt mới là kết quả của phép or hai QInt
	QInt operator|(QInt so);

	// Operator &
	// Tham số:	QInt so, số cần and với
	// Trả về: Trả về QInt mới là kết quả của phép and hai QInt
	QInt operator&(QInt so);

	// Operator ^
	// Tham số:	QInt so, số cần xor với
	// Trả về: Trả về QInt mới là kết quả của phép xor hai QInt
	QInt operator^(QInt so);

	// Operator ~
	// Trả về: Trả về QInt mới là kết quả cua phép Not của QInt
	QInt operator~();

	// Phép dịch phải
	// Tham số: số bit cần dịch
	QInt operator>>(int num);
	
	// Phép dịch trái
	// Tham số: số bit cần dịch
	QInt operator<<(int num);

	// Phép lấy chỉ số
	// Tham số: chỉ số bit của QInt (0->127)
	char operator[](int index) const;
};