#include "Doggos.h"
#include<string>
#include<iostream>
#include<Windows.h>
#include<fstream>

using namespace std;

void Doggo::set_inf()
{
	string nam = "", col = "", sz = "";
	cout << ">>> ������ ����������\n\n";
	cout << "������: ";
	SetConsoleCP(1251);
	cin.clear();
	//cin.ignore(32767, ' '); //�������� ��� ����� �������
	getline(cin, nam);
	SetConsoleCP(866);
	this->SetNam(nam);
	cout << "\n�����: ";
	SetConsoleCP(1251);
	cin.clear();
	getline(cin, col);
	SetConsoleCP(866);
	this->SetCol(col);
	cout << "\n������: ";
	SetConsoleCP(1251);
	cin.clear();
	getline(cin, sz);
	SetConsoleCP(866);
	this->SetSz(sz);
	cout << "\n";
}

void Doggo::show_inf()
{
	cout << ">>> ���������� � ������\n\n";
	cout << "������: " << this->GetNam() << "\n";
	cout << "�����: " << this->GetCol() << "\n";
	cout << "������: " << this->GetSz() << "\n";

	cout << "\n";
}
