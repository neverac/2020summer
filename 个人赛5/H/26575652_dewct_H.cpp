#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
int prime[maxn];
bool not_prime[maxn];
int main()
{
    ios::sync_with_stdio(false);
    int n, cnt = 0;
    n = 5000;
    memset(not_prime, 0, sizeof(not_prime));
    not_prime[1] = true;
    for (int i = 1; i <= n; i++)
    {
        if (!not_prime[i])
            prime[++cnt] = i;
        for (int j = 1; j <= cnt; j++)
        {
            if (prime[j] * i > n)
                break;
            not_prime[prime[j] * i] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
    cin >> n;
    int ls = n;
    while (not_prime[ls])
        ls++;
    cout << ls << endl;
    for (int i = 1; i < n; i++)
        cout << i << " " << i + 1 << endl;
    cout << 1 << " " << n << endl;
    for (int i = 1; i <= ls - n; i++)
        cout << i << " " << i + n / 2 << endl;
    return 0;
}