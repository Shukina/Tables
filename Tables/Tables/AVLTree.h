
#ifndef _AVLTREE_H
#define _AVLTREE_H

#include <iostream>
#include "Table.h"
#include "AVLNode.h"

class AVL
{
private:
	AVLNode* root;


	unsigned int GetHeight(AVLNode* p) // ��������� ������ �������
	{
		if (p)
			return p->GetHeight();
		else
			return 0; //������� ������ ��������� �������� : ���� ������� ���, ����� 0 ����� ������ ��������� ���� �������
	}

	int difheight(AVLNode* p) // �������� ����� ����� ���������
	{
		return GetHeight(p->GetRight()) - GetHeight(p->GetLeft()); // ������� ��������� �������
	}

	void fixheight(AVLNode* p) // ������� ������, ���� ������������������ ��������
	{
		unsigned int hl = GetHeight(p->GetLeft()); // ������ ������ ����
		unsigned int hr = GetHeight(p->GetRight()); // ������ ������� ����
		if (hl > hr)
			p->SetHeight(hl + 1);
		else
			p->SetHeight(hr + 1); // ������ ������� - ��� ������ ���� � ���� ������� ���� 1
	}

	AVLNode* rotateright(AVLNode* p) // ������ ������� ������ p
	{
		AVLNode* q = p->GetLeft();//���������� ������ ���� � 
		p->SetLeft(q->GetRight());//�������� ������ ���� � ����, ������� ���� p � q
		q->SetRight(p);//����������� ������� ���� q ��������� �
		fixheight(p); //������� ������
		fixheight(q);
		return q;
	}

	AVLNode* rotateleft(AVLNode* p) // ����� ������� ������ q
	{
		AVLNode* q = p->GetRight(); //���������� ������� ���� � 
		p->SetRight(q->GetLeft());//�������� ������� ���� � ����, ������� ���� p � q
		q->SetLeft(p);//����������� ������ ���� q ��������� �
		fixheight(p); //������� ������
		fixheight(q);
		return p;
	}


	AVLNode* balance(AVLNode* p) // ������������ ���� p
	{
		fixheight(p);
		if (difheight(p) == 2) //���� ����� ��� ������ ������ ������� ������� ������ �������
		{
			if (difheight(p->GetRight()) < 0)
				p->SetRight(rotateright(p->GetRight()));
			return rotateleft(p);
		}
		if (difheight(p) == -2) // ���� ������ ��� ����� ������ ������ ������� ����� �������
		{
			if (difheight(p->GetLeft()) > 0)
				p->SetLeft(rotateleft(p->GetLeft()));
			return rotateright(p);
		}
		return p; // ������������ �� �����
	}

	void Insert(AVLNode* node, AVLNode* new_node) // ������� ����� k � ������ � ������ p
	{
		if (node == NULL)
			node = new AVLNode(*new_node);

		if (new_node->GetName() < node->GetName()) //���� ����� ���� ������ ����� �����, ������� ������� ���������� �� ������ ����
			Insert(node->GetLeft(), new_node);
		else
			Insert(node->GetRight(), new_node); // ���� ����� ���� ������ ����� �����, ������� �������� �� ������ ����

		balance(node); // ������������� �������
	}

	AVLNode* Search(AVLNode* r, string key) //����� � ������ � ������ r ���� � ������ key
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

	AVLNode* findmin(AVLNode* p) // ����� ���� � ����������� ������ � ������ p 
	{
		if (p->GetLeft())
			return findmin(p->GetLeft());//���� ���� ����� ���, ���� � ���� ����� ����� � ���� �������
	}

	AVLNode* removemin(AVLNode* p) // �������� ���� � ����������� ������ �� ������ p
	{
		if (p->GetLeft() == 0) // ���� ��� ������ ���� ������ ��� �������
			return p->GetRight();
		p->SetLeft(removemin(p->GetLeft())); // ����� ���� � ������ ����
		return balance(p); //����������� ������
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

	Record* Search(string key) //����� ������ � ������ key
	{
		AVLNode* res = Search(root, key);
		if (res == NULL)
			return NULL;
		else
			return res->GetMiddle();
	}

	

	AVLNode* remove(AVLNode* p, int k) // �������� ����� k �� ������ p
	{
		if (!p) return 0; // ���� ������ ������, ������
		if (k < p->key) //���� ������� ������ ������� ���� � ������ ����
			p->left = remove(p->left, k);
		else if (k > p->key)
			p->right = remove(p->right, k);  // ���� ������� ������ �������, ���� � ������� ����
		else //  �� ������ � �������, ������� ���� �������
		{
			AVLNode* q = p->left;
			AVLNode* r = p->right;
			delete p; //������ ��������� ��� �������
			if (!r) return q;
			AVLNode* min = findmin(r);
			min->right = removemin(r); //������ ��� ����������� ������� - ��� ������ ��������� ��������� ��� ��������
			min->left = q; // ����� ��� ����������� ������� - ����� ��� ���������
			return balance(min); // ����������� ������� �������
		}
		return balance(p); // �� ������ �� �����, ����������� ������
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
