//Точки минимума
#include <iostream>
#include <cmath>
using namespace std;

double f(double x)
{
	return ((x * x + 2 * x + 2) / (x * x + 2 * x + 5));
}
int main()
{
	double x0 = 0;
	double d = 0.1;
	double xR, xC, xL, xN, a=0, b=0;

	setlocale(LC_ALL, "rus");
	xC = x0;
	xL = x0 - d;
	xR = x0 + d;
	cout << "Метод Свенна " << endl;
	while (!((f(xL) > f(xC)) && (f(xR) > f(xC))))
	{
		if ((f(xL) > f(xC)) && (f(xC) > f(xR)))
		{
			xN = xR + 2 * d;
			xL = xC;
			xC = xR;
			xR = xN;
		}
		else 
			if ((f(xL) < f(xC)) && (f(xC) < f(xR)))
			{
				xN = xL - 2 * d;
				xR = xC;
				xC = xL;
				xL = xN;
			}
		d = 2 * d;
		a = xL;
		b = xR;	
	}
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	cout << "Метод деления пополам " << endl;
	double eps = 0.001;
	double c, c1, c2, c3;

	while (b - a >= 2 * eps) {
		c1 = (3 * a + b) / 4;
		c2 = (a + b) / 2;
		c3 = (a + 3 * b) / 4;
		if ((f(c1) < f(c2)) && (f(c2) < f(c3))) {
			b = c2;
		}
		else
			if ((f(c1) > f(c2)) && (f(c2) > f(c3))) {
				a = c2;
			}
			else
			{
				a = c1;
				b = c3;
			}
	}
	c = (a + b) / 2;
	cout << "c = " << c << endl;

	cout << "Метод золотого сечения " << endl;
	double phi, z, z1, z2;

	phi = (sqrt(5) - 1) / 2;
	while (b - a >= 2 * eps) {
		z1 = phi * a + (1 - phi) * b;
		z2 = (1 - phi) * a + phi * b;
		if (f(z1) < f(z2)) {
			b = z2;
		}
		else
			if (f(z1) > f(z2)) {
				a = z1;
			}
	}
	z = (a + b) / 2;
	cout << "z = " << z << endl;
}