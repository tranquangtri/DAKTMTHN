#include <iostream>
#include "QInt.h"
#include <string>
#include <fstream>


void main()
{
	// MƠ FILE ĐỂ ĐỌC
	fstream input("input.txt", ios_base::in);
	// MƠ FILE ĐỂ GHI
	fstream output("output.txt", ios_base::out);
	if (!input.good())
	{
		cout << "Khong doc duoc file !" << endl;
		return;
	}
	while (!input.eof())
	{
		int heSoVao = 2, heSoRa = 2;
		QInt ketQua;
		input >> heSoVao;
		heSoRa = heSoVao; // Mặc định để hệ số ra bằng vào

		// Đầu tiên đọc và kiểm tra tham số thứ hai trước vì
		// Để tránh trường hợp chương trình hiểu nhầm chỉ thị
		// Ví dụ: 2 10 + 101, 10 là số nhị phân chứ không phải chỉ thị p2
		string thamSo1, thamSo2, thamSo3;
		input >> thamSo1 >> thamSo2;
		// Nếu tham số 2 là +-*/&|^ thì tiếp tục đọc tham số 3 (là toán hạng phải) và thực hiện phép tính tương ứng
		if (string("+-*/&|^").find(thamSo2) != string::npos)
		{
			input >> thamSo3;
			QInt toanHangTrai(thamSo1, heSoVao);
			QInt toanHangPhai(thamSo3, heSoVao);
			if (thamSo2 == "+")
				ketQua = toanHangTrai + toanHangPhai;
			else if (thamSo2 == "-")
				ketQua = toanHangTrai - toanHangPhai;
			else if (thamSo2 == "*")
			 	ketQua = toanHangTrai * toanHangPhai;
			else if (thamSo2 == "/")
				ketQua = toanHangTrai / toanHangPhai;
			else if (thamSo2 == "&")
				ketQua = toanHangTrai & toanHangPhai;
			else if (thamSo2 == "|")
				ketQua = toanHangTrai | toanHangPhai;
			else if (thamSo2 == "^")
				ketQua = toanHangTrai ^ toanHangPhai;
		}
		else if (thamSo2 == "ROL")
		{
			ketQua = QInt(thamSo1, heSoVao).XoayTrai();
		}
		else if (thamSo2 == "ROR")
		{
			ketQua = QInt(thamSo1, heSoVao).XoayPhai();
		}
		else if (string(">><<").find(thamSo2) != string::npos) // Thiếu xoay trái xoay phải
		{
			int bitDich = 0;
			input >> bitDich;
			QInt toanHangTrai(thamSo1, heSoVao);
			if (thamSo2 == ">>")
				ketQua = toanHangTrai >> bitDich;
			else if (thamSo2 == "<<")
				ketQua = toanHangTrai << bitDich;
		}
		else if (thamSo1 == "~")
		{
			ketQua = ~QInt(thamSo2, heSoVao);
		}
		// Nếu tham số 2 không phải là một toán tử, tức nó là một toán hạng vậy tham số 1 cũng không thê là toán hạng
		// mà là một chỉ thị, bắt đầu kiểm tra chỉ thị
		else if (thamSo1 == "10")
		{
			ketQua = QInt(thamSo2, heSoVao);
			heSoRa = 10;
		}
		else if (thamSo1 == "2")
		{
			ketQua = QInt(thamSo2, heSoVao);
			heSoRa = 2;
		}
		else if (thamSo1 == "16")
		{
			ketQua = QInt(thamSo2, heSoVao);
			heSoRa = 16;
		}
		output << ketQua.ToString(heSoRa) << endl;
	}
	output.close();
	input.close();
}