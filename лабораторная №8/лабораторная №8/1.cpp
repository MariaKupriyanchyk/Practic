//��� ��������������� ������� ���������� ������������ ������.
//�������� ������� �� ���������� �����, ������������ ������ �++.
//���������� �������� � ��������� ����, ������������ ������ �++.
//����� � ��������� �� ������������.
//8.9 ���������� ����� ������ ���� ��������� �������.

//��������:
//���� ������� ����� inputfile?+

#include <iostream>
#include <fstream>
#include <time.h>
#include <cmath>

using namespace std;

int SumFiveElements(int* arr, int start, int size, ofstream& outputfile, int sum, int limit)
{
    if (start >= limit || start >= size)
    {
        return sum;
    }
    sum += arr[start];
    SumFiveElements(arr, start + 1, size, outputfile, sum, limit);
}

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(0));

    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile || !outputFile)
    {
        cout << "������ �������� ������" << endl;
        return 1;
    }

    int sum = 0;
    int size = 0;
    int start = 0; 
    int capacity = 2;
    int* array = new int[capacity];

    outputFile << "�������� ������" << endl;

    while (inputFile >> array[size])
    {
        size++;
        if (size >= capacity)
        {
            capacity *= 2;
            int* newArray = new int[capacity];
            for (int i = 0; i < size; i++)
            {
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
        }
    }

    for (int i = 0; i < size; i++)
    {
        outputFile << array[i] << " ";
    }

    outputFile << endl;

    double times;
    times = size / 5.0;
    times = ceil(times);

    int limit;
    if (size < 5)
    {
        limit = size;
    }
    else
    {
        limit = 5;
    }

    for (int i = 0; i < times; i++)
    {
        outputFile << "����� " << (i+1) << " ������ ���������: " << SumFiveElements(array, start, size, outputFile, sum, limit) << endl;
        start += 5;
        limit += 5;
    }

    delete[] array;
    inputFile.close();
    outputFile.close();

    cout << "���������� ��������� �������� � ����" << endl;

    return 0;
}