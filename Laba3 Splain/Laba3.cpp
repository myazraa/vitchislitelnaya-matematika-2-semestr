#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int const n = 6;
	double masX[n] = { -1.1, -0.2, 0.1, 1, 1.8, 2.7 };
	double masY[n] = { 6.63552, -4.43904, 1.94271, 29.53125, 27.57888, 4.22577 };
	/*double masX[n] = { -5,-3,-2,0,4,5,8 };
	double masY[n] = { 7,6,5,10,-10,-7,6 };*/
	double masA[n];
	double masB[n];
	double masC[n];
	double masZ[n];
	masZ[0] = -1;
	double d, e;
	cout << setw(10) << "Xk" << setw(10) << "Yk" << setw(10) << "Zk" 
		 << setw(10) << "Ak" << setw(10) << "Bk" << setw(10) << "Ck" << endl;
	cout << setw(10) << masX[0] << setw(10) << masY[0] << setw(10) << masZ[0] << endl;
	for (int k = 1; k < n; k ++)
	{
		d = masX[k] - masX[k - 1];
		e = masY[k] - masY[k - 1];
		masA[k] = e / (d * d) - masZ[k - 1] / d;
		masB[k] = 2 * e / d - masZ[k - 1];
		masC[k] = masY[k];
		masZ[k] = masB[k];

		cout << setprecision(4) << setw(10) << masX[k] << setw(10) << masY[k] << setw(10) << masZ[k] << setw(10) 
											<< masA[k] << setw(10) << masB[k] << setw(10) << masC[k] << endl;
	}
	


}