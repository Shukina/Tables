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
	/*virtual int Find(string word) = 0;*/
public:
	//virtual void Insert(string word, int p) = 0;
	//virtual void Delete(string word) = 0;
	//virtual int GetNode(string key) = 0;

	
	/*
	void Print() {
		for (Reset(); !IsEnd(); GoNext())
		{
			cout << GetCurr().key << "  -  " << GetCurr().value << endl;
		}
	}*/

	/*oid Read(char* pFileName)
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
	}*/
	;
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

 

