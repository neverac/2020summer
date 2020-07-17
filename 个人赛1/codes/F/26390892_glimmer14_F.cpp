#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;
int cnt[N];

int main()
{
    ios::sync_with_stdio(false);
    int n, x;
    cin >> n;
    ll sum = 0;
    for (int i = 0; i < n; i ++)
        cin >> x, sum += x, cnt[x] ++;
    ll q, b, c;
    cin >> q;
    while (q--)
    {
        cin >> b >> c;
        sum += (c - b) * cnt[b];
        cnt[c] += cnt[b];
        cnt[b] = 0;
        cout << sum << endl;
    }
    

}
