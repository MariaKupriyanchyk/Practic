//#include <iostream>
//#include <cmath>
//using namespace std;
//int main() {
//	setlocale(LC_ALL, "Rus");
//	const double pi = 3.14;
//	double x, e, s, slag;
//	int tr, k = 0;
//	slag = 1;
//	s = 1;
//	cout << "Введите х и порядок слагаемого\n";
//	cin >> x >> tr;
//	if (x > 2 * pi)
//	{
//		while (x > 2 * pi) {
//			x = x - 2 * pi;
//		}
//	}
//	if (x < -2 * pi)
//	{
//		while (x < -2 * pi) {
//			x = x + 2 * pi;
//		}
//	}
//	cout << cos(x) << endl;
//	if (tr < 0) {
//		cout << "Некорректный ввод\n";
//		return 1;
//	}
//		e = pow(10, (double)(-tr));
//		while (abs(slag) > e) {
//			slag = slag * (-(x * x)) / ((k + 1) * (k + 2));
//			s += slag;
//			k += 2;
//		}
//		cout << s << endl;
//	return 0;
//}