
#ifndef _AVLTREE_H
#define _AVLTREE_H

#include <iostream>
#include "Table.h"
#include "AVLNode.h"

class AVL
{
private:
	AVLNode* root;


	unsigned int GetHeight(AVLNode* p) // получение высоты вершины
	{
		if (p)
			return p->GetHeight();
		else
			return 0; //получим высоту следующим способом : если вершины нет, ответ 0 иначе высота поддерева этой вершины
	}

	int difheight(AVLNode* p) // разность высот между сыновьями
	{
		return GetHeight(p->GetRight()) - GetHeight(p->GetLeft()); // вручную посчитаем разницу
	}

	void fixheight(AVLNode* p) // обновим высоту, если сбалансированность нарушена
	{
		unsigned int hl = GetHeight(p->GetLeft()); // высота левого сына
		unsigned int hr = GetHeight(p->GetRight()); // высота правого сына
		if (hl > hr)
			p->SetHeight(hl + 1);
		else
			p->SetHeight(hr + 1); // высота вершины - это высота сына с макс высотой плюс 1
	}

	AVLNode* rotateright(AVLNode* p) // правый поворот вокруг p
	{
		AVLNode* q = p->GetLeft();//запоминаем левого сына р 
		p->SetLeft(q->GetRight());//присваем левому сыну р узлы, которые мжду p и q
		q->SetRight(p);//присваиваем правому сыну q поддерево р
		fixheight(p); //починим дерево
		fixheight(q);
		return q;
	}

	AVLNode* rotateleft(AVLNode* p) // левый поворот вокруг q
	{
		AVLNode* q = p->GetRight(); //запоминаем правого сына р 
		p->SetRight(q->GetLeft());//присваем правому сыну р узлы, которые мжду p и q
		q->SetLeft(p);//присваиваем левому сыну q поддерево р
		fixheight(p); //починим дерево
		fixheight(q);
		return p;
	}


	AVLNode* balance(AVLNode* p) // балансировка узла p
	{
		fixheight(p);
		if (difheight(p) == 2) //если левый сын сильно больше правого сделаем правый поворот
		{
			if (difheight(p->GetRight()) < 0)
				p->SetRight(rotateright(p->GetRight()));
			return rotateleft(p);
		}
		if (difheight(p) == -2) // если правый сын сибно больше левого сделаем левый поворот
		{
			if (difheight(p->GetLeft()) > 0)
				p->SetLeft(rotateleft(p->GetLeft()));
			return rotateright(p);
		}
		return p; // балансировка не нужна
	}

	void Insert(AVLNode* node, AVLNode* new_node) // вставка ключа k в дерево с корнем p
	{
		if (node == NULL)
			node = new AVLNode(*new_node);

		if (new_node->GetName() < node->GetName()) //если новый ключ меньше ключа корня, вызомем вставку рекурсивно от левого сына
			Insert(node->GetLeft(), new_node);
		else
			Insert(node->GetRight(), new_node); // если новый ключ больше ключа корня, вызовем рекурсию от правго сына

		balance(node); // отбалансируем вершину
	}

	AVLNode* Search(AVLNode* r, string key) //поиск в дереве с корнем r узла с ключом key
	{
		if (r == NULL || r->GetMiddle() == NULL)
			return NULL;

		if (key == r->GetName())
			return r;

		if (key < r->GetName())
			return Search(r->GetLeft(), key);
		else
			return Search(r->GetRight(), key);
	}

	AVLNode* findmin(AVLNode* p) // поиск узла с минимальным ключом в дереве p 
	{
		if (p->GetLeft())
			return findmin(p->GetLeft());//если есть левый сын, идем в него иначе ответ в этой вершине
	}

	AVLNode* removemin(AVLNode* p) // удаление узла с минимальным ключом из дерева p
	{
		if (p->GetLeft() == 0) // если нет левого сына удалим эту вершину
			return p->GetRight();
		p->SetLeft(removemin(p->GetLeft())); // иначе идем в левого сына
		return balance(p); //балансируем дерево
	}
public:

	void Insert(Record node)
	{
		if (root->GetMiddle == NULL)
			root->SetMiddle(&node);
		else
		{
			AVLNode* temp = new AVLNode(&node);
			Insert(root, temp);
		}
	}

	Record* Search(string key) //поиск записи с ключом key
	{
		AVLNode* res = Search(root, key);
		if (res == NULL)
			return NULL;
		else
			return res->GetMiddle();
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
			return;

		if (node->GetLeft() != NULL)
			DeleteALL(node->GetLeft());
		if (node->GetRight() != NULL)
			DeleteALL(node->GetRight());
		//if (node->GetLeft()== NULL && node->GetRight() == NULL)
		delete[] node;
	}

	~AVL()
	{
		DeleteALL(root);
	}
};
#endif
