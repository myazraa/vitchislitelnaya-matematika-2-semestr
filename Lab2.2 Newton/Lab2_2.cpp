#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int const n = 5;
    double masX[6] = { -1.1, -0.2, 0.1, 1, 1.8, 2.6 };
    double masY[6] = {1.66419, -2.94912, 1.94271, 24, 27.57888, 6.88896};
    //double masY1[6][6];
    //double masX[6] = { 0.4,1.9,4.7,8.2,11.7,19.3 };
    //double masY[6] = { 7.6,9.2,-13.8,6.0,9.8,-14.2 };
    double masY1[6][6];
    double x = -0.7;
    double xX[6];
    double num, den;
    
    for (int i = 0; i <= n; i++)
    {
        //xX[i] = masX[i];
        masY1[i][0] = masY[i];
    }

    for (int j = 1; j <= n; j++)
    {
        for (int i = 0; i <= n - j; i++)
        {

            num = masY1[i + 1][j - 1] - masY1[i][j - 1];
            den = masX[i + j] - masX[i];
            masY1[i][j] = num / den;
           // cout << num << "num = " << endl;
            //cout << den << "den = " << endl;
            //cout << masY1[i][j] << endl;
        }
    }

 /*   for (int m = 1; m < 6; m++)
    {
        for (int k = 0; k < 6 - m; k++)
        {
            if (m == 1) {
                masY1[k][m] = (masY[k + 1] - masY[k]) / (masX[k + 1] - masX[k]);
            }
            else {
                masY1[k][m] = (masY1[k + 1][m - 1] - masY1[k][m - 1]) / (masX[k + m] - masX[k]);
            }
            cout << masY1[k][m] << endl;
        }
    }*/

    double NewtonF = masY1[0][0];
    double prod = 1;
    for (int k = 1; k <= n; k++)
    {
        prod = prod * (x - masX[k - 1]);
        NewtonF = NewtonF + masY1[0][k] * prod;
    }
    cout << NewtonF << endl;

    double NewtonB = masY1[n][0];
    prod = 1;
    for (int k = 1; k <= n; k++)
    {
        prod = prod * (x - masX[n - k + 1]);
        NewtonB = NewtonB + masY1[n - k][k] * prod;
    }
    cout << NewtonB << endl;






}
