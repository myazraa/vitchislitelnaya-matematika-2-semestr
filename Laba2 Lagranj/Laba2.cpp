#include <iostream>
using namespace std;

int main()
{
    double masX[6] = { -1.1, -0.2, 0.1, 1, 1.8, 2.6 };
    double masY[6] = { 1.66419, -2.94912, 1.94271, 24, 27.57888, 6.88896 };
    double x = -0.7;
    double LaGrange = 0;
    double znam, chisl;
    
    for (int k = 0; k < 6;  k++)
    {
        double p = 1;
        chisl = 1; 
        znam = 1;

        for (int i = 0; i < 6; i++)
        {
            if (i != k)
            {
              chisl = chisl * (x - masX[i]);
            }
        }
        
        for (int j = 0; j < 6; j++)
        {
            if (j != k)
            {
                znam = znam * (masX[k] - masX[j]);
            }
        }
       
        LaGrange = LaGrange + masY[k] * chisl / znam;
    }

    cout << "LaGrange = " << LaGrange << endl;
}
