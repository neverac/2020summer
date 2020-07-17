#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stack>
using namespace std;
#define sd(n) scanf("%d",&n)
#define sdd(n,m) scanf("%d%d",&n,&m)
#define sddd(n,m,k) scanf("%d%d%d",&n,&m,&k)
#define pd(n) printf("%d\n", n)
#define pc(n) printf("%c", n)
#define pdd(n,m) printf("%d %d", n, m)
#define pld(n) printf("%lld\n", n)
#define pldd(n,m) printf("%lld %lld\n", n, m)
#define sld(n) scanf("%lld",&n)
#define sldd(n,m) scanf("%lld%lld",&n,&m)
#define slddd(n,m,k) scanf("%lld%lld%lld",&n,&m,&k)
#define sf(n) scanf("%lf",&n)
#define sc(n) scanf("%c",&n)
#define sff(n,m) scanf("%lf%lf",&n,&m)
#define sfff(n,m,k) scanf("%lf%lf%lf",&n,&m,&k)
#define ss(str) scanf("%s",str)
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define mem(a,n) memset(a, n, sizeof(a))
#define debug(x) cout << #x << ": " << x << endl
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mod(x) ((x)%MOD)
#define gcd(a,b) __gcd(a,b)
#define lowbit(x) (x&-x)
typedef pair<int,int> PII;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int MOD = 1e9 + 7;
const double eps = 1e-9;
const int maxn = 3e5 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
const int inf = 0x3f3f3f3f;
inline int read()
{
    int ret = 0, sgn = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9')
    {
        if(ch == '-')
            sgn = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ret = ret*10 + ch - '0';
        ch = getchar();
    }
    return ret*sgn;
}
inline void Out(int a)    //Êä³öÍâ¹Ò
{
    if(a>9)
        Out(a/10);
    putchar(a%10+'0');
}

int qpow(int m, int k, int mod)
{
    int res = 1, t = m;
    while (k)
    {
        if (k&1)
            res = res * t % mod;
        t = t * t % mod;
        k >>= 1;
    }
    return res;
}

ll gcd(ll a,ll b)
{
    return b==0?a : gcd(b,a%b);
}

ll lcm(ll a,ll b)
{
    return a*b/gcd(a,b);
}
int n,m,t,cnt;
bool flag;
int a[100005];
stack<int> q;
int main()
{
    sd(t);
    while(t--)
    {
        sd(n);
        flag=0;
        rep(i,1,n)
        {
            cin>>a[i];
            if(a[i]<i)
                flag=1;
        }
        if(flag)
            printf("-1\n");
        else
        {
            cnt=0;
            rep(i,1,n)
            {
                while(cnt<a[i])
                {
                    q.push(++cnt);

                }
                printf("%d ",q.top());
                q.pop();
            }
            cout<<endl;
        }
    }
}


