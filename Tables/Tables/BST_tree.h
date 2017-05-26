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

	BSTNode* Search(BSTNode* r, string key) 
	{
		if (r == NULL || r->GetMiddle() == NULL) return NULL;

		if (key == r->GetName()) 
		{
			return r;
		}
		if (key < r->GetName()) 
		{
			return Search(r->GetLeft(), key);
		}
		return Search(r->GetRight(), key);
	}

	BSTNode* FindMax(BSTNode* r) 
	{
		if (r->GetRight() == NULL) 
		{
			return r;
		}
		return FindMax(r->GetRight());
	}

	BSTNode* FindMin(BSTNode* r) 
	{
		if (r->GetLeft() == NULL) 
		{
			return r;
		}
		return FindMin(r->GetLeft());
	}

	BSTNode* Merge(BSTNode* l, BSTNode* r) 
	{
		if (r == NULL || r->GetMiddle() == NULL)
		{
			return l;
		}
		if (l == NULL || l->GetMiddle() == NULL) 
		{
			return r;
		}
		FindMin(r)->SetLeft(l);
		return r;
	}

	void Delete(BSTNode* r, string key) 
	{

		if (key < r->GetName())
		{
			if (r->GetLeft()->GetName() == key)
			{
				r->SetLeft(Merge(r->GetLeft()->GetLeft(), r->GetLeft()->GetRight()));
			}
			else 
			{
				Delete(r->GetLeft(), key);
				return;
			}
		}
		if (key > r->GetName()) {
			if (r->GetRight()->GetName() == key) 
			{
				r->SetRight(Merge(r->GetRight()->GetLeft(), r->GetRight()->GetRight()));
			}
			else {
				Delete(r->GetRight(), key);
				return;
			}
		}
	}

	void Insert(BSTNode* r, BSTNode* new_node) 
	{
		if (new_node->GetName() > r->GetName()) 
		{
			if (r->GetRight() != NULL) 
			{
				Insert(r->GetRight(), new_node);
				return;
			}
			else 
			{
				r->SetRight(new_node);
				return;
			}
		}
		if (r->GetLeft() != NULL) 
		{
			Insert(r->GetLeft(), new_node);
			return;
		}
		else {
			r->SetLeft(new_node);
			return;
		}
	}

	void DeleteALL(BSTNode* node) //??
	{
		if (node->GetMiddle() == NULL)
		{
			return;
		}
		if (node->GetLeft != NULL)
			DeleteALL(node->GetLeft);
		if (node->GetRight != NULL)
			DeleteALL(node->GetRight);
		if (node->GetLeft == NULL && node->GetRight == NULL)
			node->SetMiddle(NULL);
	}
public:
	void Insert(Record* node)
	{
		if (root->GetMiddle == NULL)
		{
			root->SetMiddle(node);
			return;
		}

		BSTNode* tmp = new BSTNode(node);
		Insert(root, tmp);
	}

	void Delete(string key)
	{
		if (root->GetMiddle() == NULL) 
		{
			return;
		}

		if (root->GetName() == key)
		{
			if (root->GetRight() != NULL || root->GetLeft() != NULL) {
				root = Merge(root->GetLeft(), root->GetRight());
				return;
			}
			root->SetMiddle(NULL);
			return;
		}
		Delete(root, key);
	}

	

	Record* Search(string key) {
		BSTNode* res = Search(root, key);
		if (res == NULL)
		{
			return NULL;
		}
		return res->GetMiddle();
	}

	~BST()
	{
		DeleteALL(root);
		root = NULL;
	}



};


#endif