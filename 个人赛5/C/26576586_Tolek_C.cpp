#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int p[500], n;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", p + i);
    ll number = 0, money = 100;
    for (int i = 1; i < n; i++) {
        if (p[i + 1] > p[i]) {
            ll mai = min(money / p[i], 100000 - number);
            number += mai;
            money -= p[i] * mai;
            money += p[i + 1] * number;
            number = 0;
        }
    }
    printf("%lld\n", money);
    return 0;
}