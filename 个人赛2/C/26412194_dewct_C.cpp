#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

string a;

int main()
{
    int t;
    cin >> t;
    int tot = 0;
    while (t--)
    {
        tot++;
        cin >> a;
        int len = a.length();
        LL ans;
        for (int i = 1; i < len - 3; i++)
        {
            LL ans1 = 0, ans2 = 0, ans3 = 0;
            for (int j = 0; j <= i - 1; j++)
                ans1 = ans1 * 10ll + (LL)(a[j] - '0');
            for (int j = 1; j <= i; j++)
                ans2 = ans2 * 10ll + (LL)(a[j] - '0');
            ans1 += a[i] - '0';
            ans2 += a[0] - '0';
            ans3 = max(ans1, ans2);
            LL ls1 = (LL)(a[i + 1] - '0'), ls2 = (LL)(a[i + 2] - '0');
            LL ans4 = 0;
            for (int j = i + 3; j < len; j++)
                ans4 = ans4 * 10ll + (LL)(a[j] - '0');
            // cout << ans3 << " " << ls1 << " " << ls2 << " " << ans4 << endl;
            if (i == 1)
                ans = ans3 - ls1 * ls2 / ans4;
            else
                ans = max(ans, ans3 - ls1 * ls2 / ans4);
        }
        printf("Case #%d: %lld\n", tot, ans);
    }
    return 0;
}