#include <bits/stdc++.h>
using namespace std;
const int N = 10000 + 5;
typedef long long ll;
int n2, n3, n5, n7;
__int128 mypow(int x, int y)
{
    __int128 ans = 1;
    for (int i = 1; i <= y; i++) ans *= x;
    return ans;
}

void print(__int128 x)
{
    if (!x) return;
    if (x < 0) putchar('-'), x = -x;
    print(x / 10);
    putchar(x % 10 + '0');
}
int main()
{
    int n;
    scanf("%d", &n);
    while (n--) {
        long long x;
        scanf("%lld", &x);
        n2 = n3 = n5 = n7 = 0;
        while (x % 2 == 0) x /= 2, ++n2;
        while (x % 3 == 0) x /= 3, ++n3;
        while (x % 5 == 0) x /= 5, ++n5;
        while (x % 7 == 0) x /= 7, ++n7;
        // cout << n2 << " " << n3 << " " << n5 << " " << n7 << endl;
        __int128 s2 = (mypow(3, n3 + 1) - 1) / 2;
        __int128 s3 = (mypow(5, n5 + 1) - 1) / 4;
        __int128 s4 = (mypow(7, n7 + 1) - 1) / 6;
        print(s2 * s3 * s4);
        printf("\n");
    }
    return 0;
}