#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll num[233333];
ll sum;

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        sum = 0;
        for (int i = 1; i <= n; i++)
            cin >> num[i], sum += num[i];
        ll ls = 0, ans = -1e15;
        int l1, r1, l, r;
        for (int i = 1; i <= n; i++)
        {
            if (ls <= 0)
            {
                ls = num[i];
                l1 = i;
                r1 = i;
            }
            else
            {
                ls += num[i];
                r1 = i;
            }
            // cout << ls << endl;
            if (ans < ls)
            {
                ans = ls;
                l = l1;
                r = r1;
            }
        }
        // cout << ans << endl;
        if (ans < sum || (sum == ans && l == 1 && r == n))
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
