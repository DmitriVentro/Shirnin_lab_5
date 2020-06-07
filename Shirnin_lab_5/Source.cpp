#include <iostream>
#include <fstream>
#include <string>
#include <string.h>


using namespace std;

//Наша структура
struct Bus
{
	int busnum;
	string shofer_secondname;
	string shofer_othername;
	int pathnum;
	float timedur;
};

int CountBus();
void FillBus(Bus* BS, int n);
void FindOclod(Bus* BS, int n);
void Find_Timedur(Bus* BS, int n);



int main()
{
	setlocale(LC_ALL, "Russian");

	int n;
	n = CountBus();

	Bus* BS = new Bus[n];
	FillBus(BS, n);

	cout << "Весь список аавтобусов:";
	for (int i = 0; i < n; i++)
		cout << endl << BS[i].busnum << "  " << BS[i].shofer_secondname + " " + BS[i].shofer_othername << "  " << BS[i].pathnum << "  " << BS[i].timedur;


	FindOclod(BS, n); //Вывод сех книг Толстого

	Find_Timedur(BS, n); //Вывод книг по ценнику с условиями из лабораторной

	return 0;
}




void Find_Timedur(Bus* BS, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (strcmp(BS[i].shofer_secondname.c_str(), BS[j].shofer_secondname.c_str()) < 0)
				swap(BS[i], BS[j]);

	cout << endl << endl << "Список маршрутов длинее 60 минут:";
	for (int i = 0; i < n; i++)
		if (BS[i].timedur > 60)
			cout << endl << BS[i].busnum << "  " << BS[i].shofer_secondname + " " + BS[i].shofer_othername << "  " << BS[i].pathnum << "  " << BS[i].timedur;
}



void FindOclod(Bus* BS, int n)
{
	cout << endl << endl << "Информацио об водителе Oclod:";
	for (int i = 0; i < n; i++)
		if (BS[i].shofer_secondname == "Oclod")
			cout << endl << BS[i].busnum << "  " << BS[i].shofer_secondname + " " + BS[i].shofer_othername << "  "
			<< BS[i].pathnum << "  " << BS[i].timedur;
}


int CountBus()
{
	string str;
	int n = 0;


	ifstream file; //Входной поток
	file.open("input.txt"); //Открыли файл с данными

	//Пока файл не кончился
	while (!file.eof())
	{
		getline(file, str);  //считываем строки по кол-ву строк, которые занимают данные по одной книге
		getline(file, str);
		getline(file, str);
		getline(file, str);
		getline(file, str);  // + считываем пробел после данных
		n++;                 // счётчик книг +1
	}

	file.close();  //Закрыли файл

	return n;    //вернуть подсчитанное кол-во книг
}

//Заполняем массив данными из файла
void FillBus(Bus* BS, int n)
{
	int k = 0;
	Bus temp;

	ifstream file;  //входной поток
	file.open("input.txt"); //Открыли файл


	while (!file.eof())
	{
		file >> temp.busnum;
		file >> temp.shofer_secondname;
		file >> temp.shofer_othername;
		file >> temp.pathnum;
		file >> temp.timedur;

		BS[k] = temp;

		k++;
	}

	file.close();  //закрываем файл
}


