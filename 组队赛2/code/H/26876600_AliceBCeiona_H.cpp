#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll ans = n * (n + 1);
        ans = ans ^ (n + 1);
        cout << ans << endl;
    }
    return 0;
}