#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <cmath>
using namespace std; 

double qq(double x, double a, double x1, double d, double k, double y1)
{
    return a * x * x * x / 3 - (2 * a * x1 + k) * x * x / 2 + (a * x1 * x1 + y1 - d) * x;   
}

int main()
{
	int t;
    cin >> t;
    while(t--)
    {
        double x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        double a = (y2 - y1) / (x2 - x1) / (x2 - x1);
        double k = (y3 - y2) / (x3 - x2); 
        double d = y2 - k * x2;
        printf("%.2f\n",fabs(qq(x2, a, x1, d, k, y1) - qq(x3, a, x1, d, k, y1)));
    }
	return 0;
}