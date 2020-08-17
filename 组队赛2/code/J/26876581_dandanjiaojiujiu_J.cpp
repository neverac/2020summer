#include <bitset>
#include <iostream>
using namespace std;
typedef long long LL;

const int MAX_N = 512, MAX_M = 16;

bitset<MAX_N> A[MAX_M];

int main()
{
    int T, n, m;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> A[i];
        }
        int ans = MAX_M;
        for (int i = (1 << m) - 1; i; i--)
        {
            bitset<MAX_N> cur;
            int cnt = 0;
            for (int j = 0; j < m; j++)
            {
                if (i >> j & 1)
                {
                    cur |= A[j];
                    ++cnt;
                }
            }
            if (cnt < ans && [&cur, &n]() {
                    for (int i = 0; i < n; i++)
                    {
                        if (!cur[i])
                        {
                            return false;
                        }
                    }
                    return true;
                }())
            {
                ans = cnt;
            }
        }
        printf("%d\n", ans < MAX_M ? ans : -1);
    }
    return 0;
}