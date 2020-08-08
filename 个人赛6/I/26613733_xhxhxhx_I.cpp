#include <cstdio>
#include <iostream>
using namespace std;

const int INF = 1e9;
const int MAX_N = 20088;
struct Edge
{
    int to;
    int next;
    Edge(const int &to, const int &next) : to(to), next(next)
    {
    }
    Edge() : to(-1), next(-1)
    {
    }
} G[2 * MAX_N];
int head[MAX_N];
int deg;

int cnt;
int par[MAX_N];
int depth[MAX_N];
int scnt[MAX_N];
int rk[MAX_N];
int top[MAX_N];
int id[MAX_N];
int son[MAX_N];

int init_t(const int n);
void add_edge(const int &u, const int &v);

void dfs1(const int v);
void dfs2(const int v, const int tp);

int _n;
int dat[1 << 17];
void init(const int n);
int query(const int &left, const int &right, const int k, const int begin, const int end);
void update(int p, const int &x);

int query(int x, int y);

int A[MAX_N];

int main()
{
    int T, N, a, b, c;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);
        int ecnt = N;
        init_t(2 * N);
        fill(A, A + 2 * N, -INF);
        for (int i = 1; i < N; i++)
        {
            scanf("%d%d%d", &a, &b, &c);
            --a, --b;
            add_edge(a, ecnt);
            add_edge(ecnt, b);
            A[ecnt++] = c;
        }
        const int root = 0;
        dfs1(root);
        dfs2(root, root);
        init(2 * N - 1);

        for (char str[16];;)
        {
            scanf(" \n%s", str);
            if (*str == 'D')
            {
                break;
            }
            else
            {
                scanf("%d%d", &a, &b);
                if (*str == 'C')
                {
                    update(id[N + a - 1], b);
                }
                else
                {
                    printf("%d\n", query(a - 1, b - 1));
                }
            }
        }
    }
    return 0;
}

int init_t(const int n)
{
    par[0] = deg = cnt = 0;
    fill(son, son + n + 8, -1);
    fill(head, head + n + 8, -1);
    return 0;
}

void add_edge(const int &u, const int &v)
{
    G[deg] = Edge(v, head[u]);
    head[u] = deg++;
    G[deg] = Edge(u, head[v]);
    head[v] = deg++;
}

void dfs1(const int v)
{
    scnt[v] = 1;
    depth[v] = depth[par[v]] + 1;
    int maxson = -1;
    for (int i = head[v]; ~i; i = G[i].next)
    {
        const int &to = G[i].to;
        if (to != par[v])
        {
            par[to] = v;
            dfs1(to);
            scnt[v] += scnt[to];
            if (scnt[to] > maxson)
            {
                maxson = scnt[to];
                son[v] = to;
            }
        }
    }
}

void dfs2(const int v, const int tp)
{
    top[v] = tp;
    id[v] = cnt;
    rk[cnt++] = v;

    if (~son[v])
    {
        dfs2(son[v], tp);
        for (int i = head[v]; ~i; i = G[i].next)
        {
            const int &to = G[i].to;
            if (to != par[v] && to != son[v])
            {
                dfs2(to, to);
            }
        }
    }
}

void init(const int n)
{
    _n = 1;
    while (_n < n)
    {
        _n <<= 1;
    }
    --_n;

    for (int i = 0; i < n; ++i)
    {
        dat[_n + i] = A[rk[i]];
    }
    for (int i = _n - 1; i >= 0; --i)
    {
        dat[i] = max(dat[(i << 1) + 1], dat[(i << 1) + 2]);
    }
}

int query(const int &left, const int &right, const int k, const int begin, const int end)
{
    if (left <= begin && end <= right)
    {
        return dat[k];
    }
    else if (left <= end && begin <= right)
    {
        return std::max(query(left, right, (k << 1) + 1, begin, (begin + end) >> 1),
                        query(left, right, (k << 1) + 2, ((begin + end) >> 1) + 1, end));
    }
    else
        return -INF;
}

void update(int p, const int &x)
{
    p += _n;
    dat[p] = x;
    while (p)
    {
        p = (p - 1) >> 1;
        dat[p] = max(dat[(p << 1) + 1], dat[(p << 1) + 2]);
    }
}

int query(int x, int y)
{
    int s = -INF;
    while (top[x] != top[y])
    {
        if (depth[top[x]] < depth[top[y]])
        {
            swap(x, y);
        }
        s = std::max(s, query(id[top[x]], id[x], 0, 0, _n));
        x = par[top[x]];
    }
    if (id[x] < id[y])
    {
        swap(x, y);
    }
    s = std::max(s, query(id[y], id[x], 0, 0, _n));
    return s;
}