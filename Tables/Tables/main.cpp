#include <stdio.h>
#include <tchar.h>
#include "Table.h"
#include "HashTable.h"
#include "BST_tree.h"
#include "Math.h"
#include "stdlib.h"
#include <fstream>
#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{

	//HashTable C(10);
	BST C;
	Record rec;
	C.Read("Text.txt");
	system("cls");
	cout << "���-�������:" << endl << endl;
	C.Print();
	cout << endl;
	//setlocale(LC_ALL, "rus"); // ���������� ����������� ���������
	//ofstream fout("TestText.txt"); // ������ ������ ������ ofstream ��� ������ � ��������� ��� � ������ cppstudio.txt
	//fout << "�����"; // ������ ������ � ����
	//fout.close(); // ��������� ����


	//char buff[50]; // ����� �������������� �������� ������������ �� ����� ������
	//ifstream fin("TestText.txt"); // ������� ���� ��� ������

	//							  //fin >> buff; // ������� ������ ����� �� �����
	//							  //cout << buff << endl; // ���������� ��� �����

	//fin.getline(buff, 50); // ������� ������ �� �����
	//fin.close(); // ��������� ����
	//cout << buff << endl << endl; // ���������� ��� ������

	//cout << "��� 10 ����� ������ ����" << endl;
	//cout << "+---------------+--------------+" << endl;
	//cout << "|  �����        |   ����� ���� |" << endl;

	system("pause");
	return 0;
}