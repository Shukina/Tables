#6
#ifndef _AVLNODE_H
#define _AVLNODE_H

#include <iostream>
#include "Table.h"

class AVLNode
{
public:
	int key;   //ключ
	unsigned char height; //высота поддерева в данной вершине
	AVLNode* left; //указатель на правый
	AVLNode* right; //указатель на левый

	AVLNode(int k) //создает дерево из 1 вершины
	{
		key = k;
		left = right = NULL;
		height = 1;
	}

};

#endif