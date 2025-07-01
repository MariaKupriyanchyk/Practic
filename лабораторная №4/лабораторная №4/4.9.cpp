/*Для массива из индивидуального задания реализовать:
+ Ввод - вывод на языке С++ (cin, cout)
+ Генерация элементов массива - случайная
+ Выполнить сортировку по убыванию с помощью стандартной функции qsort.
+ Выполнить поиск элемента в массиве с помощью стандартной функции bsearch.
+ Выполнить сортировку с помощью стандартной функции sort(STL: algorithm).

Разработать программу, запрашивающую у пользователя размерность массива N,
выполняющую cортировки его элементов по возрастанию.
Сортировки осуществлять с помощью сортировок «бинарной» сортировки и «выбором».
Ввод, вывод, cортировки выделить в отдельные функции. Тип массива unsigned short.*/
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
void OutputArray(int size, unsigned short* A)
{
	for (int i = 0; i < size; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}
int Compare(const void* i, const void* j)
{
	return (*(unsigned short*)j - *(unsigned short*)(i));
}
void BinarySearch(int size, unsigned short* A)
{
	int middle, left, right;
	for (int element = 2; element <= size; element++)
	{
		left = 1; right = element;
		while (left < right) 
		{
			middle = (left + right) / 2; 
			if (A[middle] <= A[element]) 
			{
				left = middle + 1;
			} 
	        else
	        {
			    right = middle;
		    } 
	    }
	    for (int i = 1; i > right; A[i--] = A[i - 1]);
	    A[right] = A[element];
	}
}
int PosMin(int size, int start, unsigned short* A)
{
	unsigned short min = A[start];
	int pos{};
	for (int i = start; i < size; i++)
	{
		if (A[i] <= min)
		{
			min = A[i];
			pos = i;
		}
	}
	return pos;
}
unsigned short SortSelest(int size, int start, unsigned short* A)
{
	for (int i = 0; i < size; i++)
	{
		int pos = PosMin(size, start, A);
		swap(A[pos], A[i]);
		cout << A[i] << " ";
		start++;
	}
	cout << endl;
	return (unsigned short)A;
}
int main() {
	setlocale(LC_ALL, "Rus");
	srand(time(0));
	unsigned short* A;
	int size, start{}, find;
	unsigned short* element_find;
	cout << "Введите количество элементов массива\n";
	cin >> size;
	A = new unsigned short[size];
	for (int i = 0; i < size; i++)
	{
		A[i] = (unsigned short)rand();
		cout << A[i] << " ";
	}
	cout << endl;
	cout << "Выборная сортировка массива по возрастанию\n";
	SortSelest(size, start, A);
	cout << "Cортировка массива по убыванию с помощью стандартной функции qsort\n";
	qsort(A, size, sizeof(unsigned short), Compare);
	OutputArray(size, A);
	cout << "Поиск элемента в массиве с помощью стандартной функции bsearch\n";
	qsort(A, size, sizeof(A[0]), Compare);
	cout << "Элемент массива, который нужно найти\n";
	cin >> find;
	element_find = (unsigned short*)bsearch(&find, A, size, sizeof(unsigned short), Compare);
	if (element_find != 0)
		{
		cout <<"В массиве обнаружен элемент " << *element_find << endl;
		}
	else
		{
		cout << "Элемент массива не обнаружен\n" << endl;
		}
	cout << "Сортировка с помощью стандартной функции sort\n";
	sort(A, A + size);
	OutputArray(size, A);
	cout << "Сортировка по возрастанию с помощью бинарных вставок\n";
	BinarySearch(size, A);
	OutputArray(size, A);
	return 0;
}