#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    LL ans = 100, num = 0, dq = 1e9;
    while (n--)
    {
        LL ls;
        cin >> ls;
        if (ls <= dq)
        {
            num = ans / ls;
            dq = ls;
        }
        else
        {
            ans += num * (ls - dq);
            dq = ls;
        }
        num = min(num, 100000LL);
    }
    cout << ans;
    return 0;
}