#3
#ifndef _HASHTABLE_H
#define _HASHTABLE_H

#include <iostream>
#include "Table.h"

class HashTable : public Table
{
private:
	list<Record> **table; //	СПИСОК СПИСКОВ (массив, в котором указатели на списки, но массив большой)
	int max_size;   // максимальная длина списка указтелей

	int hashfunc(string str)//получение номера размещения
	{
		int temp = 0;
		for (int i = 0; i < str.size(); i++)
		{
			temp += str[i];
		}
		return (temp % max_size);
	}

	//int Find(string key) { return 0; };

public:
	HashTable()
	{
		max_size = 10;
		table = new list<Record>*[max_size];
		for (int i = 0; i < max_size; i++)
		{
			table[i] = new list < Record>;
		}
	}

	~HashTable()
	{
		for (int i = 0; i < max_size; i++)
		{
			delete [] table[i];
		}
		delete [] table;
	}

	void Insert(string key, int p)
	{
		int hash_rec = hashfunc(key);
		table[hash_rec]->push_back(Record(key, p));
	}

	void Delete(string key)
	{
		int hash_rec = hashfunc(key);
		table[hash_rec]->remove(Record(key, NULL));
	}

	int GetNode(string key)
	{
		int hash_rec = hashfunc(key);
		list<Record>::const_iterator iterator;
		for (iterator = table[hash_rec]->begin(); iterator != table[hash_rec]->end(); ++iterator) {
			if (key == iterator->GetKey())
			{
				return iterator->GetValue();
			}
		}
		return NULL;
	}

	
};






#endif