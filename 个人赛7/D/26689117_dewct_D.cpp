#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll num[23333];
int aa[5] = {0, 2, 3, 5, 7};

ll work(ll x)
{
    while (x % 2 == 0)
        x /= 2;
    ll ans = 1, ls = 0, lssum = 0;
    for (int i = 1; i <= 4; i++)
    {
        ls = 1;
        lssum = 1;
        while (x % aa[i] == 0)
        {
            x /= aa[i];
            ls *= aa[i];
            lssum += ls;
        }
        ans *= lssum;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
        cout << work(num[i]) << endl;
    }
    return 0;
}