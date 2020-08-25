#include <cstdio>
#include <algorithm>
#include <memory>
#include <vector>
using namespace std;

const int MAX_N = 100088;

struct UFS
{
    int par;
    int rank;
    UFS() {}
    UFS(int par, int rank) : par(par), rank(rank) {}
} ufs[MAX_N];
void init(const int n);
int find(int x);
void unite(int x, int y);
bool same(int x, int y);

struct Edge
{
    int x;
    int y;
    Edge() {}
    Edge(int x, int y) : x(x), y(y) {}
    bool operator<(const Edge &R) const
    {
        int lmax = max(x, y), rmax = max(R.x, R.y), lmin = x ^ y ^ lmax, rmin = R.x ^ R.y ^ rmax;
        return lmax < rmax || lmax == rmax && lmin < rmin;
    }
};

int deg[MAX_N];

int main()
{
    int n, m, x, y;
    scanf("%d%d", &n, &m);
    init(n);
    vector<Edge> G;
    while (m--)
    {
        scanf("%d%d", &x, &y);
        G.push_back(Edge(x, y));
    }
    sort(G.begin(), G.end());
    for(const auto&e:G)
    {
        if(!same(e.x,e.y))
        {
            unite(e.x, e.y);
            ++deg[e.x];
            ++deg[e.y];
        }
    }
    printf("%d\n", *max_element(deg + 1, deg + n + 1));
    return 0;
}

void init(const int n)
{
    for (int i = 0; i <= n; i++)
    {
        new (ufs + i) UFS(i, 0);
    }
}

int find(int x)
{
    if (ufs[x].par == x)
    {
        return x;
    }
    else
    {
        return ufs[x].par = find(ufs[x].par);
    }
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x != y)
    {
        if (ufs[x].rank < ufs[y].rank)
        {
            ufs[x].par = y;
        }
        else
        {
            ufs[y].par = x;
            if (ufs[x].rank == ufs[y].rank)
            {
                ++ufs[x].rank;
            }
        }
    }
}

inline bool same(int x, int y)
{
    return find(x) == find(y);
}