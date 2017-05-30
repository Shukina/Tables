
#ifndef _AVLNODE_H
#define _AVLNODE_H

#include <iostream>
#include "Table.h"

class AVLNode
{
private:
	Record* middle;   //����
	unsigned int height; //������ ��������� � ������ �������
	AVLNode* left; //��������� �� ������
	AVLNode* right; //��������� �� �����
public:
	AVLNode() //������� ������ �� 1 �������
	{
		middle = NULL;
		left = NULL;
		right = NULL;
		height = 0;
	}

	AVLNode(Record* k) //������� ������ �� 1 �������
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