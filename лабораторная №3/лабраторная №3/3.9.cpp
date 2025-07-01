//Заменить в массиве размерности n, n<=100, чётные элементы на сумму их цифр.
#include <iostream>
#include <time.h>
using namespace std;
int SettingArray(int n, int Ma[100])
{
	int m;
	m = n;
	setlocale(LC_ALL, "Rus");
	srand(time(0));
	if (m < 0 || m > 100)
	{
		cout << "Некорректный ввод";
		return 1;
	}
	for (int i = 0; i < m; i++)
	{
			Ma[i] = rand() % 200 - 100;
			cout << Ma[i] << " ";
	}
	return n, Ma[100];
}
int criterion(int n, int Ma[], int sum)
{
	if (n < 0 || n > 100)
	{
		return 1;
	}
	for (int j = 0; j <= n; j++)
	{
		if (Ma[j] % 2 == 0)
		{
			if (Ma[j] < 0)
            {
	            Ma[j] = -Ma[j];
            }
			if (Ma[j] >= 0) {
				while (Ma[j] / 10 > 0) {
					sum += (Ma[j] % 10);
					Ma[j] = Ma[j] / 10;
				}
				cout << sum + Ma[j] << " ";
			}
			sum = 0;
		}
		else
		{
			cout << Ma[j] << " ";
		}
	}
	return n, Ma, sum;
}
int main()
{
	setlocale(LC_ALL, "Rus");
	int Ma[100], n, sum{};
	cout << "Введите количество элементов массива\n";
	cin >> n;
	SettingArray(n, Ma);
	cout << endl;
	criterion(n, Ma, sum);
	return 0;
}