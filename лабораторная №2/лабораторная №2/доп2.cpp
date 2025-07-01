#include <iostream>
#include <cmath>
using namespace std;
int main() {
	setlocale(LC_ALL, "Rus");
	double dr, chast, x1, x2;
	int ost = 0;
	cout << "Введите делимое и делитель\n";
	cin >> x1 >> x2;
	if (x2 == 0) {
		cout << "Некорректный ввод";
		return 1;
	}
	if (x1 >= 0 && x2 > 0)
	{
		chast = x1 / x2;
		dr = chast - int(chast);
		if (dr < 0.5)
		{
			chast = chast - dr;
		}
		else
		{
			chast = chast - dr + 1;
		}
		if (x1 > x2 && chast != 0)
		{
			ost = int(x1) % int(x2);
		}
		else if (x1 < x2)
		{
			ost = x1;
		}
	}
	else if (x1 < 0 && x2 > 0)
	{
		x1 = abs(x1);
		chast = x1 / x2;
		dr = chast - int(chast);
		dr = -dr;
		if (dr < 0.5)
		{
			chast = -(chast + dr) - 1;
		}
		else
		{
			chast = -(chast - dr) - 1;
		}
		x1 = -x1;
		ost = int(x1) - int(x2) * chast;
	}
	else if (x2 < 0 && x1 >= 0)
	{
		x2 = abs(x2);
		chast = x1 / x2;
		dr = chast - int(chast);
		dr = -dr;
		if (dr < 0.5)
		{
			chast = -(chast + dr);
		}
		else
		{
			chast = -(chast + dr - 1);
		}
		x2 = -x2;
		ost = int(x1) - int(x2) * chast;
	}
	else if (x1 < 0 && x2 < 0)
	{
		x1 = abs(x1);
		x2 = abs(x2);
		chast = x1 / x2;
		dr = chast - int(chast);
		if (dr < 0.5)
		{
			chast = chast - dr + 2;
		}
		else
		{
			chast = chast - dr + 1;
		}
		x1 = -x1;
		x2 = -x2;
		ost = int(x1) - int(x2) * chast;
	}
	cout << "Округлённое частное " << chast << endl;
	cout << "Остаток " << ost;
	return 0;
}