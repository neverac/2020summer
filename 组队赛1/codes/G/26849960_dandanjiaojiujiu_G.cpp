#include <algorithm>
#include <cstdio>
#include <stack>
#include <vector>
using namespace std;

typedef long long ll;

const ll INF = 1ll << 60;
const int MAX_N = 100088;

struct P
{
    int x;
    int y;
    P()
    {
    }
    P(int x, int y, int z = 0) : x(x), y(y)
    {
    }
};

int bit[MAX_N], _n;
void add(int i, int x);
int sum(int i);

int A[MAX_N], TA[MAX_N];

int main()
{
    int n;
    scanf("%d", &n);
    _n = MAX_N - 16;
    vector<P> mv;
    vector<int> sorted;
    mv.push_back(P(-1, -1));
    for (int i = 1; i <= n; i++)
    {
        int &cur = A[i];
        scanf("%d", &cur);
        if (cur > mv.back().x)
        {
            mv.clear();
            mv.push_back(P(cur, i));
        }
        else if (cur == mv.back().x)
        {
            mv.push_back(P(cur, i));
        }
        sorted.push_back(cur);
    }
    sort(sorted.begin(), sorted.end());
    // copy(A + 1, A + n + 1, TA);
    // int cnt = remove(A + 1, A + n + 1, mv.front().x) - A - 1;
    // move(A + 1, A + 1 + cnt, A + mv.size() + 1);
    // fill(A + 1, A + mv.size() + 1, mv.front().x);

    vector<int> B, C;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        const int &cur = A[i];
        if (cur < mv.front().x)
        {
            int t1 = i - 1 - sum(cur), t2 = sorted.end() - upper_bound(sorted.begin(), sorted.end(), cur) - t1;
            if (t1 < t2)
            {
                B.push_back(cur);
                ans += t1;
            }
            else
            {
                C.push_back(cur);
                ans += t2;
            }
        }
        add(cur, 1);
    }
    // for (int i = 0; i < mv.size(); i++)
    // {
    //     int tp = B.size() + i + 1;
    //     ans += abs(mv[i].y - tp);
    // }
    // fill(bit, bit + _n + 8, 0);
    // for (int i = 0; i < B.size(); i++)
    // {
    //     ans += i - sum(B[i]);
    //     add(B[i], 1);
    // }
    // fill(bit, bit + _n + 8, 0);
    // for (int i = 0; i < C.size(); i++)
    // {
    //     ans += sum(C[i] - 1);
    //     add(C[i], 1);
    // }
    printf("%lld\n", ans);
    return 0;
}

void add(int i, int x)
{
    ++i;
    while (i < _n)
    {
        bit[i] += x;
        i += i & -i;
    }
}

int sum(int i)
{
    ++i;
    int s = 0;
    while (i)
    {
        s += bit[i];
        i -= i & -i;
    }
    return s;
}