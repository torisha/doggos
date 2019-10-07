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
#include"Factory.h"
#include"LabFactory.h"
#include"ChihFactory.h"
#include"Doggos.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	//сначала выбрать содать догго или загрузить инфу из файла
	//если создать то выбираем породу и записываем инфу и сохраняем в файл

	/*fstream f;
	f.open("Doggos.txt", fstream::in);
	if (!f.is_open())
	{
		cout << "Ошибка открытия файла" << endl;
	}
	else
	{
		char mas[20];
		char chChar;
		string line;
		}

f.close(); */
		/*while (f.get(chChar))
		{
			switch (chChar)
			{


			case'>':

				getline(f, line);
				cout << line << endl;
				break;
			case'<':
				break;

			}}

			///////
				while (!f.eof())
		{

			getline(f, line);
			if (line.at(0) != '<')
			{
				cout << line << "\n";
			}

		}
		*/
	
	

	//LabFactory* lab_f = new LabFactory;
	//ChihFactory* chih_f = new ChihFactory;
	//lab_f->create_doggo()->breed();

	Factory* lab_f = new LabFactory;
	Factory* chih_f = new ChihFactory;
	Factory* factories[] = { lab_f,chih_f }; // An array of creators 
	for (auto&& creator : factories) // Iterate over creators and create products 
	{
		Doggo* dog = creator->create_doggo();
		dog->breed();
		dog->set_inf();
		dog->show_inf();
		delete dog;
	}

	//Doggo* dog1 = lab_f->create_doggo();
	//dog1->breed();
	//dog1->set_inf();
	//dog1->show_inf();

	//Doggo* lab = new Lab;
	//lab->breed();
	
	



	system("pause");
	return 0;
}