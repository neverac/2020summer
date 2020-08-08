#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int fa[N];

int getfa(int x)
{
    return fa[x] == x ? x : fa[x] = getfa(fa[x]);
}

int main()
{
    int n, k, x, y;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        cin >> x >> y;
        int px = getfa(x), py = getfa(y);
        if (px != py)
            fa[py] = px;
        else  
            ans ++;
    }

    cout << ans << endl;
}