#include <iostream>
#define _USE_MATH_DEFINES ///Определение математических констант
#include <cmath> ///Библиотека с математическими функциями
#define M_PI 3.14159265358979323846 ///Константа Пи


double func(double x)
{
    //return sin(x) / x;
    return (1) / (sqrt(2 * x * x + 2));
}

double funcSimps(double x)
{
    //return sin(x) / x;
    return (sin(x*x*x-9))/(2*x*x+1);
}

 /// Метод Симпсона
//int main()
// {
//     //const double pi = 3.14159265358979;
//
//     int n = 8;
//     int m = 4;
//     double a = 0.7;// *M_PI;
//     double b = 1.5;// *M_PI;
//     double h = (b - a) / n;
//     double s1 = 0;
//     for (int i = 1; i <= m; i++)
//     {
//         s1 = s1 + funcSimps(a + (2 * i - 1) * h);
//     }
//     double s2 = 0;
//     for (int i = 1; i <= m - 1; i++)
//     {
//         s2 = s2 + funcSimps(a + 2 * i * h);
//     }
//     double s = (h / 3) * (funcSimps(a) + funcSimps(b) + 4 * s1 + 2 * s2);
//     std::cout << "Метод Симпсона = " << s << std::endl;
//     
// }



/// Метод трапеций
int main()
{
    setlocale(LC_ALL, "rus");
    int n = 3;
    double a = 0.6; // * M_PI;
    double b = 1.5; // * M_PI;
    double h = (b - a) / n;
    double s = 0;
    for (int i = 1; i <= n-1; i++)
    {
        s = s + func(a + i * h);
    }
    s = (h / 2) * (func(a) + func(b) + 2 * s);
    std::cout << "Метод трапеций = " << s << std::endl;
    
    

    /// Метод Симпсона
    int n1 = 6;
    int m1 = 3;
    double a1 = 0.7; // * M_PI;
    double b1 = 1.5; // * M_PI;
    double h1 = (b1 - a1) / n1;
    double s1 = 0;
    for (int i = 1; i <= m1; i++)
    {
        s1 = s1 + funcSimps(a1 + (2 * i - 1) * h1);
    }
    double s2 = 0;
    for (int i = 1; i <= m1 - 1; i++)
    {
        s2 = s2 + funcSimps(a1 + 2 * i * h1);
    }
    double s3 = (h1 / 3) * (funcSimps(a1) + funcSimps(b1) + 4 * s1 + 2 * s2);
    std::cout << "Метод Симпсона = " << s3 << std::endl;
   
    
}
