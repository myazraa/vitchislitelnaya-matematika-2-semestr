#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    //double masX[6] = { -1.1, -0.2, 0.1, 1, 1.8, 2.6 };
    //double masY[6][6] = {1.66419, -2.94912, 1.94271, 24, 27.57888, 6.88896};
    //double masY1[6][6];
    double masX[6] = { 0.4,1.9,4.7,8.2,11.7,19.3 };
    double masY[6] = { 7.6,9.2,-13.8,6.0,9.8,-14.2 };
    double masY1[6][6];
    double x = 9.8;
    double num, den;
    /*for (int j = 1; j < 6; j++)
    {
        for (int i = 0; i < 6-j; i++)
        {*/

        //num = masY[i + 1][j - 1] - masY[i][j - 1];
        //den = masX[i + j] - masX[i];
        //masY[i][j] = num / den;
        //cout << num <<"num = " << endl;
        //cout << den <<"den = " << endl;
        //cout << masY[i][j] << endl;

    for (int m = 1; m < 6; m++)
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
    }

    double NewtonF = masY1[0][1];
    double prod = 1;
    for (int k = 1; k < 6; k++)
    {
        prod = prod * (x - masX[k - 1]);
        NewtonF = NewtonF + masY1[0][k] * prod;
    }
    cout << NewtonF << endl;

    double NewtonB = masY1[5][0];
    //double prod = 1;
    for (int k = 1; k < 6; k++)
    {
        prod = prod * (x - masX[5 + 1 - k]);
        NewtonB = NewtonB + masY1[5 - k][k] * prod;
    }
    cout << NewtonB << endl;






}
