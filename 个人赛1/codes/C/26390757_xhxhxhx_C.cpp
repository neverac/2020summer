#include <cstdio>
#include <set>
using namespace std;

const int MAX_N = 100008;

int q[MAX_N], ans[MAX_N];

int main()
{
    int t, n;
    scanf("%d", &t);

    while (t--)
    {
        scanf("%d", &n);
        set<int> ust;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", q + i);
        }
        for (int i = 1; i <= n; i++)
        {
            if (q[i] < i)
            {
                n = -1;
            }
            else
            {
                if (q[i] > q[i - 1])
                {
                    ans[i] = q[i];
                    for (int j = q[i - 1] + 1; j < q[i]; j++)
                    {
                        ust.insert(j);
                    }
                }
                else
                {
                    auto it = ust.begin();
                    ans[i] = *it;
                    ust.erase(it);
                }
            }
        }
        if (~n)
        {
            for (int i = 1; i <= n; i++)
            {
                printf("%d%c", ans[i], i == n ? '\n' : ' ');
            }
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}
