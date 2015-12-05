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
	double p;
	double *q;
	setlocale(LC_CTYPE, "Russian");
	cout << "Введите число заданий:" << endl;
	cin >> n;
	TQueue <int> a(n);
	q = new double[n];
	for (int i = 0; i < n; i++)
		q[i] = rand() % 100 / 100.0;
	cout << "Введите вероятность (в процентах), что придёт новое задание:" << endl;
	do
	{
		cin >> p;
		if ((p < 0) || (p>100))
			cout << "Некорректный ввод. Введите значение заново:" << endl;
	} while ((p<0)||(p>100));
	p /= 100.0;
	cout << "Состояние очереди:" << endl;
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (q[i] >= p)
			continue;
		int tmp = (rand() % 100) + 1;
		a.Push(tmp);
		j++;
		cout << "Поступила в очередь: задача №" << i << " - " << tmp << " - вероятность "<< q[i] << endl;
		while ((a.Front() < a.Back()) && (!a.IsEmpty()))
			cout << "Выполнено: задача - " << a.Pop() << endl;
		i++;
	}
	while(!a.IsEmpty())
		cout << "Выполнено: задача - " << a.Pop() << endl;
	if (!j)
		cout << "В очередь не поступило ни одной задачи" << endl;
	else cout << "Всего выполнено " << j << " задач" << endl;
    return 0;
}

