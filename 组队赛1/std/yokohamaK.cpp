#include<bits/stdc++.h>
#include<time.h>
#define LL long long
using namespace std;
const int N=5005;
int n;
vector<int> f;
int ans[N], vis[N], tricks, p_rk[N];
struct node
{
    int num, id, rk;
    node(int _num=0, int _id=0, int _rk=0)
    {
        num=_num;
        id=_id;
        rk=_rk;
    }
}p[N];

bool com1(node a, node b)
{
    return a.num<b.num;
}
bool com2(node a, node b)
{
    return a.id<b.id;
}

bool check(int x, int s)
{
    auto ww=upper_bound(f.begin(), f.end(), p[s].num);
    int win=0;
    if (ww<f.end()&&x+1<f.size())win=1;
    else win=0;
    int tem=tricks;
    if (p[s].num<f[x])tem--;
    int q=0;
    for (int i=1;i<=n;i++)
    {
        if (vis[i]==1)continue;
        if (p[s].rk==i)continue;
        while (q<f.size()&&(f[q]<=p_rk[i]||q==x))q++;
        if (q<f.size())
        {
            tem--;
            q++;
        }
        else break;
    }
    bool ret=0;
    if (tem>0 && p[s].num<f[x])ret=0;
    else if (tem>0 && p[s].num>=f[x])ret=win;
    else if (tem<=0 && p[s].num>=f[x])ret=1;
    else ret=1;
    return ret;
}
int getint()
{
    int ret=0;
    char ch=getchar();
    while (ch<'0'||ch>'9')ch=getchar();
    while (ch<='9'&&ch>='0')ret=ret*10+ch-'0', ch=getchar();
    return ret;
}

int main()
{
    n=getint();
    for (int i=1;i<=n;i++)p[i].num=getint(), p[i].id=i;
    for (int i=1;i<=n;i++)
    {
        int a=getint();
        f.push_back(a);
    }
    sort(f.begin(), f.end());
    sort(p+1, p+1+n, com1);
    for (int i=1;i<=n;i++)p_rk[i]=p[i].num, p[i].rk=i;
    tricks=0;
    int q=0;
    for (int i=1;i<=n;i++)
    {
        while (q<n&&f[q]<=p[i].num)q++;
        if (q<n)
        {
            tricks++;
            q++;
        }
        else break;
    }
    sort(p+1, p+1+n, com2);
    for (int i=1;i<=n;i++)
    {
        int l=0, r=f.size();
        while (l<r)
        {
            int mid=(l+r)>>1;
            if (check(mid, i))l=mid+1;
            else r=mid;
        }
        l--;
        ans[i]=f[l];
        vis[p[i].rk]=1;
        if (p[i].num<f[l])tricks--;
        for (auto j=f.begin();j<f.end();j++)
        {
            if (*j==f[l])
            {
                f.erase(j);
                break;
            }
        }

    }
    for (int i=1;i<=n;i++)printf("%d ", ans[i]);
    printf("\n");
    return 0;
}
/*
3
10 10 20
15 25 25
*/
