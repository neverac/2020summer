#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;
int x[1010];
int y[1010];
int z[1010];
int d[1010];
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin>>x[i]>>y[i]>>z[i];
        d[i] = x[i]*x[i]+y[i]*y[i]+z[i]*z[i];
    }
    sort(d,d+n);
    cout << setiosflags(ios::fixed) << setprecision(3) << pow(d[0],0.5) << endl;
    return 0;
}
