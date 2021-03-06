#include <iostream>

//Алгоритм Евклида 
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

//Расширенный алгоритм Евклида 
int gcdex(int a, int b, int &x, int &y)
{
	if (b == 0)
	{
		x = 1; y = 0;
		return a;
	}
	int x1(0), y1(1), x2(1), y2(0);
	int r, q;
	while (b > 0)
	{
		q = a / b;
		r = a % b;
		x = x2 - q * x1;
		y = y2 - q * y1;
		a = b; b = r;
		x2 = x1; x1 = x;
		y2 = y1; y1 = y;
	}
	x = x2; y = y2;
	return a;
}

//Обратный элемент a кольца по модулю n
void inverse(int a, int n)
{
	int x, y;
	if (gcdex(a, n, x, y) == 1)
		std::cout << x << std::endl;
	else
		std::cout << "inverse element doesn't exist" << std::endl;
}
