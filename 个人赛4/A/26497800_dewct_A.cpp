#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

struct qer
{
    int hp, dmg;
} num[233333];

bool vis[233333];
LL po[23];

bool cmp(qer a, qer b)
{
    return a.hp - a.dmg > b.hp - b.dmg;
}

int main()
{
    ios::sync_with_stdio(false);
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++)
        cin >> num[i].hp >> num[i].dmg;
    sort(num + 1, num + n + 1, cmp);
    LL sum = 0;
    po[0] = 1;
    for (int i = 1; i <= 20; i++)
        po[i] = po[i - 1] * 2;
    int tot = b;
    int minn = 2147483640, minn2 = 2147483640, minn3 = 2147483640;
    for (int i = 1; i <= n; i++)
    {
        if (tot && num[i].hp >= num[i].dmg)
        {
            sum += num[i].hp;
            vis[i] = 1;
            tot--;
            if (num[i].hp - num[i].dmg <= minn3)
                minn = num[i].hp, minn2 = num[i].dmg, minn3 = num[i].hp - num[i].dmg;
        }
        else
            sum += num[i].dmg;
    }
    LL ans = sum;
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << num[i].hp << " " << num[i].dmg << endl;
    // }
    // cout << sum << endl;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 1)
        {
            ans = max(ans, sum - num[i].hp + num[i].hp * po[a]);
            // cout << ans << " " << i << endl;
        }
        else
        {
            if (tot > 0)
            {
                ans = max(ans, sum - num[i].dmg + num[i].hp * po[a]);
                // cout << ans << " " << i << endl;
            }
        }
    }
    if (b > 0)
    {
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                ans = max(ans, sum - minn - num[i].dmg + minn2 + num[i].hp * po[a]);
                // cout << ans << " 233 " << i << " " << minn << " " << sum << " " << num[i].hp << endl;
            }
        }
    }
    cout << ans;
    return 0;
}
/*
10 7 2
8 6
5 5
3 7
7 7
3 8
6 1
10 9
4 6
9 5
7 9
*/