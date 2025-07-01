//Для индивидуального задания обработать динамический массив.
//Элементы считать из текстового файла, использовать потоки С++.
//Результаты записать в текстовый файл, использовать потоки С++.
//Циклы в рекурсиях не использовать.
//8.9 Вычисление суммы каждых пяти элементов массива.

//добавить:
//ввод массива через inputfile?+

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
        cout << "Ошибка открытия файлов" << endl;
        return 1;
    }

    int sum = 0;
    int size = 0;
    int start = 0; 
    int capacity = 2;
    int* array = new int[capacity];

    outputFile << "Заданный массив" << endl;

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
        outputFile << "Сумма " << (i+1) << " пятёрки элементов: " << SumFiveElements(array, start, size, outputFile, sum, limit) << endl;
        start += 5;
        limit += 5;
    }

    delete[] array;
    inputFile.close();
    outputFile.close();

    cout << "Результаты программы выведены в файл" << endl;

    return 0;
}