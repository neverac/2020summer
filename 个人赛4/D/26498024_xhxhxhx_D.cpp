#include <algorithm>
#include <cstdio>
using namespace std;

int gcd(int x, int y);

int main()
{
    int t, n, a, b;
    scanf("%d", &t);
    for (int casen = 1; casen <= t; casen++)
    {
        scanf("%d%d%d", &n, &a, &b);
        int ans = n / gcd(a, b);
        printf("Case #%d: %s\n", casen, ans & 1 ? "Yuwgna" : "Iaka");
    }
    return 0;
}

int gcd(int x, int y)
{
    while (y)
    {
        int tmp = y;
        y = x % y;
        x = tmp;
    }
    return x;
}