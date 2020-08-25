#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll t, n, m, x, y;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> x >> y;
        if (y >= x)
            cout << m << endl;
        else
        {
            ll sub = x - y, tt = n - x;
            ll ans = tt / sub + 1;
            // cout << ans << endl;
            if (ans >= m)
                cout << m << endl;
            else
            {
                cout << (n + (m - 1) * y) / x << endl;
            }
            
        }
        
    }
    
}