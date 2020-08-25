#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ans = INT_MAX;
    int n, x, y, z;
    cin >> n;
    while (n--)
    {
        cin >> x >> y >> z;
        ans = min(ans, x * x + y * y + z * z);
    }
    double a = sqrt(ans);
    printf("%.3lf\n", a);
    
}