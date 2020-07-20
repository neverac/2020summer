#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long ll;
const int MAX_N = 1 << 16;

bool used[MAX_N];
int D[MAX_N];

int main()
{
    int A, B, C, S;
    for (;;)
    {
        scanf("%d", &A);
        if (!A)
            break;
        scanf("%d%d%d", &B, &C, &S);
        int cnt = 0;
        fill(used, used + MAX_N, false);
        for (; !used[S]; cnt++)
        {
            used[S] = true;
            D[cnt] = S;
            S = (ll)(A * S + B) % C;
        }
        int x = -1, y = 0;
        for (int i = 0; i < cnt; i++)
        {
            x &= D[i];
            y |= D[i];
        }
        for (int i = 15; i >= 0; i--)
        {
            if (x >> i & 1)
            {
                printf("1");
            }
            else if (!(y >> i & 1))
            {
                printf("0");
            }
            else
            {
                printf("?");
            }
        }
        printf("\n");
    }
    return 0;
}
