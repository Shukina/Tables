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
	unsigned char GetHeight(AVLNode* p) // ��������� ������ �������
	{
		if (p)
			return p->height;
		else
			return 0; //������� ������ ��������� �������� : ���� ������� ���, ����� 0 ����� ������ ��������� ���� �������
	}

	int difheight(AVLNode* p) // �������� ����� ����� ���������
	{
		return GetHeight(p->right) - GetHeight(p->left); // ������� ��������� �������
	}

	void fixheight(AVLNode* p) // ������� ������, ���� ������������������ ��������
	{
		unsigned char hl = GetHeight(p->left); // ������ ������ ����
		unsigned char hr = GetHeight(p->right); // ������ ������� ����
		if (hl > hr)
			p->height = hl + 1;
		else
			p->height = hr + 1; // ������ ������� - ��� ������ ���� � ���� ������� ���� 1
	}

	AVLNode* rotateright(AVLNode* p) // ������ ������� ������ p
	{
		AVLNode* q = p->left;  // �������� ������ � ������� ����
		p->left = q->right;
		q->right = p;
		fixheight(p); //������� ������
		fixheight(q);
		return q;
	}

	AVLNode* rotateleft(AVLNode* q) // ����� ������� ������ q
	{
		AVLNode* p = q->right; // �������� ������� � ������ ����
		q->right = p->left;
		p->left = q;
		fixheight(q);
		fixheight(p);
		return p;
	}


	AVLNode* balance(AVLNode* p) // ������������ ���� p
	{
		fixheight(p);
		if (difheight(p) == 2) //���� ����� ��� ������ ������ ������� ������� ������ �������
		{
			if (difheight(p->right) < 0)
				p->right = rotateright(p->right);
			return rotateleft(p);
		}
		if (difheight(p) == -2) // ���� ������ ��� ����� ������ ������ ������� ����� �������
		{
			if (difheight(p->left) > 0)
				p->left = rotateleft(p->left);
			return rotateright(p);
		}
		return p; // ������������ �� �����
	}

	AVLNode* insert(AVLNode* p, int k) // ������� ����� k � ������ � ������ p
	{
		if (!p) 
			return new AVLNode(k); // ���� ������ ������ �������� ���
		if (k<p->key) //���� ���� ������ �������, ������� ��� ���������� �� ������ ����
			p->left = insert(p->left, k);
		else
			p->right = insert(p->right, k); // ���� ���� ������ �������, ������� �������� �� ������ ����
		return balance(p); // ������������� �������
	}

	AVLNode* findmin(AVLNode* p) // ����� ���� � ����������� ������ � ������ p 
	{
		if (p->left)
			return findmin(p->left);//���� ���� ����� ���, ���� � ���� ����� ����� � ���� �������
	}

	AVLNode* removemin(AVLNode* p) // �������� ���� � ����������� ������ �� ������ p
	{
		if (p->left == 0) // ���� ��� ������ ���� ������ ��� �������
			return p->right;
		p->left = removemin(p->left); // ����� ���� � ������ ����
		return balance(p); //����������� ������
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

};
#endif
