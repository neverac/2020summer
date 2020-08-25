#include <bits/stdc++.h>
using namespace std;

map<string, bool> vis;
int cnt[110];

int main()
{
    int n, m;
    cin >> n >> m;
    string s;
    while (m--)
    {
        cin >> s;
        if (!vis[s])
            vis[s] = true, cnt[s.length()] ++;
        
    }
    int ans = 0;
    for (int i = 1; i < 105; i ++)
    {
        while (cnt[i] && i <= n)
            n -= i + 1, cnt[i] --, ans ++;
    }
    cout << ans << endl;
}