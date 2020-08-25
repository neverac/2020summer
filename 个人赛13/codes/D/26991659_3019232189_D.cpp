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
#define N 1000006
using namespace std;

int head[N],cnt,nxt[N*4],v[N*4];

int fa[N];

int n,m,deg[N],sta[N],he;

int fin(int x){
    if(fa[x]==-1)
        return x;
    fa[x]=fin(fa[x]);
    return fa[x];
}

void add(int t1,int t2){
    ++cnt;
    nxt[cnt]=head[t1];
    head[t1]=cnt;
    v[cnt]=t2;
}

int main(){
    int t1,t2,temp;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        fa[i]=-1;
    for(int i=1;i<=m;++i){
        scanf("%d%d",&t1,&t2);
        if(t1<t2)
            swap(t1,t2);
        add(t1,t2);
    }
    for(int i=1;i<=n;++i){
        temp=head[i];
        he=0;
        while(temp){
            sta[++he]=v[temp];
            temp=nxt[temp];
        }
        sort(sta+1,sta+1+he);
        for(int j=1;j<=he;++j){
            t1=fin(i); t2=fin(sta[j]);
            if(t1!=t2){
                fa[t1]=t2;
                ++deg[i]; ++deg[sta[j]];
                //printf("i=%d v[temp]=%d\n",i,sta[j]);
            }
        }
    }
    temp=0;
    for(int i=1;i<=n;++i)
        temp=max(temp,deg[i]);
    printf("%d\n",temp);
    //while(1);
}
/*
5 8
2 1
1 2
2 1
2 4
1 3
3 4
4 5
1 5
*/