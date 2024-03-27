#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;
const int n = 11;
const double h = 0.1;

double func(double x, double y)
{
    return sin(x) * cos(y);
}



string EulerX(double x, double y)
{
    double masX[n];
    double masY[n];
    masX[0] = x;
    masY[0] = y;
    string XX;
    for (int i = 0; i < n; i++)
    {
        if (i < n - 1)
        {
            masX[i + 1] = masX[i] + h;
        }
        XX += to_string(masX[i]) + "\n";
        //YY += to_string(masY[i]) + "\n";
        //cout << setw(5) << XX;//masX[i] << setw(15) << masY[i] << endl;

    }
    return XX;
}

string Euler(double x, double y)
{
    double masX[n];
    double masY[n];
    masX[0] = x;
    masY[0] = y;
    //string XX;
    string YY;
    for (int i = 0; i < n; i++)
    {
        if (i < n-1)
        {
            masX[i+1] = masX[i] + h;
            masY[i+1] = masY[i] + h * func(masX[i], masY[i]);
        }
        //XX += to_string(masX[i]) + "\n";
        YY += to_string(masY[i]) + "\n";
        //cout << setw(5) << XX;//masX[i] << setw(15) << masY[i] << endl;

    }     
    return YY;
}

void EulerMod(double x, double y)
{
    double masX[n];
    double masY[n];
    masX[0] = x;
    masY[0] = y;
    for (int i = 0; i < n; i++)
    {
        if (i < n - 1)
        {
            masX[i + 1] = masX[i] + h;
            masY[i + 1] = masY[i] + h *func(masX[i] + h/2, masY[i] + (h/2) * func(masX[i] + h, masY[i]));
        }
        //cout << masX[i] << endl;
        cout << masY[i] << endl;
    }
}

void RungeKutt(double x, double y)
{
    double masX[n];
    double masY[n];
    masX[0] = x;
    masY[0] = y;
    for (int i = 0; i < n; i++)
    {
        if (i < n - 1)
        {
            masX[i + 1] = masX[i] + h;
            double z1 = h * func(masX[i], masY[i]);
            double z2 = h * func(masX[i] + h / 2, masY[i] + z1 / 2);
            double z3 = h * func(masX[i] + h / 2, masY[i] + z2 / 2);
            double z4 = h * func(masX[i] + h, masY[i] + z3);
            masY[i + 1] = masY[i] + (z1 + 2 * z2 + 2 * z3 + z4) / 6;
        }
        //cout << masX[i] << endl;
        cout << masY[i] << endl;
    }
}

void Adams(double x, double y)
{
    double masX[n];
    double masY[n];
    masX[0] = x;
    masY[0] = y;
    /// Метод порядка m = 1
    for (int i = 0; i < n; i++)
    {
        if (i < 1)
        {
            masX[i + 1] = masX[i] + h;
            double z1 = h * func(masX[i], masY[i]);
            double z2 = h * func(masX[i] + h / 2, masY[i] + z1 / 2);
            double z3 = h * func(masX[i] + h / 2, masY[i] + z2 / 2);
            double z4 = h * func(masX[i] + h, masY[i] + z3);
            masY[i + 1] = masY[i] + (z1 + 2 * z2 + 2 * z3 + z4) / 6;
        }
        else
        {
            if (i < n - 1)
            {
                masX[i + 1] = masX[i] + h;
                double a = func(masX[i], masY[i]);
                double b = func(masX[i - 1], masY[i - 1]);
                double c = 3 * a - b;
                masY[i + 1] = masY[i] + (h / 2) * c;
            }
        }
        cout << masY[i] << endl;
    }
    /// Метод порядка m = 2
    for (int i = 0; i < n; i++)
    {
        if (i < 2)
        {
            masX[i + 1] = masX[i] + h;
            double z1 = h * func(masX[i], masY[i]);
            double z2 = h * func(masX[i] + h / 2, masY[i] + z1 / 2);
            double z3 = h * func(masX[i] + h / 2, masY[i] + z2 / 2);
            double z4 = h * func(masX[i] + h, masY[i] + z3);
            masY[i + 1] = masY[i] + (z1 + 2 * z2 + 2 * z3 + z4) / 6;
        }
        else
        {
            if (i < n - 1)
            {
                masX[i + 1] = masX[i] + h;
                double a = func(masX[i], masY[i]);
                double b = func(masX[i - 1], masY[i - 1]);
                double c = func(masX[i - 2], masY[i - 2]);
                double d = 23 * a - 16 * b + 5 * c;
                masY[i + 1] = masY[i] + (h / 12) * d;
            }
        }
        cout << masY[i] << endl;
    }
    /// Метод порядка m = 3
    for (int i = 0; i < n; i++)
    {
        if (i < 3)
        {
            masX[i + 1] = masX[i] + h;
            double z1 = h * func(masX[i], masY[i]);
            double z2 = h * func(masX[i] + h / 2, masY[i] + z1 / 2);
            double z3 = h * func(masX[i] + h / 2, masY[i] + z2 / 2);
            double z4 = h * func(masX[i] + h, masY[i] + z3);
            masY[i + 1] = masY[i] + (z1 + 2 * z2 + 2 * z3 + z4) / 6;
        }
        else
        {
            if (i < n - 1)
            {
                masX[i + 1] = masX[i] + h;
                double a = func(masX[i], masY[i]);
                double b = func(masX[i - 1], masY[i - 1]);
                double c = func(masX[i - 2], masY[i - 2]);
                double d = func(masX[i - 3], masY[i - 3]);
                double e = 55 * a - 59 * b + 37 * c - 9 * d;
                masY[i + 1] = masY[i] + (h / 24) * e;
            }
        }
        cout << masY[i] << endl;
    }



        //cout << masX[i] << endl;
        
    }




int main()
{
    
   cout << setw(4) << EulerX(0, 1) << Euler(0, 1);
   /*EulerMod(0, 1);
   RungeKutt(0, 1);
   Adams(0, 1)*/;
}
