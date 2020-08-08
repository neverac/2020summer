#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

char s[N];

int ne[N][10];
int la[10];
int cnt[10];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> s + 1;
        int n = strlen(s + 1);
        memset(cnt, 0, sizeof cnt);
        for (int j = 0; j < 10; j ++)
            la[j] = n + 1;
        for (int i = n; i >= 1; i --)
        {
            int c = s[i] - '0';
            for (int j = 0; j < 10; j ++)
                ne[i][j] = la[j];
            la[c] = i;
            cnt[c] ++;
        }
        for (int j = 0; j < 10; j ++)
            ne[0][j] = la[j];
        
        int ans = 0;
        for (int i = 0; i < 10; i ++)
            ans = max(ans, cnt[i]);
        
        for (int i = 0; i < 10; i ++)
            for (int j = 0; j < 10; j ++)
            {
                if (i == j) continue;
                int tt = 0;
                int pos = 0;
                while (true)
                {
                    pos = ne[pos][i];
                    if (pos == n + 1) break;
                    pos = ne[pos][j];
                    if (pos == n + 1) break;
                    tt += 2;
                }
                ans = max(ans, tt);
                
            }
        
        // cout << ans << endl;
        cout << n - ans << endl;
        
    }
    
}