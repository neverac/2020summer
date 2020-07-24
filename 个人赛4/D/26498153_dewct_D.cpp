#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int t, tot = 0;
    cin >> t;
    while (t--)
    {
        tot++;
        int n, a, b;
        cin >> n >> a >> b;
        cout << "Case #" << tot << ": ";
        if (n / __gcd(a, b) % 2 == 1)
            cout << "Yuwgna" << endl;
        else
            cout << "Iaka" << endl;
    }
    return 0;
}