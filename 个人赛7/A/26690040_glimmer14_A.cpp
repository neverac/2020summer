#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, M = 26;
char s[N];
int pos[M][N];
int cnt[M];

typedef long long ll;

int main()
{
    int k;
    scanf("%d %s", &k, s + 1);
    int n = strlen(s + 1);
    ll ans = 0;
    for (int i = 1; i <= n; i ++)
    {
        int c = s[i] - 'a';
        pos[c][++cnt[c]] = i;
        for (int j = 0; j < M; j ++)
            ans += (cnt[j] < k ? pos[j][cnt[j]] : pos[j][cnt[j]] - pos[j][cnt[j] - k]);
    }
    cout << ans << endl;
}