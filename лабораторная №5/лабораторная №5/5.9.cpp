/*
+ Задана матрица А размерности N*M.
+ Элементы матрицы целые знаковые числа.
Построить динамическую матрицу В,
строки которой будут состоять только из всех повторяющихся элементов соответствующей строки матрицы А.
В конце строк нули не добавлять, а сделать строки переменной длины.
+ Размерность матрицы считать с консоли, элементы матрицы - случайным образом. Результаты вывести на консоль.
+ Вывод матриц с помощью функции printf (использовать форматирование).*/
#include <iostream>
#include <time.h>
#include <algorithm>
using namespace std;

void DeleteMatrix(int n, int m, int** matrix)
{
	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

void PrintMatrixA(int n, int m, int** matrix)
{
	printf("Матрица A:\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d \t", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void PrintMatrixB(int n, int* rowSizes, int** matrix)
{
	printf("Матрица B:\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < rowSizes[i]; j++)
		{
			printf("%d \t", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int** BuildMatrixB(int** matrixA, int n, int m, int value, int*& rowSizes)
{
	int** matrixB = new int* [n];
	rowSizes = new int[n];
	for (int i = 0; i < n; i++) {
		int newSize = 0;
		for (int j = 0; j < m; j++) {
			if (matrixA[i][j] != value) {
				newSize++;
			}
		}
		matrixB[i] = new int[newSize];
		rowSizes[i] = newSize;
		int index = 0;
		for (int j = 0; j < m; j++) {
			if (matrixA[i][j] != value) {
				matrixB[i][index++] = matrixA[i][j];
			}
		}
	}
	return matrixB;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(0));
	int n, m;
	cout << "Введите количество строк и столбцов матрицы A\n";
	cin >> n >> m;
	int** matrixA;
	matrixA = new int* [n];
	for (int j = 0; j < n; j++)
	{
		matrixA[j] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matrixA[i][j] = rand() % 21 - 10;
		}
	}
	PrintMatrixA(n, m, matrixA);

	for (int i = 0; i < n; i++)
	{
		sort(matrixA[i], matrixA[i] + m);
	}
	cout << "Отсортированная матрица А\n";
	PrintMatrixA(n, m, matrixA);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; (j+1) < m; j++)
		{
			if (matrixA[i][j] != matrixA[i][j + 1])
			{
				matrixA[i][j] = -11;
			}
		}
	}

	int* rowSizes;
	int** matrixB = BuildMatrixB(matrixA, n, m, -11, rowSizes);
	cout << "Вывод матрицы В, строки которой состоят из повторяющихся элементов соответствующей строки матрицы А\n";
	PrintMatrixB(n, rowSizes, matrixB);

	DeleteMatrix(n, m, matrixA);
	DeleteMatrix(n, m, matrixB);
	delete[] rowSizes;

	return 0;
}