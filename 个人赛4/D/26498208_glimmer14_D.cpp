#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    int t, n, a, b;
    cin >> t;
    for (int i = 1; i <= t; i ++)
    {
        cin >> n >> a >> b;
        bool ans = (n / gcd(a, b)) & 1;
        printf("Case #%d: ", i);
        cout << (ans ? "Yuwgna" : "Iaka") << endl;
    }
    
}