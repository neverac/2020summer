#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;

const int MAX_W = 2;
const int MAX_BIT = 30;
const int MAX_N = 100088;

struct P
{
    P *next[MAX_W];
    int val;
    P() : val(-1)
    {
        memset(next, 0, sizeof(next));
    }
} pool[MAX_N * (MAX_BIT + 2)];
int pt;
char buf[64];
void insert(const char *const str, P *root);
void insert(int x, P *root);

unsigned dfs(P *const v, int cnt);

int A[MAX_N];

int main()
{
    int n, x;
    scanf("%d", &n);
    P *const root = new (pool + pt++) P;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", A + i);
    }
    sort(A, A + n);
    for (int i = 0; i < n; i++)
    {
        insert(A[i], root);
    }
    printf("%u\n", dfs(root, MAX_BIT - 1));
    return 0;
}

void insert(const char *const str, P *root)
{
    P *p = root;
    int i = -1, num = 0;
    while (str[++i])
    {
        int index = str[i] - '0';
        num = (num << 1) + index;
        if (p->next[index] == nullptr)
        {
            p->next[index] = new (pool + pt++) P();
        }
        p = p->next[index];
    }
    p->val = num;
}

void insert(int x, P *root)
{
    for (int k = 0; k < MAX_BIT; k++)
    {
        buf[k] = (x & 1) + '0';
        x >>= 1;
    }
    reverse(buf, buf + MAX_BIT);
    buf[MAX_BIT] = 0;
    insert(buf, root);
}

unsigned dfs(P *const v, int cnt)
{
    if (v->next[0] && v->next[1])
    {
        int a = dfs(v->next[0], cnt - 1) | (1u << cnt);
        int b = dfs(v->next[1], cnt - 1) | (1u << cnt);
        return min(a, b);
    }
    else if (v->next[0])
    {
        return dfs(v->next[0], cnt - 1);
    }
    else if (v->next[1])
    {
        return dfs(v->next[1], cnt - 1);
    }
    else
    {
        return 0;
    }
}