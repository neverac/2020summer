#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef long long ll;

const int MAX_N = 200088;

char ch[MAX_N];

int main()
{
    int K, L = -1;
    scanf("%d \n%s", &K, ch);
    while (ch[++L])
    {
        ch[L] -= 'a';
    }
    vector<int> B[26];
    for (int i = 0; i < 26; i++)
    {
        B[i].push_back(-1);
    }
    for (int i = 0; i < L; i++)
    {
        B[ch[i]].push_back(i);
    }
    for (int i = 0; i < 26; i++)
    {
        B[i].push_back(L);
    }
    ll ans = 0;
    for (int i = 0; i < 26; i++)
    {
        const vector<int> &cur = B[i];
        int lb = 1, rb = 1;
        while (rb + 1 < cur.size())
        {
            ans += (ll)(cur[rb] - cur[lb - 1]) * (cur[rb + 1] - cur[rb]);
            if (++rb - lb + 1 > K)
            {
                ++lb;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}