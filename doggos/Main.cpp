/*
������� ����� ������� �����, � ���������� ������������� �������� ������ ����� ��������: 
��������, �����, �������, ��������, ������, ��������. 
������ ����� ����������� ������ ������ � ��� ������������� 
(������, �����, ���, ���� ��������, �������, ��� ���������, 
������������ ���������, ��������, �������� ����� �� �������/������� (�����)), 
� ������� ��� �� ���������������� �����. ������������ ������� ���������� �����. 
��������� �������� �������� � ��� �� �������������� ������������ � �������� ����,
���������� �������� ��������� �� �������.
*/

#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
#include"Factory.h"
#include"LabFactory.h"
#include"ChihFactory.h"
#include"PitFactory.h"
#include"Doggos.h"
using namespace std;

void copy()//������� f1, ������������� f2
{
	
	if (remove("Doggos.txt") != 0)             // �������� ����� file.txt
		std::cout << "������ �������� �����n";
	else
		std::cout << "���� ������� �����n";
	rename("Doggos2.txt", "Doggos.txt");
}

void clean(string file)
{
	fstream f;
	f.open(file, fstream::out | fstream::trunc);
	f.close();

}

bool empty(string file)//true = ������
{
	fstream f;
	f.open(file, fstream::out );
	if (!f.is_open()) { cout << "Not open\n"; }// ���� �� ��������
	else if (f.peek() == EOF) { return true; cout << "Fail empty\n"; } // ���� ������ ������ ����� �����
	else return false;
	f.close();
}

//������ ����, �������� ����, �������� � ����, ��������� ����, �������� ����, ������� ���� �� �����
int main()
{
	setlocale(LC_ALL, "Russian");
	
	int cnt = 0;
	Factory* lab_f = new LabFactory;
	Factory* chih_f = new ChihFactory;
	Factory* pit_f = new PitFactory;
	Factory* factories[] = { lab_f,chih_f, pit_f }; // An array of creators 
	int br = 0;
	int ch = 0;
	string inf = "";
	Doggo* dog;

	char number;
	do
	{
		cout << "\n--- ���� � ����� ��� ������,\n";
		cout << "�� ������� �������� �� (3) ---\n";
		cout << "*********����**********" << endl << endl;
		cout << "1) ������������� ���������� " << endl << endl;
		cout << "2) �������� ����������" << endl << endl;
		cout << "3) �������� ���������� " << endl << endl;
		cout << "4) �������� ����" << endl << endl;
		//cout << "5) ������� �� �����" << endl << endl;

		//cout << "6) �������� � �����" << endl << endl;
		//cout << "7) �������� �����" << endl << endl;
		//cout << "8) �����" << endl << endl;
		cout << "***********************" << endl << endl;
		cout << "������� �������: ";
		cin >> number;
		cout << "***********************" << endl << endl;
		cout << endl << endl;
		
		
		try
		{
			switch (number)
			{
			case'1':
				cnt = 0;
				cout << ">>> ��������\n\n";
				cout << "1) ����� ������: ��������(0) ���(1) �������(2)\n";
				cin >> br;
				cout << "2) ����� ����� ��� ��������������:\n" << "������(1) �����(2) ������(3)\n";
				cin >> ch;
				cout << "3) ���� ����� ����������:\n";
				SetConsoleCP(1251);
				cin.ignore(7777, '\n');
				getline(cin, inf);
				SetConsoleCP(866);
				cout << inf;
				
				for (auto&& creator : factories)
				{
					 dog = creator->create_doggo();

					if (creator == factories[br])
					{
						dog->breed();
						dog->read_inf(cnt);
						dog->show_inf();
						dog->modify(ch, inf);
						dog->show_inf();

					}
					else
					{
						dog->read_inf(cnt);

					}

					dog->write_inf(cnt,"Doggos2.txt");
					cnt += 3;
					delete dog;
				}

				copy();
				cout << endl << endl;
				break;
			case'2':
				cnt = 0;
				cout << ">>>������\n\n";
				cout << "�������� ���������� � ���������(0) ����(1) �������(2)\n";
				cout << "��� ��� ���� ������� (9)\n";
				cin >> br;
				if (br == 9)
				{
					for (auto&& creator : factories)
					{
						 dog = creator->create_doggo();
						dog->breed();
						dog->read_inf(cnt);
						dog->show_inf();
						
						cnt += 3;
						delete dog;
					}
				}
				else
				{
					for (auto&& creator : factories)
					{
						 dog = creator->create_doggo();
						if (creator == factories[br])
						{
							dog->breed();
							dog->read_inf(cnt);
							dog->show_inf();
						}
											
						cnt += 3;
						delete dog;
					}
				}
			
				cout << endl << endl;
				break;
			case'3':
				cnt = 0;
				cout << ">>>����������/������ ������\n\n";
				//�������� ���� �������
				clean("Doggos.txt");
				cout << "(���� �� ������ ������� ��-��, ������� ������)\n";
				for (auto&& creator : factories)
				{
					 dog = creator->create_doggo();
					
						dog->breed();
						dog->set_inf();
						dog->write_inf(cnt, "Doggos.txt");		
					cnt += 3;
					delete dog;
				}
				//copy();
				cout << endl << endl;
				break;
			case'4':
				cout << ">>>���� ������\n";
				clean("Doggos.txt");

				cout << endl << endl;
				break;
			case'5':
				
				cout << endl << endl;
				break;
			case'6':
				
				break;
			case'7':
				
				break;
			case'8':
				break;
			}
		}
		catch (const char* msg)
		{
			cout << endl << msg << endl;
		}
	} while (number != '8');



	for (auto&& creator : factories) // Iterate over creators and create products 
	{
		
		Doggo* dog = creator->create_doggo();
		dog->breed();
		//dog->set_inf();
		//dog->show_inf();
		//dog->write_inf();
		dog->read_inf(cnt);//
		dog->show_inf();//
		delete dog;
		cnt += 3;//
	}

	
		//��������� �� ����� � �������� � ����� �������� ���������
	
	

	

	
	system("pause");
	return 0;
}