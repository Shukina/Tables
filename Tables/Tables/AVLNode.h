#6
#ifndef _AVLNODE_H
#define _AVLNODE_H

#include <iostream>
#include "Table.h"

class AVLNode
{
public:
	int key;   //����
	unsigned int height; //������ ��������� � ������ �������
	AVLNode* left; //��������� �� ������
	AVLNode* right; //��������� �� �����

	AVLNode(int k) //������� ������ �� 1 �������
	{
		key = k;
		left = right = NULL;
		height = 1;
	}

};

#endif