// Queue.cpp: определяет точку входа для консольного приложения.
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
	double p;  //вероятность поступления задачи
	double *q;  
	setlocale(LC_CTYPE, "Russian");
	char c;
	do
	{
		cout << "Введите число заданий:" << endl;
		do
		{
			cin >> n;
			if (n <= 0)
				cout << "Некорректный ввод. Введите значение заново:" << endl;
		} while (n <= 0);
		TQueue <int> a(n);
		q = new double[n];
		for (int i = 0; i < n; i++)
			q[i] = rand() % 100 / 100.0;
		cout << "Введите вероятность (в процентах), что придёт новая задача:" << endl;
		do
		{
			cin >> p;
			if ((p < 0) || (p>100))
				cout << "Некорректный ввод. Введите значение заново:" << endl;
		} while ((p < 0) || (p>100));
		p /= 100.0;
		cout << "Состояние очереди:" << endl;
		int j = 0;
		for (int i = 0; i < n; i++)
		{
			if (q[i] >= p)
				continue;
			int tmp = (rand() % 100) + 1;  //значение задачи
			a.Push(tmp);
			j++;
			cout << "Поступила в очередь: задача №" << i << " - " << tmp << " - вероятность " << q[i] << endl;
			while ((a.Front() < a.Back()) && (!a.IsEmpty()))  //если значение первой задачи в очереди меньше последней, то задача считается выполненной
				cout << "Выполнено: задача - " << a.Pop() << endl;
		}
		while (!a.IsEmpty())
			cout << "Выполнено: задача - " << a.Pop() << endl;
		if (!j)
			cout << "В очередь не поступило ни одной задачи" << endl;
		else cout << "Всего выполнено " << j << " задач" << endl;
		cout << "Введите '1', если хотите ещё раз ввести вероятность, или любой другой символ для завершения работы:" << endl;
		cin >> c;
	} while (c == '1');
    return 0;
}

