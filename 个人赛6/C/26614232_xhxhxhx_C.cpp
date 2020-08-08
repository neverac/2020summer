#include <iostream>
#include <queue>
#include <stdio.h>
#include <string.h>
using namespace std;

const int MAX_N = 200088;

struct bcj
{
    int par;
    int rank;
} T[MAX_N];

void init();
int findp(int x);
void unite(int a, int b);
bool same(int a, int b);

int main()
{
    int n, k, x, y;
    scanf("%d%d", &n, &k);
    init();
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

void init()
{
    for (int i = 0; i < MAX_N; i++)
    {
        T[i].par = i;
        T[i].rank = 0;
    }
}

int findp(int x)
{
    if (T[x].par == x)
    {
        return x;
    }
    return T[x].par = findp(T[x].par);
}

void unite(int a, int b)
{
    a = findp(a);
    b = findp(b);

    if (a != b)
    {
        if (T[a].rank > T[b].rank)
        {
            T[b].par = a;
        }
        else if (T[a].rank < T[b].rank)
        {
            T[a].par = b;
        }
        else
        {
            T[b].par = a;
            T[a].rank++;
        }
    }
}

bool same(int a, int b)
{
    return findp(a) == findp(b);
}