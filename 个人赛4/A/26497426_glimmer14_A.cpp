#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 10;
int h[N], d[N], n, a, b;
int sub[N];

int id[N];
ll psum[N];
bool comp(int x, int y)
{
    // return h[x] > h[y] || (h[x] == h[y] && d[x] < d[y]);
    return sub[x] > sub[y];
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i ++)
        cin >> h[i] >> d[i], id[i] = i, sub[i] = h[i] - d[i];
    sort(id + 1, id + 1 + n, comp);

    ll bb = 0;
    for (int i = 1; i <= n; i++)
        bb += d[i];
    if (b == 0)
    {
        cout << bb << endl;
        return 0;
    }

    int cc = n;
    for (int i = 1; i <= n; i ++)
    {
        if (sub[id[i]] <= 0)
        {
            cc = i - 1;
            break;
        }
        psum[i] = psum[i - 1] + sub[id[i]];
    }
    
    ll ans = 0;
    if (cc < b)
    {
        ans = psum[cc];
        for (int i = 1; i <= n; i ++)
        {
            ll tt = (ll)h[i] << a;
            ll aa = psum[cc] + tt;
            if (sub[i] <= 0) aa -= d[i];
            else aa -= h[i];
            ans = max(ans, aa);
        }
    }
    else
    {
        ans = psum[b];
        for (int i = 1; i <= n; i ++)
        {
            ll tt = (ll)h[i] << a;
            ll aa = psum[b];
            if (sub[i] < sub[id[b]]) aa = psum[b - 1] + tt - d[i];
            else aa = psum[b] + tt - h[i];
            ans = max(ans, aa);
        }
    }
    cout << ans + bb << endl;

}