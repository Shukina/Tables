
#ifndef _AVLNODE_H
#define _AVLNODE_H

#include <iostream>
#include "Table.h"

class AVLNode
{
private:
	Record* middle;   //ключ
	unsigned int height; //высота поддерева в данной вершине
	AVLNode* left; //указатель на правый
	AVLNode* right; //указатель на левый
public:
	AVLNode() //создает дерево из 1 вершины
	{
		middle = NULL;
		left = NULL;
		right = NULL;
		height = 0;
	}

	AVLNode(Record* k) //создает дерево из 1 вершины
	{
		middle = k;
		left = right = NULL;
		height = 1;
	}

	AVLNode(AVLNode& temp)
	{
		middle = temp.GetMiddle();
		left = temp.GetLeft();
		right = temp.GetRight();
	}

	AVLNode*  GetLeft() const
	{
		return left;
	}

	AVLNode*  GetRight() const
	{
		return right;
	}


	void  SetMiddle(Record* _data)
	{
		middle = _data;
	}


	void  SetLeft(AVLNode* _left)
	{
		left = _left;
	}

	void  SetRight(AVLNode* _right)
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

	unsigned int GetHeight()
	{
		return height;
	}
	void SetHeight(unsigned int len)
	{
		height = len;
	}

};

#endif