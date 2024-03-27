#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;


double func(double x)
{
	return exp(2 * x);
}



void zad1()
{
	setlocale(LC_ALL, "rus");
	const double pi = 3.141592654;
	int m1 = 161;		// 8;
	int m2 = 643;		//70;
	double x0 = 1;		//pi / 4;
	double eps = 0.001;
	double s1 = 0;
	s1 = pow((6 * eps / m1), 0.5);
	std::cout << "По первой формуле верхний порог для h = " << s1 << "\n";
	double h1;
	std::cout << "Введите h = ";
	std::cin >> h1;
	double diff = (func(x0 + h1) - func(x0 - h1)) / (2 * h1);
	std::cout << "Производная по первой формуле = " << diff << "\n";

	double s2 = 0;
	s2 = s2 + pow((30 * eps / m2), 0.25);
	std::cout << "По первой формуле верхний порог для h = " << s2 << "\n";
	double h2;
	std::cout << "Введите h = ";
	std::cin >> h2;
	double diff2 = (func(x0 - 2 * h2) - 8 * func(x0 - h2) + 8 * func(x0 + h2) - func(x0 + 2 * h2)) / (12 * h2);
	std::cout << "Производная по второй формуле = " << diff2 << "\n";

}

void zad2()
{
	const int n = 8;
	double masX[n] = {-5,-4,-3,-2,-1,0,1,2};
	double masY[n][n] = { -5,-4,-3,-2,-1,0,1,2,
						 4.89686, 4.97158, 5.03382, 5.08078, 5.11005,5.12000,5.11005,5.08078 };
	double h = 0.1;
	for (int i = 0; i < n; i++)
	{
		masX[i] = 4 + h * i;
		masY[i][0] = pow((1 + pow((masX[i]), 2)), 0.5);
		cout << i << setw(10) << masX[i] << setw(10) << masY[i][0] << endl;

	}
	/*cout << "x=";
	for (int i = 0; i < n; i++) {
		cout << masX[i] << "\t";
	}
	cout << endl;
	cout << "y(x)=";
	for (int i = 0; i < n; i++) {
		cout << masY[i][0] << "\t";
	}*/
	cout << endl;
	cout << endl;

	double Buf[n][n] = { 0 };

	for (int j = 1; j < n; j++)
	{
		for (int i = 0; i < n - j; i++)
		{
			masY[i][j] = masY[i + 1][j - 1] - masY[i][j - 1];
			Buf[i][j] = masY[i][j];
		}
		cout << "D" << j << setw(15);
	}
	cout << endl;
	for (int i = 0; i < n - 1; i++)
	{
		//cout << "D" << i + 1 << ":\t";
		for (int j = 1; j < n - i; j++)
		{

			cout << setw(4) << Buf[i][j] << "\t";
		}

		cout << endl;
	}


	cout << endl;
	cout << endl;

	double s = 0;
	double d = -1;
	double Delta = 0;
	string deltaString = "Delta=";
	string sString = "Погрешность=";
	for (int j = 1; j < n - 1; j++)
	{
		d = (-1) * d;
		s = s + d * masY[0][j] / (j * h);
		Delta = abs((masY[0][j + 1]) / ((j + 1) * h));
		deltaString += to_string(Delta) + "; ";
		sString += to_string(s) + "; ";
	}
	// вывод значений Delta в строчку
	cout << deltaString << endl;
	cout << sString << endl;
	//cout << s << "\t ";

	/*for (int j = 1; j < n; j++)
	{

		cout << "D" << j << endl;
		for (int i = 0; i < n - j; i++)
		{
			masY[i][j] = masY[i + 1][j - 1] - masY[i][j - 1];

			cout << setw(4) << masY[i][j] << endl;
		}
	}
	cout << endl;
	double s = 0;
	double d = -1;
	double Delta = 0;
	for (int j = 1; j < n - 1; j++)
	{
		d = (-1) * d;
		s = s + d * masY[0][j] / (j * h);
		Delta = abs((masY[0][j + 1]) / ((j + 1) * h));
	
		cout << s << " " << endl;

		cout << Delta << " " << endl;
	}*/
	
}

int main()
{	
	setlocale(LC_ALL, "rus");
	cout << "Первая задача ";
	zad1();
	cout << endl;
	cout << "Вторая задача ";
	cout << endl;
	zad2();
}