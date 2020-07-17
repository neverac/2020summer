#include <algorithm>
#include <cstdio>
using namespace std;

const int MAX_N = 100008;

int cnt[MAX_N];

int main()
{
    int N, Q, x, b, c;
    scanf("%d", &N);
    long long sum = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &x);
        sum += x;
        cnt[x]++;
    }
    scanf("%d", &Q);
    while (Q--)
    {
        scanf("%d%d", &b, &c);
        int &cur = cnt[b];
        cnt[c] += cur;
        sum += cur * (c - b);
        cur = 0;
        printf("%lld\n", sum);
    }
    return 0;
}
