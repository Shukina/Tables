#4
#ifndef _BSTNODE_H
#define _BSTNODE_H

#include <iostream>
#include "Table.h"

class BSTNode
{
private:
	Record* middle;
	BSTNode* left;
	BSTNode* right;
public:
	BSTNode ()
	{
		middle = NULL;
		left = NULL;
		right = NULL;
	}
	BSTNode (Record* p)
	{
		middle = p;
		left = NULL;
		right = NULL;
	}

	

	BSTNode (BSTNode& temp)
	{
		middle = temp.GetMiddle();
		left = temp.GetLeft();
		right = temp.GetRight();
	}

	BSTNode*  GetLeft() const
	{
		return left;
	}

	BSTNode*  GetRight() const
	{
		return right;
	}


	void  SetMiddle(Record* _data)
	{
		middle = _data;
	}


	void  SetLeft(BSTNode* _left)
	{
		left = _left;
	}

	void  SetRight(BSTNode* _right)
	{
		right = _right;
	}

	string  GetName() const
	{
		return middle->GetKey();
	}

	int GetCount() const
	{
		return middle->GetValue();
	}

	Record*  GetMiddle()
	{
		return middle;
	}






	
};

#endif