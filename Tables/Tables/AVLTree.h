#7
#ifndef _AVLTREE_H
#define _AVLTREE_H

#include <iostream>
#include "Table.h"
#include "AVLNode.h"

class AVL
{
private:
	AVLNode* root;

public:
	AVLNode* GetRight()
	{
		return root->right;
	}

	AVLNode* GetLeft()
	{
		return root->left;
	}

	unsigned int GetHeight(AVLNode* p) // получение высоты вершины
	{
		if (p)
			return p->height;
		else
			return 0; //получим высоту следующим способом : если вершины нет, ответ 0 иначе высота поддерева этой вершины
	}

	int difheight(AVLNode* p) // разность высот между сыновьями
	{
		return GetHeight(p->right) - GetHeight(p->left); // вручную посчитаем разницу
	}

	void fixheight(AVLNode* p) // обновим высоту, если сбалансированность нарушена
	{
		unsigned int hl = GetHeight(p->left); // высота левого сына
		unsigned int hr = GetHeight(p->right); // высота правого сына
		if (hl > hr)
			p->height = hl + 1;
		else
			p->height = hr + 1; // высота вершины - это высота сына с макс высотой плюс 1
	}

	AVLNode* rotateright(AVLNode* p) // правый поворот вокруг p
	{
		AVLNode* q = p->left;//запоминаем левого сына р 
		p->left = q->right;//присваем левому сыну р узлы, которые мжду p и q
		q->right = p;//присваиваем правому сыну q поддерево р
		fixheight(p); //починим дерево
		fixheight(q);
		return q;
	}

	AVLNode* rotateleft(AVLNode* p) // левый поворот вокруг q
	{
		AVLNode* q = p->right; //запоминаем правого сына р 
		p->right = q->left;//присваем правому сыну р узлы, которые мжду p и q
		q->left = p;//присваиваем левому сыну q поддерево р
		fixheight(p); //починим дерево
		fixheight(q);
		return p;
	}


	AVLNode* balance(AVLNode* p) // балансировка узла p
	{
		fixheight(p);
		if (difheight(p) == 2) //если левый сын сильно больше правого сделаем правый поворот
		{
			if (difheight(p->right) < 0)
				p->right = rotateright(p->right);
			return rotateleft(p);
		}
		if (difheight(p) == -2) // если правый сын сибно больше левого сделаем левый поворот
		{
			if (difheight(p->left) > 0)
				p->left = rotateleft(p->left);
			return rotateright(p);
		}
		return p; // балансировка не нужна
	}

	AVLNode* insert(AVLNode* p, int k) // вставка ключа k в дерево с корнем p
	{
		if (!p) 
			return new AVLNode(k); // если дерево пустое создадим его
		if (k<p->key) //если ключ больше вершины, вызомем это рекурсивно от левого сына
			p->left = insert(p->left, k);
		else
			p->right = insert(p->right, k); // если ключ меньше вершины, вызовем рекурсию от правго сына
		return balance(p); // отбалансируем вершину
	}

	AVLNode* findmin(AVLNode* p) // поиск узла с минимальным ключом в дереве p 
	{
		if (p->left)
			return findmin(p->left);//если есть левый сын, идем в него иначе ответ в этой вершине
	}

	AVLNode* removemin(AVLNode* p) // удаление узла с минимальным ключом из дерева p
	{
		if (p->left == 0) // если нет левого сына удалим эту вершину
			return p->right;
		p->left = removemin(p->left); // иначе идем в левого сына
		return balance(p); //балансируем дерево
	}

	AVLNode* remove(AVLNode* p, int k) // удаление ключа k из дерева p
	{
		if (!p) return 0; // если дерево пустое, уходим
		if (k < p->key) //если элемент меньше вершины идем в левого сына
			p->left = remove(p->left, k);
		else if (k > p->key)
			p->right = remove(p->right, k);  // если элемент больше вершины, идем в правого сына
		else //  мы пришли в вершину, которую надо удалить
		{
			AVLNode* q = p->left;
			AVLNode* r = p->right;
			delete p; //удалим физически эту вершину
			if (!r) return q;
			AVLNode* min = findmin(r);
			min->right = removemin(r); //правый сын минимальной вершины - это правое поддерево удаляемой без минимума
			min->left = q; // левый сын минимальной вершины - левый сын удаляемой
			return balance(min); // балансируем меньшую вершину
		}
		return balance(p); // мы ничего не нашли, балансируем дерево
	}

	void DeleteALL(AVLNode* node) //??
	{
		if (node == NULL)
		{
			return;
		}
		if (node->left!= NULL)
			DeleteALL(node->left);
		if (node->right != NULL)
			DeleteALL(node->right);
		//if (node->GetLeft()== NULL && node->GetRight() == NULL)
		delete[] node;
	}

	~AVL()
	{
		DeleteALL(root);
	}
};
#endif
