#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

char a[233];

int main()
{
    LL n;
    int t = 0;
    cin >> n;
    while (n)
    {
        a[++t] = 'a' + (n - 1) % 26;
        n--;
        n /= 26;
    }
    for (int i = t; i >= 1; i--)
        printf("%c", a[i]);
    return 0;
}