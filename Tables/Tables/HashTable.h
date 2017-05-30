
#ifndef _HASHTABLE_H
#define _HASHTABLE_H

#include <iostream>
#include <math.h>
#include "Table.h"

class HashTable : public Table
{
private:
	list<Record> *table; //	массив списка (массив, в котором указатели на списки, но массив большой)
	int max_size;   // максимальная длина списка указтелей

	int hashfunc(string str)//получение номера размещения
	{
		int temp = 0;
		for (int i = 0; i < (int)str.size(); i++)
		{
			temp += (int)(str[i]*exp(i*log(10)));
		}
		return (temp % max_size);
	}

public:
	HashTable()
	{
		max_size = 10;
		table = new list<Record>[max_size];
	}
	HashTable(int _size)
	{
		max_size = _size;
		table = new list<Record>[max_size];
	}

	~HashTable()
	{
		delete [] table;
	}

	void Insert(Record p)
	{
		int hash_rec = hashfunc(p.GetKey() );
		table[hash_rec].push_back(Record( p));
	}

	void Delete(string key)
	{
		int hash_rec = hashfunc(key);
		table[hash_rec].remove(Record(key, NULL));
	}

	int GetNode(string key)
	{
		int hash_rec = hashfunc(key);
		list<Record>::const_iterator iterator;
		for (iterator = table[hash_rec].begin(); iterator != table[hash_rec].end(); ++iterator)
		{
			if (key == iterator->GetKey())
				return iterator->GetValue();
		}
		return NULL;
	}

	void Print()
	{
		Record temp;
		for (int i = 0; i < max_size; i++)
		{
			while (table[i].size())
			{
				temp = table[i].front();
				cout << i << ") hash = " << hashfunc(temp.GetKey() ) << " key = " << temp.GetKey() << " data = " << temp.GetValue() << '\n';
			}
		}
	}

	void Read(char* pFileName)
	{
		string str = "";
		ifstream TxtFile(pFileName);

		if (!TxtFile.fail())
		{
			while (!TxtFile.eof())
				str += TxtFile.get();
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
	}
};

#endif