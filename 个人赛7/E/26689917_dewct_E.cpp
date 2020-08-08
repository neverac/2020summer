
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll num[15], n;
int m, t;

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> num[i];
    ll sum = 0;
    ll ls, cnt;
    for (int i = 0; i < (1 << m); i++)
    {
        ls = 1;
        cnt = 0;
        for (int j = 0; j < m; j++)
        {
            if (i & (1 << j))
            {
                ls = lcm(ls, num[j]);
                cnt++;
            }
        }
        if (cnt == 0)
            continue;
        if (cnt & 1)
            sum += n / ls;
        else
            sum -= n / ls;
    }
    cout << sum << endl;
    return 0;
}