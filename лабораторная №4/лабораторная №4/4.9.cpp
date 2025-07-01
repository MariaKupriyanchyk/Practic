/*��� ������� �� ��������������� ������� �����������:
+ ���� - ����� �� ����� �++ (cin, cout)
+ ��������� ��������� ������� - ���������
+ ��������� ���������� �� �������� � ������� ����������� ������� qsort.
+ ��������� ����� �������� � ������� � ������� ����������� ������� bsearch.
+ ��������� ���������� � ������� ����������� ������� sort(STL: algorithm).

����������� ���������, ������������� � ������������ ����������� ������� N,
����������� c��������� ��� ��������� �� �����������.
���������� ������������ � ������� ���������� ��������� ���������� � ��������.
����, �����, c��������� �������� � ��������� �������. ��� ������� unsigned short.*/
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
	cout << "������� ���������� ��������� �������\n";
	cin >> size;
	A = new unsigned short[size];
	for (int i = 0; i < size; i++)
	{
		A[i] = (unsigned short)rand();
		cout << A[i] << " ";
	}
	cout << endl;
	cout << "�������� ���������� ������� �� �����������\n";
	SortSelest(size, start, A);
	cout << "C��������� ������� �� �������� � ������� ����������� ������� qsort\n";
	qsort(A, size, sizeof(unsigned short), Compare);
	OutputArray(size, A);
	cout << "����� �������� � ������� � ������� ����������� ������� bsearch\n";
	qsort(A, size, sizeof(A[0]), Compare);
	cout << "������� �������, ������� ����� �����\n";
	cin >> find;
	element_find = (unsigned short*)bsearch(&find, A, size, sizeof(unsigned short), Compare);
	if (element_find != 0)
		{
		cout <<"� ������� ��������� ������� " << *element_find << endl;
		}
	else
		{
		cout << "������� ������� �� ���������\n" << endl;
		}
	cout << "���������� � ������� ����������� ������� sort\n";
	sort(A, A + size);
	OutputArray(size, A);
	cout << "���������� �� ����������� � ������� �������� �������\n";
	BinarySearch(size, A);
	OutputArray(size, A);
	return 0;
}