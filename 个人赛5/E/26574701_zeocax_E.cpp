#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#define ll long long
using namespace std;
const int INF = 1e9;
inline int readint()
{
    int ret = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return ret;
}
inline ll readll()
{
    ll ret = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return ret;
}

const int maxn = 2e5;

int n;

int A[maxn + 3], idmap[maxn + 3], mnval[maxn + 3], mnto[maxn + 3];
vector<int> blg[maxn + 3];

struct DSU
{
    int fa[maxn + 3];
    int FindFa(int u)
    {
        if (u == fa[u])
            return u;
        return fa[u] = FindFa(fa[u]);
    }
    bool Merge(int u, int v)
    {
        int fu = FindFa(u), fv = FindFa(v);
        if (fu == fv)
            return false;
        fa[fu] = fv;
        return true;
    }
    void Init()
    {
        for (int i = 1; i <= n; i++)
            fa[i] = i;
    }
} D;
struct NODE
{
    int siz, id;
    NODE *ch[2];
};
struct TRIE
{
    NODE pol[maxn * 35], *root, *ncnt, *NIL;
    void Init()
    {
        ncnt = NIL = root = pol;
        NIL->ch[0] = NIL->ch[1] = NIL;
        NIL->siz = NIL->id = 0;
    }
    NODE *NewNode()
    {
        NODE *p = ++ncnt;
        *p = *NIL;
        return p;
    }
    void Modify(NODE *&u, int num, int dep, int val, int id)
    {
        if (u == NIL)
            u = NewNode();
        u->siz += val;
        if (dep < 0)
        {
            u->id = id;
            return;
        }
        int dir = bool(num & (1 << dep));
        Modify(u->ch[dir], num, dep - 1, val, id);
    }
    int Query(NODE *u, int num, int dep)
    {
        if (dep < 0)
            return u->id;
        int dir = bool(num & (1 << dep));
        if (u->ch[dir]->siz)
            return Query(u->ch[dir], num, dep - 1);
        return Query(u->ch[!dir], num, dep - 1);
    }
} T;

int main()
{
    n = readint();
    T.Init();
    D.Init();
    for (int i = 1; i <= n; i++)
        A[i] = readint();
    sort(A + 1, A + 1 + n);
    A[0] = -1;
    for (int i = 1; i <= n; i++)
    {
        T.Modify(T.root, A[i], 29, 1, i);
        if (A[i] == A[i - 1])
            D.Merge(i, i - 1);
    }
    long long ans = 0;
    while (true)
    {
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            if (D.fa[i] == i)
            {
                idmap[i] = ++cnt;
                mnto[cnt] = -1;
                mnval[cnt] = -1;
            }
        if (cnt == 1)
            break;
        for (int i = 1; i <= n; i++)
            blg[idmap[D.FindFa(i)]].push_back(i);
        for (int i = 1; i <= cnt; i++)
        {
            for (int j = 0; j < (int)blg[i].size(); j++)
            {
                int u = blg[i][j];
                T.Modify(T.root, A[u], 29, -1, u);
            }
            for (int j = 0; j < (int)blg[i].size(); j++)
            {
                int u = blg[i][j];
                int resu = T.Query(T.root, A[u], 29);
                if (mnval[i] == -1 || mnval[i] > (A[u] ^ A[resu]))
                {
                    mnval[i] = (A[u] ^ A[resu]);
                    mnto[i] = resu;
                }
            }
            for (int j = 0; j < (int)blg[i].size(); j++)
            {
                int u = blg[i][j];
                T.Modify(T.root, A[u], 29, 1, u);
            }
            blg[i].clear();
        }
        for (int i = 1; i <= n; i++)
            if (D.fa[i] == i && D.Merge(i, mnto[idmap[i]]))
                ans += mnval[idmap[i]];
    }
    printf("%lld\n", ans);
    return 0;
}