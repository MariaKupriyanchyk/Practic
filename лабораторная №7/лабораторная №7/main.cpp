#include <iostream>
#include "circle.h"
#include <time.h>

using namespace std;

void main()
{
	srand(time(0));
	setlocale(LC_ALL, "ru");

	Circle c1;
	Circle c2(3, 4, 9);
	Circle c3;
	Circle c4(4.6, 3.5, 8.9);
	Circle c5(1, 2, 10);
	Circle c6(0, 8, 9);
	Circle c7(2, -4, 1);
	Circle c8(-1.1, 7, 11);
	Circle c9(-2.2, -2.5, 16);
	Circle c10(3, 3, 3);
	Circle c11(3.01, -2.9, 6.33);
	Circle c12(-2.3, 7, 0.1);
	Circle c13(-2, 4, 8);
	Circle c14(1, -5, 3.9);
	Circle c15(-1.3, -2, 5.5);
	Circle c16(3, -6, 10.1);
	Circle c17(3.03, -3.4, 9);

	double n;
	n = rand() % 21 - 10;

	cout << "���� ���������� ��� ����������: " << c3 << endl;
	cin >> c5;

	cout << "�����, � ������� ����� ����������� �������� * � / ��� ������������: " << n << endl;

	cout << "������� ���������� c5 = " << c5.area() << endl;

	cout << "+\n";
	c3 = c1 + c2;
	c3.print();

	cout << "-\n";
	c5 = c1 - c2;
	c5.print();

	cout << "*n\n";
	c6 = c1 * n;
	c6.print();

	cout << "/n\n";
	c7 = c1 / n;
	c7.print();

	cout << "��������� ������������ ������ ���������\n";
	~c3;
	c3.print();

	cout << "++ �����������\n";
	c8++;
	c8.print();

	cout << "-- �����������\n";
	c9--;
	c9.print();

	cout << "++ ������������\n";
	++c10;
	c10.print();

	cout << "-- ������������\n";
	--c11;
	c11.print();

	cout << "������������\n";
	c12 = c11;
	c12.print();

	if (c12 == c13)
	{
		cout << "���������� " << c12 << " � " << c13 << " �����\n";
	}

	else if (c12 != c13)
	{
		cout << "���������� " << c12 << " � " << c13 << " �� �����\n";
	}

	if (c14 <= c15)
	{
		cout << "���������� " << c14 << " �� ������ ���������� " << c15 << endl;
	}

	if (c15 >= c16)
	{
		cout << "���������� " << c15 << " �� ������ ���������� " << c16 << endl;
	}

	if (c16 < c17)
	{
		cout << "���������� " << c16 << " ������ ���������� " << c17 << endl;
	}

	else if (c16 > c17)
	{
		cout << "���������� " << c16 << " ������ ���������� " << c17 << endl;
	}
}