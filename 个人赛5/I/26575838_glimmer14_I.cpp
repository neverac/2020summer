#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;
char s[N];
int p0[N], p1[N];
int ans[N];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", s);
        int c0 = 0, c1 = 0, n = strlen(s);
        for (int i = 0; i < n; i ++)
        {
            int tt = s[i] - '0';
            tt & 1 ? p1[c1++] = tt : p0[c0++] = tt;
        }

        int cnt = 0, pp1 = 0, pp0 = 0;
        while (pp1 < c1 && pp0 < c0)
            ans[cnt++] = p1[pp1] < p0[pp0] ? p1[pp1++] : p0[pp0++];

        while (pp1 < c1)
            ans[cnt++] = p1[pp1++];
        
        while (pp0 < c0)
            ans[cnt++] = p0[pp0++];
        
        for (int i = 0; i < cnt; i ++)
            printf("%d", ans[i]);
        putchar('\n');
    }
    
}