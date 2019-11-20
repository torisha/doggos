/*
Создать класс «Породы собак», в результате использования которого клиент может получить: 
лабрадор, хаски, шнауцер, чихуахуа, пудель, спаниель. 
Клиент имеет возможность выбора породы и его характеристик 
(кличка, окрас, пол, дата рождения, размеры, имя владельца, 
наименование питомника, характер, описание ухода за шерстью/собакой (текст)), 
с консоли или из соответствующего файла. Использовать паттерн «Фабричный метод». 
Результат создания животных и все их характеристики записываются в выходной файл,
содержимое которого разделено по породам.
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

void copy()//удалить f1, переименовать f2
{
	
	if (remove("Doggos.txt") != 0)             // удаление файла file.txt
		std::cout << "Ошибка удаления файлаn";
	else
		std::cout << "Файл успешно удалёнn";
	rename("Doggos2.txt", "Doggos.txt");
}

void clean(string file)
{
	fstream f;
	f.open(file, fstream::out | fstream::trunc);
	f.close();

}

bool empty(string file)//true = пустой
{
	fstream f;
	f.open(file, fstream::out );
	if (!f.is_open()) { cout << "Not open\n"; }// если не открылся
	else if (f.peek() == EOF) { return true; cout << "Fail empty\n"; } // если первый символ конец файла
	else return false;
	f.close();
}

//ввести инфу, показать инфу, записать в файл, прочитать файл, изменить инфу, удалить инфу из файла
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
		cout << "\n--- Если в файле нет данных,\n";
		cout << "то сначала запишите их (3) ---\n";
		cout << "*********МЕНЮ**********" << endl << endl;
		cout << "1) Редактировать информацию " << endl << endl;
		cout << "2) Показать информацию" << endl << endl;
		cout << "3) Записать информацию " << endl << endl;
		cout << "4) Очистить файл" << endl << endl;
		//cout << "5) Вывести на экран" << endl << endl;

		//cout << "6) Записать в файлы" << endl << endl;
		//cout << "7) Очистить файлы" << endl << endl;
		//cout << "8) Выход" << endl << endl;
		cout << "***********************" << endl << endl;
		cout << "Введите команду: ";
		cin >> number;
		cout << "***********************" << endl << endl;
		cout << endl << endl;
		
		
		try
		{
			switch (number)
			{
			case'1':
				cnt = 0;
				cout << ">>> РЕДАКТОР\n\n";
				cout << "1) Выбор породы: лабрадор(0) чих(1) питбуль(2)\n";
				cin >> br;
				cout << "2) Выбор графы для редактирования:\n" << "кличка(1) окрас(2) размер(3)\n";
				cin >> ch;
				cout << "3) Ввод новой информации:\n";
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
				cout << ">>>ДАННЫЕ\n\n";
				cout << "Показать информацию о лабрадоре(0) чихе(1) питбуле(2)\n";
				cout << "или обо всех породах (9)\n";
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
				cout << ">>>ОБНОВЛЕНИЕ/ЗАПИСЬ ДАННЫХ\n\n";
				//очистить файл сначала
				clean("Doggos.txt");
				cout << "(если не хотите вводить ин-фу, вводите пробел)\n";
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
				cout << ">>>Файл очищен\n";
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

	
		//считывать из файла и изменять и потом записать изменения
	
	

	

	
	system("pause");
	return 0;
}