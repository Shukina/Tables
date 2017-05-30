
#ifndef _RECORD_H 
#define _RECORD_H

#include <iostream>
#include <string>

using namespace std;

//typedef Record *PRecord;

typedef string TKey;
typedef int TValue;

class Record {
public:
	TKey key;
	TValue value;
public:
	Record()
	{
		key = "";
		value = 0;
	}

	Record(Record& m) 
	{
		key = m.GetKey();
		value = m.GetValue();
	}

	Record(  TKey _key ,TValue _val) 
	{
		key = _key;
		value = _val;
	}

	string GetKey() const
	{
		return key; 
	}

	int GetValue(void) const
	{
		return value; 
	}

	Record& operator=(const Record& m)
	{
		if (this == &m) {
			return *this;
		}
		key = m.GetKey();
		value = m.GetValue();
		return *this;
	}

	bool operator==(const Record &rec)
	{
		return key == rec.key; 
	}

	/*friend ostream& operator<<(ostream &out, const Record rec) 
	{
		out << "----------|------------" << endl;
		out << rec.key << "            " << rec.value << endl;
		return out;
	}*/
};
#endif