#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef double db;
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
#define low(x) ((x)&-(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define X first
#define Y second
#ifdef _DEBUG
const int N=1e3+10;
#else
const int N=1e6+10;
#endif
const ll mod=1e9+7;
template<typename T> inline T gcd(T a, T b) {
    return !b?a:gcd(b, a%b);
}
template<typename T> inline T q_pow(T a, T x) {
    T ans=1, tmp=a;while (x) {
        if (x&1)(ans*=tmp)%=mod;(tmp*=tmp)%=mod;x>>=1;
    }return ans;
}
template<typename T> inline void re(T &N) {
    int f=1;char c;while ((c=getchar())< '0'||c> '9')if (c=='-')f=-1;N=c-'0';while ((c=getchar())>='0'&&c<='9')N=N*10+c-'0';N*=f;
}
int m, n, t=1, st, en;
struct Xor {
    vector<bitset<1001>>v;
    vector<int>p;
    void init(int n) {
        v.resize(n+1);p.assign(n+1, 0);
    }
    void insert(bitset<1001> x, int up)
    {
        int pos=0;
        for (int i=up;i<=m;i++)if (x[i])
        {
            if (p[i])x^=v[i];
            else if (!pos)pos=i;
        }
        if (pos)
        {
            v[pos]=x;p[pos]=1;
            for (int i=pos-1;i>=1;i--)
                if (v[i][pos])v[i]^=x;
        }
    }
    void filter(bitset<1001> &x)
    {
        for (int i=1;i<=m;i++)
            if (x[i]&&p[i])x^=v[i];
    }
    inline int judge(bitset<1001> &x, int pos)
    {
        if (p[pos])x^=v[pos];x[pos].flip();
        int ans=x.count();
        if (p[pos])x^=v[pos];x[pos].flip();
        return ans;
    }
};
bitset<1001>a[1010];
char s[1010][1010];
struct SegT {
    Xor d[20];
    vector<bitset<1001> >e[4010];
    void update(int p, int l, int r, int L, int R, bitset<1001> &k)
    {
        if (L<=l&&r<=R)
        {
            e[p].push_back(k);
            return;
        }
        int mid=(l+r)>>1;
        if (L<=mid)update(ls(p), l, mid, L, R, k);
        if (mid< R)update(rs(p), mid+1, r, L, R, k);
    }
    void query(int p, int l, int r, int dep)
    {
        d[dep]=d[dep-1];
        for (auto &it:e[p])
            d[dep].insert(it, 1);
        if (l==r)
        {
            d[dep].filter(a[l]);
            int ty=a[l].count();
            for (int i=1;i<=m;i++)
            {
                int now=d[dep].judge(a[l], i);
                if (ty)putchar(now?'0':'-');
                else putchar(now?'+':'0');
            }
            puts("");
            return;
        }
        int mid=(l+r)>>1;
        query(ls(p), l, mid, dep+1);
        query(rs(p), mid+1, r, dep+1);
    }
}tr;
int main()
{
    // freopen("data.txt","r",stdin);
    // freopen("out1.txt","w",stdout);
    re(n);re(m);
    for (int i=1;i<=n;i++)scanf("%s", s[i]+1);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            a[i][j]=s[i][j]-'0';
    for (int i=1;i<=n;i++)
    {
        if (i> 1)tr.update(1, 1, n, 1, i-1, a[i]);
        if (i< n)tr.update(1, 1, n, i+1, n, a[i]);
    }
    for (int i=0;i< 20;i++)
        tr.d[i].init(m);
    tr.query(1, 1, n, 1);
}