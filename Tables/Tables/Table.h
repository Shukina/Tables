//#2
#ifndef _TABLE_H
#define _TABLE_H


#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "Record.h"

using namespace std;

class Table {
protected:
	int DataCount;//количество записей
public:
	Table()
	{
		DataCount = 0;
	}

	~Table() {}

	int GetDataCount() const 
	{ 
		return DataCount; 
	}


	int isEmpty() //проверка на пустоту
	{ 
		return DataCount == 0;
	}

	virtual int IsFull() = 0; //проверка на полноту
	virtual int Find(TKey _key) = 0; //найти запись 
	virtual void Delete(TKey _key) = 0; //удалить запись
	virtual void Insert(Record rec) = 0;//вставить запись
	virtual void Reset() = 0; //вернуться в начало
	virtual void GoNext() = 0; //перейти к следующей записи
	virtual int IsEnd() = 0; //таблица завершена?
	virtual Record GetCurr() = 0; 

	
	/*
	void Print() {
		for (Reset(); !IsEnd(); GoNext())
		{
			cout << GetCurr().key << "  -  " << GetCurr().value << endl;
		}
	}

	void Read(char* pFileName)
	{
		string str = "";
		ifstream TxtFile(pFileName);

		if (!TxtFile.fail())
		{
			while (!TxtFile.eof()) str += TxtFile.get();
			TxtFile.close();
		}
		else cout << "File does not exist" << endl;

		for (int i = 0; i <= str.length(); i++)
		{
			char tmp = str[i];
			if (((int)tmp >= 65) && ((int)tmp <= 90))
			{
				tmp += 32;
			}
			str[i] = tmp;
		}

		string tmp = "";
		Record rec;

		for (int i = 0; i <= str.length(); i++)
		{
			if (str[i] == ' ')
			{
				rec.key = tmp;
				rec.value = 1;
				Insert(rec);
				tmp = "";
			}
			else
			{
				tmp += str[i];
			}
		}
	}*/
};
#endif// !_TABLE_H

//*friend*/ ostream& operator<< (ostream &os, Table &tab)//?????
//	{
//		int i = 0;
//		cout << "Table printing" << endl; 
//		for (tab.Reset(); !tab.IsEnd(); tab.GoNext())
//		{
//			os << i << " Key: " << tab.GetCurr.GetKey() << " Val: " << tab.GetCurr.GetValue();
//			os << endl; i++;
//		}
//		return os;
//	}

 

