#include <algorithm>
#include <cstdio>
using namespace std;

using ll = long long;

int ans[128];

int main()
{
    ll N;
    scanf("%lld", &N);
    int i;
    for (i = 0; N; i++)
    {
        N--;
        ans[i] = N % 26;
        N /= 26;
    }
    while (i--)
    {
        printf("%c", ans[i] + 'a');
    }
    printf("\n");

    return 0;
}
