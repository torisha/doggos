#include "Doggos.h"
#include<string>
#include<iostream>
#include<Windows.h>
#include<fstream>

using namespace std;

void Doggo::set_inf()
{
	string nam = "", col = "", sz = "";
	cout << ">>> Ведите информацию\n\n";
	cout << "Кличка: ";
	SetConsoleCP(1251);
	cin.clear();
	//cin.ignore(32767, ' '); //печатает все после пробела
	getline(cin, nam);
	SetConsoleCP(866);
	this->SetNam(nam);
	cout << "\nОкрас: ";
	SetConsoleCP(1251);
	cin.clear();
	getline(cin, col);
	SetConsoleCP(866);
	this->SetCol(col);
	cout << "\nРазмер: ";
	SetConsoleCP(1251);
	cin.clear();
	getline(cin, sz);
	SetConsoleCP(866);
	this->SetSz(sz);
	cout << "\n";
}

void Doggo::show_inf()
{
	cout << ">>> Информация о собаке\n\n";
	cout << "Кличка: " << this->GetNam() << "\n";
	cout << "Окрас: " << this->GetCol() << "\n";
	cout << "Размер: " << this->GetSz() << "\n";

	cout << "\n";
}
