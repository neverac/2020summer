#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <ctime>
#include <vector>
#include <cstdio>
#include <map>
#include <queue>
#define ll long long
#define N 100006
using namespace std;

int cnt,ch[N*31][2],ans;

int n,a[N],mi[50];

void add(int x){
    int temp,now=0;
    for(int i=29;i>=0;--i){
        temp=(((1<<i)&x)>>i);
        if(ch[now][temp]==-1)
            ch[now][temp]=++cnt;
        now=ch[now][temp];
    }
}

void dfs(int now,int ind,int res){
    if(ind<0){
        ans=min(ans,res);
        return ;
    }
    if(ch[now][0]!=-1&&ch[now][1]!=-1){
        dfs(ch[now][0],ind-1,res+mi[ind]);
        dfs(ch[now][1],ind-1,res+mi[ind]);
    }
    else if(ch[now][0]!=-1)
        dfs(ch[now][0],ind-1,res);
    else
        dfs(ch[now][1],ind-1,res);
}

int main(){
    mi[0]=1;
    for(int i=1;i<=29;++i)
        mi[i]=mi[i-1]*2;
    cnt=0;
    ans=0x7fffffff;
    memset(ch,-1,sizeof(ch));
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        add(a[i]);
    }
    dfs(0,29,0);
    cout<<ans;
    //while(1);
}
