#include <iostream>
#include "QInt.h"
#include <string>
#include <fstream>


void main()
{
	// ĐỌC FILE
	fstream input("input.txt", ios_base::in);
	fstream output("output.txt", ios_base::out);
	if (!input.good())
	{
		cout << "Khong doc duoc file !" << endl;
		return;
	}
	while (!input.eof())
	{
		string heSo, toanTu;
		input >> heSo;

		string chiThiTam;
		input >> chiThiTam;
		// Trường hợp có chỉ thị p2
		if ((chiThiTam == "2") || (chiThiTam == "10") || (chiThiTam == "16"))
		{
			toanTu = chiThiTam;
			string soCanChuyen;
			input >> soCanChuyen;

			// Chuyển sang dãy nhị phân
			if (toanTu == "2")
			{

			}
			// Chuyển sang dãy thập phân
			else if (toanTu == "10")
			{

			}
			// Chuyển sang dãy thập lúc phân
			else if (toanTu == "16")
			{

			}
		}
		else if (chiThiTam == "~")
		{
			string soCanNot;
			input >> soCanNot;
		}
		// Nếu không có chỉ thị p2 -> toán tử hai ngôi
		else
		{
			string toanHangTrai = chiThiTam;
			input >> toanTu;
			if ((toanTu == "ROL") || (toanTu == "ROR"))
			{

			}
			else if ((toanTu == ">>") || (toanTu == "<<"))
			{
				int soBitCanDich;
				input >> soBitCanDich;
				if (toanTu == ">>")
				{
					QInt ketQua = QInt(toanHangTrai) >> soBitCanDich;
					output << ketQua.ToBinary() << endl;
				}
				else if (toanTu == "<<")
				{
					QInt ketQua = QInt(toanHangTrai) << soBitCanDich;
					output << ketQua.ToBinary() << endl;
				}
			}
			else
			{
				string toanHangPhai;
				input >> toanHangPhai;
				if (toanTu == "+")
				{
					QInt ketQua = QInt(toanHangTrai) + QInt(toanHangPhai);
					output << ketQua.ToBinary() << endl;
				}
				else if (toanTu == "-")
				{
					QInt ketQua = QInt(toanHangTrai) - QInt(toanHangPhai);
					output << ketQua.ToBinary() << endl;
				}
				else if (toanTu == "*")
				{
					QInt ketQua = QInt(toanHangTrai) * QInt(toanHangPhai);
					output << ketQua.ToBinary() << endl;
				}
				else if (toanTu == "/")
				{
					QInt ketQua = QInt(toanHangTrai) / QInt(toanHangPhai);
					output << ketQua.ToBinary() << endl;
				}
				else if (toanTu == "&")
				{
					QInt ketQua = QInt(toanHangTrai) & QInt(toanHangPhai);
					output << ketQua.ToBinary() << endl;
				}
				else if (toanTu == "|")
				{
					QInt ketQua = QInt(toanHangTrai) | QInt(toanHangPhai);
					output << ketQua.ToBinary() << endl;
				}
				else if (toanTu == "^")
				{
					QInt ketQua = QInt(toanHangTrai) ^ QInt(toanHangPhai);
					output << ketQua.ToBinary() << endl;
				}
			}
		}
	}
	input.close();
}