#include <cstdio>
using namespace std;

int main()
{
    int k, n, s, p;
    scanf("%d%d%d%d", &k, &n, &s, &p);
    n = k * ((n + s - 1) / s);
    printf("%d\n", (n + p - 1) / p);
    return 0;
}