#include <iostream>
#include <cmath>

using namespace std;

double Fib(int n) // Стандартна послідовність Фібоначчі
{
	if (n == 0)
		return 1;
	if (n == 1)
		return 1;
	if (n > 1)
		return Fib(n - 1) + Fib(n - 2);
}

double Bin(int k, int n) // Біноміальний к.
{
	if (k == n || k == 0)
		return 1;
	if (n > 0)
		return Bin(k - 1, n - 1) + Bin(k, n - 1);
}

double F(int k, int n) // Послідовність Фібоначчі за ф. суми ітерація
{
	double s = 0;
	for (k = 0; k <= n / 2; k++)
		s += Bin(k, n - k);
	return s;
}

int d(int level, int& depth) // Глибина і рівень
{
	if (level > depth)
		depth = level;
	cout << "level = " << level << endl;
	return 0;
}

double F(int k, int n, double t, int level, int &depth) // Послідовність Фібоначчі за сумою рекурсія спуск++
{
	depth = 0;
	t = t + Bin(k, n - k);
	if (k >= n / 2)
		return t;
	else
		d(level + 1, depth); // перенаправлення на ф-цію d
	cout << "depth = " << depth << endl;
		return F(k + 1, n, t,level+1, depth);
}

int main()
{
	int k, n, depth;

	cout << "k = "; cin >> k;
	cout << "n = "; cin >> n;

	cout << "Binom " << Bin(k, n) << endl; // біноміальний к.

	cout << "Fibonacci ";
	for (int i = 0; i <= n; ++i) // послідовність чисел Фобіначчі
		cout << Fib(i) << " ";
	cout << endl;

	cout << "(iter) Result " << F(k, n) << endl; // послідовність за формулою суми ітерація
	cout << "(rec down ++) Result " << F(0, n, 0, 0, depth); // послідовність за формулою суми  рекурсія

	return 0;
}