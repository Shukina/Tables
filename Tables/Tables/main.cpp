#include <fstream>
#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus"); // ���������� ����������� ���������
	ofstream fout("TestText.txt"); // ������ ������ ������ ofstream ��� ������ � ��������� ��� � ������ cppstudio.txt
	fout << "�����"; // ������ ������ � ����
	fout.close(); // ��������� ����


	char buff[50]; // ����� �������������� �������� ������������ �� ����� ������
	ifstream fin("TestText.txt"); // ������� ���� ��� ������

								  //fin >> buff; // ������� ������ ����� �� �����
								  //cout << buff << endl; // ���������� ��� �����

	fin.getline(buff, 50); // ������� ������ �� �����
	fin.close(); // ��������� ����
	cout << buff << endl << endl; // ���������� ��� ������

	cout << "��� 10 ����� ������ ����" << endl;
	cout << "+---------------+--------------+" << endl;
	cout << "|  �����        |   ����� ���� |" << endl;

	system("pause");
	return 0;
}