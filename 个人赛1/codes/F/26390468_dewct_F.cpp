#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL num[233333];
int ton[100050];

int main()
{
    int n;
    cin >> n;
    LL sum = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &num[i]);
        ton[num[i]]++;
        sum += num[i];
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int b, c;
        scanf("%d%d", &b, &c);
        sum += ton[b] * (c - b);
        ton[c] += ton[b];
        ton[b] = 0;
        printf("%lld\n", sum);
    }
    return 0;
}