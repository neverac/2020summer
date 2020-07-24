#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int k, n, s, p;
    cin >> k >> n >> s >> p;
    int x;
    if (n % s == 0)
        x = n / s;
    else
        x = n / s + 1;
    x *= k;
    for (int i = 1; i <= x; i++)
    {
        if (i * p >= x)
        {
            cout << i;
            break;
        }
    }
    return 0;
}