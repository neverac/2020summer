#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn = 1e5+100;

int n,a[maxn],sum;

int f[maxn];

#define Memset(x, a) memset(x, a, sizeof(x))
typedef long long ll;
int ch[32*maxn][2];         //节点的边信息
ll val[32*maxn];            //节点存储的值
int sz;                     //树中当前节点个数
 
void _insert(ll a){//在字典树中插入 a
                  //和一般字典树的操作相同 将X的二进制插入到字典树中
    int u=0;
    for(int i=29;i>=0;i--){
        int c=((a>>i)&1);
        if(!ch[u][c]){
            ch[u][c]=++sz;
        }
        u=ch[u][c];
    }
}

int solve(int t,int now)
{
    if(t==-1)
        return 0;
    if(ch[now][0]==0)
        return solve(t-1,ch[now][1]);
    if(ch[now][1]==0)
        return solve(t-1,ch[now][0]);
    return (1<<t)+min(solve(t-1,ch[now][1]),solve(t-1,ch[now][0]));
}


int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) _insert(a[i]);
    cout<<solve(29,0)<<endl;
    return 0;
}
/*
3
1 2 3
 */