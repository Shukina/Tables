#include <stdio.h>
#include <tchar.h>
#include "Table.h"
#include "HashTable.h"
#include "BST_tree.h"
#include "Math.h"
#include "stdlib.h"
#include <fstream>
#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{

	//HashTable C(10);
	BST C;
	Record rec;
	C.Read("Text.txt");
	system("cls");
	cout << "Хеш-таблица:" << endl << endl;
	C.Print();
	cout << endl;
	//setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы
	//ofstream fout("TestText.txt"); // создаём объект класса ofstream для записи и связываем его с файлом cppstudio.txt
	//fout << "текст"; // запись строки в файл
	//fout.close(); // закрываем файл


	//char buff[50]; // буфер промежуточного хранения считываемого из файла текста
	//ifstream fin("TestText.txt"); // открыли файл для чтения

	//							  //fin >> buff; // считали первое слово из файла
	//							  //cout << buff << endl; // напечатали это слово

	//fin.getline(buff, 50); // считали строку из файла
	//fin.close(); // закрываем файл
	//cout << buff << endl << endl; // напечатали эту строку

	//cout << "Топ 10 самых частых слов" << endl;
	//cout << "+---------------+--------------+" << endl;
	//cout << "|  слово        |   число слов |" << endl;

	system("pause");
	return 0;
}