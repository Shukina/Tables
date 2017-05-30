#5
#ifndef _BSTTREE_H
#define _BSTTREE_H

#include <iostream>
#include "Table.h"
#include "BST_Node.h"

class BST
{
private:
	BSTNode* root;

	BSTNode* Search(BSTNode* r, string key) //поиск в дереве с корнем r узла с ключом key
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

	BSTNode* FindMin(BSTNode* r) //поиск узла с минимальным ключом в поддереве с корнем r
	{
		if (r->GetLeft() == NULL)
			return r;
		else
			return FindMin(r->GetLeft());
	}

	BSTNode* Merge(BSTNode* l, BSTNode* r) //слияние левого и правого сына при удалении отца(левое поддерево становится минимумом в правом поддереве)
	{
		if (r == NULL || r->GetMiddle() == NULL)
			return l;

		if (l == NULL || l->GetMiddle() == NULL) 
			return r;

		FindMin(r)->SetLeft(l);//минимуму правго сына присваивается левый сын
		return r;
	}

	void Delete(BSTNode* r, string key) 
	{

		if (key < r->GetName())
		{
			if (r->GetLeft()->GetName() == key)
				r->SetLeft(Merge(r->GetLeft()->GetLeft(), r->GetLeft()->GetRight()));
			else 
				Delete(r->GetLeft(), key);
		}
		if (key > r->GetName()) 
		{
			if (r->GetRight()->GetName() == key) 
				r->SetRight(Merge(r->GetRight()->GetLeft(), r->GetRight()->GetRight()));
			else 
				Delete(r->GetRight(), key);
		}
	}

	void Insert(BSTNode* r, BSTNode* new_node)
	{
		if (new_node->GetName() > r->GetName())
		{
			if (r->GetRight() != NULL)
				Insert(r->GetRight(), new_node);
			else
				r->SetRight(new_node);
		}
		else//new_node->GetName() < r->GetName()
		{
			if (r->GetLeft() != NULL)
				Insert(r->GetLeft(), new_node);
			else 
				r->SetLeft(new_node);
		}
	}

	void DeleteALL(BSTNode* node) 
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
public:
	void Insert(Record* node)
	{
		if (root->GetMiddle == NULL)
			root->SetMiddle(node);

		BSTNode* temp = new BSTNode(node);
		Insert(root, temp);
	}

	void Delete(string key)//удаление записи с ключом key
	{
		if (root->GetMiddle() == NULL) 
			return;

		if (root->GetName() == key)
		{
			if (root->GetRight() != NULL || root->GetLeft() != NULL) 
				root = Merge(root->GetLeft(), root->GetRight());

			root->SetMiddle(NULL);

		}
		Delete(root, key);
	}


	Record* Search(string key) //поиск записи с ключом key
	{
		BSTNode* res = Search(root, key);
		if (res == NULL)
			return NULL;
		else
		return res->GetMiddle();
	}

	~BST()
	{
		DeleteALL(root);
		root = NULL;
	}



};


#endif