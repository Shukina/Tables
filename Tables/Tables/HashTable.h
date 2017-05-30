#3
#ifndef _HASHTABLE_H
#define _HASHTABLE_H

#include <iostream>
#include <math.h>
#include "Table.h"

class HashTable : public Table
{
private:
	list<Record> *table; //	������ ������ (������, � ������� ��������� �� ������, �� ������ �������)
	int max_size;   // ������������ ����� ������ ���������

	int hashfunc(string str)//��������� ������ ����������
	{
		int temp = 0;
		for (int i = 0; i < str.size(); i++)
		{
			temp += str[i]*exp(i*log(10));
		}
		return (temp % max_size);
	}

public:
	HashTable()
	{
		max_size = 10;
		table = new list<Record>[max_size];
	}

	~HashTable()
	{
		delete [] table;
	}

	void Insert(string key, int p)
	{
		int hash_rec = hashfunc(key);
		table[hash_rec].push_back(Record(key, p));
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
};

#endif