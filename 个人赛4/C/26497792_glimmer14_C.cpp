#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int cnt[N];

inline bool judge(int a, int b)
{
    return ((b == 0) || (a > 0 && b > 0) || (a < 0 && b < 0));
}

int main()
{
    int t, n, x;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> n >> x;
        cin >> s;

        int ans = 0;
        if (x == 0) ans ++;

        for (int i = 1; i <= n; i ++)
            if (s[i - 1] == '0') cnt[i] = cnt[i - 1] + 1;
            else cnt[i] = cnt[i - 1] - 1;

        if (cnt[n] == 0)
        {
            for (int i = 1; i <= n; i ++)
                if (cnt[i] == x)
                {
                    ans = -1;
                    break;
                }
            cout << ans << endl;
            continue;
        }

        for (int i = 1; i <= n; i ++)
        {
            int tt = x - cnt[i];
            if (judge(cnt[n], tt) && (tt % cnt[n] == 0))
                ans ++;
        }
        cout << ans << endl;
    }
    
}