#include "Doggos.h"
#include"Labrador.h"
#include"Chih.h"
#include<string>
#include<iostream>
#include<Windows.h>
#include<fstream>

using namespace std;

void Doggo::modify(int ch, string inf)
{
	if (ch == 1)
	{
		this->SetNam(inf);
	}
	if (ch == 2)
	{
		this->SetCol(inf);
	}
	if (ch == 3)
	{
		this->SetSz(inf);
	}
}

void Doggo::set_inf()
{
	string nam = "", col = "", sz = "";
	cout << ">>> ������ ����������\n\n";
	cout << "������: ";
	SetConsoleCP(1251);
	cin.clear();
	
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

void Doggo::write_inf(int cnt, string file)
{
	
	fstream f;
	f.open(file, fstream::in | fstream::out | fstream::app );
	string str = " ";
	if (cnt == 0)
	{
		f << this->GetNam() << "\n";
		f << this->GetCol() << "\n";
		f << this->GetSz() << "\n";
	}
	else
	{
		
		
		f << this->GetNam() << "\n";
		f << this->GetCol() << "\n";
		f << this->GetSz() << "\n";
	}
	



	cout << "\n>>>���������� �������� � ����\n";

	f.close();
}

void Doggo::read_inf(int cnt)
{
	//��������� ������ ��� ������  cnt = 0 lab, 3 chih 
	fstream f;
	string str = " ";
	
	f.open("Doggos.txt", fstream::in);
	if (!f.is_open())
	{
		cout << "������ �������� �����" << endl;
	}
	else
	{
		if (cnt == 0)
		{
			getline(f, str);
			this->SetNam(str);
			getline(f, str);
			this->SetCol(str);
			getline(f, str);
			this->SetSz(str);
		}
		else
		{
			
			for (int i = 0; i < cnt; i++)
			{
				getline(f, str);
			}
				getline(f, str);
				this->SetNam(str);
				getline(f, str);
				this->SetCol(str);
				getline(f, str);
				this->SetSz(str);
		}
		
		
	}
	f.close();
}

