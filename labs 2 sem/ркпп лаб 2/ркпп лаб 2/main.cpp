#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "MASSIV.h"
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#include "Windows.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");

    MASSIV <Element1> Elem1(6);
    Element1 elem1_1 ("Vika", 3);
    Element1 elem1_2 ("Glebus", 4);
    Element1 elem1_3 ("Nastya", 1);
    Element1 elem1_4 ("Sanya", 1);
    Element1 elem1_5 ("Makar", 1);
    Element1 elem1_6 ("Vova", 2);
    Elem1[0] = elem1_1;
    Elem1[1] = elem1_2;
    Elem1[2] = elem1_3;
    Elem1[3] = elem1_4;
    Elem1[4] = elem1_5;
    Elem1[5] = elem1_6;

    Elem1.WriteTextData("textElement1.txt");
    SetConsoleCP(1251);
    Elem1.WriteData("Element1.txt");
    Elem1.ReadData("Element1.txt");
    Elem1.ReadTextData("textElement1.txt");
    cout << "Search for undergraduate students" << endl << endl;
    Elem1.SearchUndergraduateStudents();
    cout << endl << Elem1 << endl;

    MASSIV <Element2> Elem2(3);
    Element2 elem2_1("Sanya", 1, 4);
    Element2 elem2_2("Makar", 1, 12);
    Element2 elem2_3("Vova", 2, 7);
    Elem2[0] = elem2_1;
    Elem2[1] = elem2_2;
    Elem2[2] = elem2_3;

    Elem2.WriteTextData("textElement2.txt");
    SetConsoleCP(1251);
    Elem2.WriteData("Element2.txt");
    Elem2.ReadData("Element2.txt");
    SetConsoleCP(866);
    Elem2.ReadTextData("textElement2.txt");
    cout << Elem2 << endl;

    MASSIV <Element3> Elem3(3);
    Elem3.SUBTRACTION(Elem1, Elem2);
    cout << Elem3;
    cout << endl << "Sorting the Elem3 array by the course field" << endl << endl;
    Elem3.Sort(Elem3);

    MASSIV <int>IntArray1(5);
    int intArray1_1 = 3;
    int intArray1_2 = 4;
    int intArray1_3 = 1;
    int intArray1_4 = 5;
    int intArray1_5 = 2;
    IntArray1[0] = intArray1_1;
    IntArray1[1] = intArray1_2;
    IntArray1[2] = intArray1_3;
    IntArray1[3] = intArray1_4;
    IntArray1[4] = intArray1_5;

    cout << "The int array" << endl;
    cout << IntArray1;
    IntArray1.WriteTextData("textInt.txt");
    cout << "Sorting the int array" << endl; ;
    IntArray1.Sort(IntArray1);

    MASSIV<int>IntArray2(3);
    int intArray2_1 = 1;
    int intArray2_2 = 5;
    int intArray2_3 = 2;
    IntArray2[0] = intArray2_1;
    IntArray2[1] = intArray2_2;
    IntArray2[2] = intArray2_3;

    cout << "The second int array" << endl;
    cout << IntArray2;

    MASSIV<int>IntArray3(3);
    cout << "The difference between the first and second int arrays" << endl;
    IntArray3.SUBTRACTION(IntArray1, IntArray2);
    cout << IntArray3 << endl;
    IntArray3.Search(3);

    return 0;
}