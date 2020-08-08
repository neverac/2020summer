#include <cstdio>
using namespace std;

const int MAX_N = 200088;

struct UFS
{
    int par;
    int rank;
} ufs[MAX_N];

void init(const int n);
int findp(int x);
void unite(int a, int b);
bool same(int a, int b);

int main()
{
    int n, k, x, y;
    scanf("%d%d", &n, &k);
    init(n + 1);
    int cnt = 0;
    for (int i = 0; i < k; i++)
    {
        scanf("%d%d", &x, &y);
        if (!same(x, y))
        {
            cnt++;
            unite(x, y);
        }
    }
    printf("%d\n", k - cnt);
    return 0;
}

void init(const int n)
{
    for (int i = 0; i <= n; i++)
    {
        ufs[i].par = i;
        ufs[i].rank = 0;
    }
}

int findp(int x)
{
    if (ufs[x].par == x)
    {
        return x;
    }
    return ufs[x].par = findp(ufs[x].par);
}

void unite(int a, int b)
{
    a = findp(a);
    b = findp(b);

    if (a != b)
    {
        if (ufs[a].rank > ufs[b].rank)
        {
            ufs[b].par = a;
        }
        else if (ufs[a].rank < ufs[b].rank)
        {
            ufs[a].par = b;
        }
        else
        {
            ufs[b].par = a;
            ufs[a].rank++;
        }
    }
}

bool same(int a, int b)
{
    return findp(a) == findp(b);
}