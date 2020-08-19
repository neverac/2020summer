#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long LL;
LL a[N], n;
void init(){
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    return ;
}
int tol; //节点个数 
LL val[32*N]; //点的值 
int ch[32*N][2]; //边的值 
 
void initi()
{ //初始化 
    tol=1;
    ch[0][0]=ch[0][1]=0;
}
 
void insert(LL x)
{ //往 01字典树中插入 x 
    int u=0;
    for(int i=32;i>=0;i--)
    {
        int v=(x>>i)&1;
        if(!ch[u][v])
        { //如果节点未被访问过 
            ch[tol][0]=ch[tol][1]=0; //将当前节点的边值初始化 
            val[tol]=0; //节点值为0，表示到此不是一个数 
            ch[u][v]=tol++; //边指向的节点编号 
        }
        u=ch[u][v]; //下一节点 
    }
    val[u]=x; //节点值为 x，即到此是一个数 
}
LL query(LL x)
{
    int u=0;
    for(int i=32;i>=0;i--)
    {
        int v=(x>>i)&1;
        //利用贪心策略，优先寻找和当前位不同的数 
        if(ch[u][v^1]) u=ch[u][v^1];
        else u=ch[u][v];
    }
    return val[u]; //返回结果 
}
LL sum;
void work(int cur, LL x, int id){
    int l = ch[cur][0], r = ch[cur][1];
    if(r == 0 && l == 0){
        LL o = query(x);
        // cout<<x<<' '<<o<<endl;
        if((o ^ x) < sum) sum = (o ^ x); return ;
    }
    if(l == 0){
        x += (1LL << id); work(ch[cur][1], x, id - 1);
    }
    else if(r == 0){
        work(ch[cur][0], x, id - 1);
    }
    else {
        work(ch[cur][0], x + (1LL << id), id - 1);
        work(ch[cur][1], x, id - 1);
    }
    return ;
}

void solve(){
    for(int i = 1; i <= n; i++) insert(a[i]);
    sum = LONG_LONG_MAX;
    work(0, 0, 32);
    printf("%lld\n", sum);
    return ;
}
int main(){
    initi();
    init();
    solve();
    return 0;
}