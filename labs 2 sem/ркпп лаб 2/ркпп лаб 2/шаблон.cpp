//#include <fstream>
//#include <iostream>
//#include <string.h> 
//#include <stdio.h>
//#include <stdlib.h>//rand
//#include <search.h>
//using namespace std;
//
//// предваряющее описание структур:
//struct Element3;
//struct Element2;
//
//struct Element1
//{
//public:
//
//	char Name[50], Addr[50];
//	double Price;
//	// перегрузка оператора вывода
//	// используется, где написано (11):
//	friend ostream& operator<< (ostream& out, const Element1& m)
//	{
//		//…
//	}
//
//	// перегрузка оператора ввода
//	// используется, где написано (12):
//	friend	istream& operator>> (istream& in, Element1& m)
//	{
//		in >> Name >> Addr;
//	}
//
//	// перегрузка оператора =
//	// используется, где написано (13) :
//	Element1& operator = (Element1& m)
//	{
//		strcpy(Name, m.Name);
//		strcpy(Addr, m.Addr);
//	}
//	// используется, где написано (14) :
//	Element1& operator = (Element2& m)
//	{
//		strcpy(Name, m.Name);
//	}
//
//	Element1& operator = (Element3& m)
//	{
//		strcpy(Name, m.Name);
//	}
//
//	// используется, где написано (15) :
//	// перегрузка оператора = общего  для разных структур (вместо предыдущих 3-х):
//	template<class T>
//	Element1& operator = (T& m)
//	{
//		strcpy(Name, m.Name);
//		//сравнение полей структур взять в блоки исключений (try\catch),
//		// если поля нет - не произойдёт сбоя программы
//
//	}
//
//	// перегрузка оператора == , сравнение структур (по полям в них)
//	// используется, где написано:(16)
//	template<class T>
//	bool operator == (T& m)
//	{
//	//сравнение полей структур взять в блоки исключений (try\catch),
//	// если поля нет - не произойдёт сбоя программы
//	}
//	// используется, где написано 17):
//	bool operator < (Element1& m2)
//	{
//		if (strcmp(Name, m2.Name) > 0)
//			return true;
//		else return false;
//	}
//};
//
//struct Element2
//{
//	char Name[50];
//
//	// используется, где написано (22) :
//	friend	istream& operator>> (istream& in, Element2& m)
//	{
//		//…
//	}
//
//	// используется, где написано (21):
//	friend ostream& operator<< (ostream& out, const Element2& m)
//	{
//		//…
//	}
//
//	// используется, где написано (23):
//	Element2& operator = (Element2& m)
//	{
//		//…
//	}
//
//	// использование шаблонного operator == для любых типов структур:
//    // используется, где написано (24):
//	template<class T>
//	bool operator == (T& m)
//	{
//	//сравнение полей структур взять в блоки исключений (try\catch),
//    // если поля нет - не произойдёт сбоя программы
//	}
//
//	// используется, где написано (25):
//	bool operator < (Element2& m2)
//	{
//		if (strcmp(Name, m2.Name) > 0)
//			return true;
//		else return false;
//	}
//};
//
//struct Element3
//{
//	char Name[50], Addr[50], ControlDate[25];
//	double Price;
//
//	// используется, где написано (32):
//	friend	istream& operator>> (istream& in, Element3& m)
//	{
//		return in;
//	}
//
//	// используется, где написано (31):
//	friend ostream& operator<< (ostream& out, const Element3& m)
//	{
//		//…
//	}
//
//	// перегрузка оператора = dlya obyecta classa, 
//	// используется, где написано (34):
//	Element3& operator = (Element3& m)
//	{
//		//…
//	}
//
//	// присвоение Element3 struct Element1 
//	// используется, где написано (33) :
//	Element3& operator = (Element1& m)
//	{
//		char s[25] = "11 dec 2000";
//		strcpy(Name, m.Name);
//	}
//
//	// используется, где написано (35) :
//	// использование шаблонного operator == для любых типов структур:
//	template<class T>
//	bool operator == (T& m)
//	{
//	//сравнение полей структур взять в блоки исключений (try\catch),
//    // если поля нет- не произойдёт сбоя программы
//	}
//
//	// перегрузка оператора <, сравнение структур по полям
//	// используется, где написано (36):
//	bool operator < (Element3& m2)
//	{
//		if (strcmp(Name, m2.Name) > 0)
//			return true;
//		else return false;
//	}
//};
//
//template<class T>
//class MASSIV
//{
//	int count;
//	T* massiv;
//
//public:
//
//	MASSIV() 
//	{
//		massiv = NULL;
//		count = 0;
//	}
//
//	MASSIV(int n)
//	{
//		//выделение памяти
//	}
//
//	MASSIV(MASSIV <T>& m)
//	{
//        
//	}
//
//	~MASSIV()
//	{
//		delete (T*)massiv;
//	}
//
//	int GetCount()
//	{
//		return count;
//	}
//
//	void SetCount(int k)
//	{
//		count = k;
//	}
//
//	void Search(T k)
//	{
//		for (int i . . .)
//
//			if (M[i] == k)
//			{
//
//			}
//	}
//
//	// Запись в бинарный файл (работает только для строк char*)
//	void WriteData(char* s)
//	{
//		fstream out;
//		out.open(s, ofstream::out | ofstream::binary);
//		if (!out.is_open())
//		{
//			cout << "Open file failed.\n";
//
//		}
//		else
//		{
//			int i = 0;
//			int k = 0;//позиция в байтах от текущей позиции
//			// установить текущую позицию: с позиции k от конца файла:
//			out.seekp(k, ios::end);
//
//			while (i < count)
//			{
//				//запись в файл элемента массива
//				out.write((char*)&massiv[i], sizeof(T));
//				i++;
//			}
//			//можно записывать полностью массив в бинарный файл без цикла:
//			out.write((char*)&massiv, sizeof(T * count));
//
//			out.close();
//		}
//	}
//	//Запись в текстовый файл
//	void WriteTextData(char* s)
//	{
//		fstream out;
//		out.open(s, ofstream::out);
//		if (!out.is_open())
//		{
//			cout << "Open file failed.\n";
//		}
//		else
//		{
//			int i = 0;
//
//			while (i < count)
//			{
//				out << massiv[i];// (11) или (21) или (31)
//				i++;
//			}
//			out.close();
//		}
//	}
//	//Чтение из бинарного файла
//	// работает только для строк char*
//	void ReadData(char* s)
//	{
//		fstream in;
//		in.open(s, ofstream::in | ofstream::binary);
//		if (!in.is_open())
//		{
//			cout << "Open file failed.\n";
//		}
//		//можно выделить, если в конструкторе не выделена:
//				//mas = new T[100];
//
//		int k = 0;//позиция в байтах от текущей позиции
//		//установить текущую позицию: k от начала файла:
//		in.seekg(k, ios::beg);
//
//		int i = 0;
//		while (!in.eof())
//		{
//			//чтение из файла элемента массива
//			in.read((char*)&massiv[i], sizeof(T));
//
//		}
//		count = i - 1;
//		//можно читать полностью массив из бинарного файла без цикла, если известно количество данных( которое можно вычислить по размеру файла)!:
//		out.read((char*)&massiv, sizeof(T * count));
//		in.close();
//	}
//	i++;
//
//}
//// Чтение из текстового файла
//void ReadTextData(char* s)
//{
//	fstream in;
//	in.open(s, ofstream::in); if (!in.is_open())
//	{
//		cout << "Open file failed.\n";
//
//	}
//	else
//	{
//		MASS = new T[100];
//		int i = 0;
//
//		while (!in.eof())
//		{
//			in >> massiv[i]; // (12) или (22) или (32)
//			i++;
//		}
//		count = i - 1;
//		in.close();
//	}
//}
//// перегрузка оператора ввода массива
//// используется, где написано :(111)
//friend istream& operator>> (istream& in, MASSIV& m)
//{
//	int n;
//	cout << "Enter count: ";
//	in >> n;
//	MASSIV x(n);
//	m = x; // (13) или (15) 
//	for (int i = 0; i < n; i++)
//	{
//
//		cout << "Enter element:";
//		in >> m[i]; // (12) или (22) или (32) и (3)
//	}
//
//	return in;
//}
//
//// перегрузка оператора вывода массива
//// используется, где написано :(1)
//friend ostream& operator<< (ostream& out, const MASSIV& m)
//{
//	out << "--------MASSIV :" << endl;
//	for (…)
//		out << m[j]; // (11) или (21) или (31) и (3)
//	return out;
//}
//
//// перегрузка оператора ввода массива
//// используется, где написано :(2)
//friend istream& operator>> (istream& in, MASSIV& m)
//{
//	cout << "--------ENTER MASSIV : " << endl;
//	for (…)
//		in >> m[j]; // (12) или (22) или (32) и (3)
//	return in;
//}
//
//// перегрузка оператора [] для объекта класса массива 
//// используется, где написано:(3)
//T& operator[] (int m)
//{
//	return massiv[m];
//}
//
////перегрузка оператора=, для объекта класса массива
////используется, где написано:(4)
//template<class T2>
//MASSIV operator = (MASSIV <T2>& m)
//{
//	count = m.GetCount();
//	…
//}
//
//void Sort()
//{
//	cout << endl << "---------------SORT MASSIV	" << endl << endl;
//	T t;
//	for (. .)
//		for (. . .)
//			if (massiv[i] < massiv[j]) //(17)
//			{
//				. . .
//					t = massiv[i]; // (13) или (15), если для Struct1;
//				// (23), если для Struct2…
//				…
//			}
//}
//
//template<class T1, class T2>
//void SUBTRACTION(MASSIV<T1>& x, MASSIV<T2>& y)
//{
//	int k = 0;
//	bool b;
//	cout << endl << "---------------SUBTRACTION—--- 	" << endl << endl;
//	for (int i = 0; i < x.GetCount(); i++)
//	{
//		…
//			for (int j = 0; j < y.GetCount(); j++)
//				if (x[i] == y[j]) . . .; //(14) или (15) 
//		. . .
//		{
//			massiv[k] = x[i]; //(33)
//
//			…
//		}
//	}
//	count = k;
//
//}
//};
//
//int main()
//{
//	MASSIV <Element1> M;
//	M.WriteData("Element1.txt");
//	M.WriteTextData("textElement1.txt");
//	M.ReadData("Element1.txt");
//	M.ReadTextData("textElement1.txt");
//	M.sort(); cout << M;//(1)
//	MASSIV <Element2> K;
//	K.ReadTextData("textElement2.txt");
//	cout << K;
//	K.ReadData("Element2.txt");
//	K.WriteData("Element2.txt");
//	K.WriteTextData("textElement2.txt");
//	cout << K[2]; //(1) (2)
//	cout << K;//(1)
//	MASSIV <Element3> R(M.GetCount());
//	R.SUBTRACTION(M, K);
//	cout << R; //(1)
//	R.Sort();
//	cout << R;//(1)
//	MASSIV <Element3> K2;
//	K2 = R;//(4)
//	cout << K2;//(1)
//	cin >> K2; //(2)
//	cout << K2;
//	MASSIV <int> intmass;
//	intmass.Sort();
//	return 1;
//}