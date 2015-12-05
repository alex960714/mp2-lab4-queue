// Queue.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "TQueue.h"
#include <stdlib.h>
#include <locale.h>
#include <iostream>
using namespace std;


int main()
{
	int n;
	double p;  //����������� ����������� ������
	double *q;  
	setlocale(LC_CTYPE, "Russian");
	char c;
	do
	{
		cout << "������� ����� �������:" << endl;
		cin >> n;
		TQueue <int> a(n);
		q = new double[n];
		for (int i = 0; i < n; i++)
			q[i] = rand() % 100 / 100.0;
		cout << "������� ����������� (� ���������), ��� ����� ����� ������:" << endl;
		do
		{
			cin >> p;
			if ((p < 0) || (p>100))
				cout << "������������ ����. ������� �������� ������:" << endl;
		} while ((p < 0) || (p>100));
		p /= 100.0;
		cout << "��������� �������:" << endl;
		int j = 0;
		for (int i = 0; i < n; i++)
		{
			if (q[i] >= p)
				continue;
			int tmp = (rand() % 100) + 1;  //������������� ������
			a.Push(tmp);
			j++;
			cout << "��������� � �������: ������ �" << i << " - " << tmp << " - ����������� " << q[i] << endl;
			while ((a.Front() < a.Back()) && (!a.IsEmpty()))  //���� ������������� ������ ������ � ������� ������ ���������, �� ������ ��������� �����������
				cout << "���������: ������ - " << a.Pop() << endl;
			i++;
		}
		while (!a.IsEmpty())
			cout << "���������: ������ - " << a.Pop() << endl;
		if (!j)
			cout << "� ������� �� ��������� �� ����� ������" << endl;
		else cout << "����� ��������� " << j << " �����" << endl;
		cout << "������� '1', ���� ������ ��� ��� ������ �����������, ��� ����� ������ ������ ��� ���������� ������:" << endl;
		cin >> c;
	} while (c == '1');
    return 0;
}

