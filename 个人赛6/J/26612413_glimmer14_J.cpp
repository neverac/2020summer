#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll n, k, x, ans = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i ++)
    {
        cin >> x;
        ans += x / k + (x % k != 0);
    }
    cout << ans / 2 + (ans % 2 != 0) << endl;
}