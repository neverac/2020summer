#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> p;
const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;
vector<p> tails;
const int maxn = 3e5 + 10;
int cnt, v[10], res[maxn];
 
template<typename T = int>
inline const T read()
{
    T x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = (x << 3) + (x << 1) + ch - '0'; ch = getchar(); }
    return x * f;
}
 
template<typename T>
inline void write(T x)
{
    if (x < 0) { putchar('-'); x = -x; }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
 
bool cmp(const p& a, const p& b)
{
    int a1 = a.first, a2 = a.second;
    int b1 = b.first, b2 = b.second;
    int mxa = max(a1, a2), mxb = max(b1, b2);
    return mxa == mxb ? min(a1, a2) < min(b1, b2) : mxa < mxb;
}
 
void getTail()
{
    for (int i = 0; i < 100; i++)
    {
        if (i % 4 == 0)
        {
            int a = i / 10, b = i % 10;
            if (a >= b || (a + b * 10) % 4)
                tails.push_back(p(a, b));
        }
    }
    sort(tails.begin(), tails.end(), cmp);
}
 
bool solve()
{
    for (p tail : tails)
    {
        int a = tail.first, b = tail.second;
        if (a == b && v[a] < 2) continue;
        if (a != b && (!v[a] || !v[b])) continue;
        v[a]--;
        v[b]--;
        for (int i = 9; i >= 0; i--)
        {
            while (v[i])
            {
                res[cnt++] = i;
                v[i]--;
            }
        }
        res[cnt++] = a;
        res[cnt++] = b;
        return true;
    }
    return false;
}
 
int main()
{
    getTail();
    int t = read();
    while (t--)
    {
        cnt = 0;
        for (int i = 0; i < 10; i++) v[i] = read();
        if (solve())
        {
            int i = 0;
            while (!res[i] && i < cnt - 1) i++;
            while (i < cnt) write(res[i++]);
        }
        else
        {
            if (v[8]) write(8);
            else if (v[4]) write(4);
            else if (v[0]) write(0);
            else write(-1);
        }
        putchar(10);
    }
    return 0;
}