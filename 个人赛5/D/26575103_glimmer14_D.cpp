#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
    ll t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        ll tt = k / (n - 1);
        ll rr = k % (n - 1);
        ll ans = tt * n;
        if (rr)
            ans += rr;
        else  
            ans -= 1;
        cout << ans << endl;
    }
    
}