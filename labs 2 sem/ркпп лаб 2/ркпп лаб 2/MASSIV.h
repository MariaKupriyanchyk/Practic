#pragma once
#define MASSIV_H
#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <search.h>

using namespace std;

struct Element3;
struct Element2;

struct Element1
{
	char Name[50];
	int course;

	Element1();

	Element1(const char*, int);

	~Element1();

	friend ostream& operator<< (ostream& out, const Element1& element1);

	friend istream& operator>> (istream& in, Element1& element1);

	template<class T>
	Element1& operator= (const T& other);

	template<class T>
	bool operator== (const T& other) const;

	bool operator< (const Element1& other) const;
};

struct Element2
{
	char Name[50];
	int ñountOfDebts;
	int course;

	Element2();

	Element2(const char*, int, int);

	~Element2();

	friend istream& operator>> (istream& in, Element2& element2);

	friend ostream& operator<< (ostream& out, const Element2& element2);

	Element2& operator= (const Element2& other);

	template<class T>
	bool operator== (const T& other) const;

	bool operator< (const Element2& other) const;
};

struct Element3
{
	char Name[50];
	int course;

	Element3();

	Element3(const char*, int);

	~Element3();

	friend istream& operator>> (istream& in, Element3& element3);

	friend ostream& operator<< (ostream& out, const Element3& element3);

	Element3& operator= (const Element3& other);

	Element3& operator= (Element1& other);

	template<class T>
	bool operator== (const T& other) const;

	bool operator< (const Element3& other) const;
};

template<class T>
class MASSIV
{
private:

	int count;
	T* M;

public:

	MASSIV();

	MASSIV(int);

	MASSIV(MASSIV <T>& other);

	~MASSIV();

	int GetCount();

	void SetCount(int);

	void Search(T);

	void WriteData(string);

	void WriteTextData(string);

	void ReadData(string);

	void ReadTextData(string);

	friend istream& operator>> (istream& in, MASSIV& M);

	friend ostream& operator<< (ostream& out, const MASSIV& M);

	friend istream& operator>> (istream& in, MASSIV& M);

	T& operator[] (int);

	void SearchUndergraduateStudents();

	void Sort(MASSIV<T>& massiv);

	template<class T1, class T2>
	void SUBTRACTION(MASSIV<T1>& x, MASSIV<T2>& y);
};

//for MASSIV
template<class T>
T* M;
int count;

//for Element1, Element2, Element3
char Name[50];
int course;
int ñountOfDebts;

struct Element1;

Element1::Element1()
{
    Name[0] = '0';
    course = 0;
}

Element1::Element1(const char* name, int course)
{
    strcpy(Name, name);
    this->course = course;
}

Element1::~Element1() {}

ostream& operator<< (ostream& out, const Element1& element1)
{
    out << element1.Name << " " << element1.course << endl;
    return out;
}

istream& operator>> (istream& in, Element1& element1)
{
    in >> element1.Name >> element1.course;
    return in;
}

template<class T>
Element1& Element1::operator= (const T& other)
{
    if (this != &other)
    {
        strcpy(Name, other.Name);
        course = other.course;
    }
    return *this;
}

template<class T>
bool Element1::operator== (const T& other) const
{
    return (strcmp(Name, other.Name) == 0);
}

bool Element1::operator< (const Element1& other) const
{
    return course < other.course;
}



struct Element2;

Element2::Element2()
{
    Name[0] = '0';
    course = 0;
    ñountOfDebts = 0;
}

Element2::Element2(const char* name, int course, int countOfDebts)
{
    strcpy(Name, name);
    this->course = course;
    this->ñountOfDebts = countOfDebts;
}

Element2::~Element2() {}

istream& operator>> (istream& in, Element2& element2)
{
    in >> element2.Name >> element2.course >> element2.ñountOfDebts;
    return in;
}

ostream& operator<< (ostream& out, const Element2& element2)
{
    out << element2.Name << " " << element2.course << " " << element2.ñountOfDebts << endl;
    return out;
}

Element2& Element2::operator= (const Element2& other)
{
    if (this != &other)
    {
        strcpy_s(Name, other.Name);
        course = other.course;
        ñountOfDebts = other.ñountOfDebts;
    }
    return *this;
}

template<class T>
bool Element2::operator== (const T& other) const
{
    return (strcmp(Name, other.Name) == 0);

}

bool Element2::operator< (const Element2& other) const
{
    return course < other.course;
}



struct Element3;

Element3::Element3()
{
    Name[0] = '0';
    course = 0;
}

Element3::Element3(const char* name, int course)
{
    strcpy(Name, name);
    this->course = course;
}

Element3::~Element3() {}

istream& operator>> (istream& in, Element3& element3)
{
    in >> element3.Name >> element3.course;
    return in;
}

ostream& operator<< (ostream& out, const Element3& element3)
{
    out << element3.Name << " " << element3.course << endl;
    return out;
}

Element3& Element3::operator= (const Element3& other)
{
    if (this != &other)
    {
        strcpy_s(Name, other.Name);
        course = other.course;
    }
    return *this;
}

Element3& Element3::operator= (Element1& other)
{
    if (this->Name != other.Name || this->course != other.course)
    {
        strcpy_s(Name, other.Name);
        course = other.course;
    }
    return *this;
}

template<class T>
bool Element3::operator== (const T& other) const
{
    return (strcmp(Name, other.Name) == 0);
}

bool Element3::operator< (const Element3& other) const
{
    return course < other.course;
}



template<class T>
MASSIV<T>::MASSIV() : count(0), M(0) {}

template<class T>
MASSIV<T>::MASSIV(int other): count(other)
{
    M = new T[count];
}

template<class T>
MASSIV<T>::MASSIV(MASSIV <T>& other)
{
    this->count = other.count;
    M = new int[count];
    for (int i = 0; i < count; i++)
    {
        M[i] = other.M[i];
    }
}

template<class T>
MASSIV<T>::~MASSIV()
{
    delete[] M;
}

template<class T>
int MASSIV<T>::GetCount()
{
    return count;
}

template<class T>
void MASSIV<T>::SetCount(int other)
{
    this->count = other.count;
}

template<class T>
void MASSIV<T>::Search(T other)
{
    for (int i = 0; i < count; i++)
    {
        if (M[i] == other)
        {
            cout << M[i] << endl;
        }
    }
}

template<class T>
void MASSIV<T>::WriteData(string str)
{
    fstream out;
    out.open(str, ofstream::out | ofstream::binary);
    if (!out.is_open())
    {
        cout << "Open file failed" << endl;
        return;
    }

    out.seekp(0, ios::end);
    for (int i = 0; i < count; i++)
    {
        out.write((char*)&M[i], sizeof(T));
    }
    out.close();
}

template<class T>
void MASSIV<T>::WriteTextData(string str)
{
    fstream out;
    out.open(str, ofstream::out);
    if (!out.is_open())
    {
        cout << "Open file failed" << endl;
        return;
    }

    for (int i = 0; i < count; i++)
    {
        out << M[i];
    }
    out.close();
}

template<class T>
void MASSIV<T>::ReadData(string str)
{
    fstream in;
    in.open(str, ofstream::in | ofstream::binary);
    if (!in.is_open())
    {
        cout << "Open file failed" << endl;
        return;
    }

   // in.seekg(0, ios::beg);
    int i = 0;
    cout << "Reading from a binary file" << endl;
    while (!in.eof())
    {
        in.read((char*)&M[i], sizeof(T));
        in.close();
    }
}

template<class T>
void MASSIV<T>::ReadTextData(string str)
{
    fstream in;
    in.open(str, ofstream::in);
    if (!in.is_open())
    {
        cout << "Open file failed" << endl;
        return;
    }

    M = new T[100];
    int i = 0;

    while (!in.eof())
    {
        in >> M[i];
        i++;
    }
    count = i - 1;
    in.close();
}

template<class T>
istream& operator>> (istream& in, MASSIV<T>& M)
{
    cout << "Enter MASSIV:" << endl;
    for (int i = 0; i < M.GetCount(); i++)
    {
        in << M[i] << endl;
    }
    return in;
}

template<class T>
ostream& operator<< (ostream& out, MASSIV<T>& M)
{
    out << "MASSIV:" << endl;
    for (int i = 0; i < M.GetCount(); i++)
    {
        out << M[i] << endl;
    }
    return out;
}

template<class T>
T& MASSIV<T>::operator[] (int size)
{
    return M[size];
}

template<class T>
template< class T1, class T2>
void MASSIV<T>::SUBTRACTION(MASSIV<T1>& x, MASSIV<T2>& y)
{
    cout << endl << "SUBTRACTION " << endl;
    int k = 0;
    for (int i = 0; i < x.GetCount(); i++)
    {
        bool found = false;

        for (int j = 0; j < y.GetCount(); j++)
        {
            if (x[i] == y[j])
            {
                found = true;
                break;
            }
        }

        if (!found)
        {
            M[k] = x[i];
            k++;
        }
    }
    count = k;
}

template<class T>
void MASSIV<T>::SearchUndergraduateStudents()
{
    for (int i = 0; i < count; i++)
    {
        if (M[i].course > 1)
        {
            cout << M[i].Name << " is an undergraduate student" << endl;
        }
        else
        {
            cout << M[i].Name << " is not an undergraduate student" << endl;
        }
    }
}

template<class T>
void MASSIV<T>::Sort(MASSIV<T>& massiv)
{
    int count = massiv.GetCount();

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (M[j + 1] < M[j])
            {
                T temp = M[j];
                M[j] = M[j + 1];
                M[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < count; i++)
    {
        cout << M[i];
    }
    cout << endl;
}