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
#define N 500006
using namespace std;

struct Node{
    int v;
    Node *nx;
    Node(int t1,Node *t2){
        v=t1;
        nx=t2;
    }
}*a[N];

int n,m;
bool vis[N];

void add(int x,int y){
    a[x]=new Node(y,a[x]);
    a[y]=new Node(x,a[y]);
}

int dfs(int x){
    vis[x]=1;
    Node *temp=a[x];
    int tt=0;
    while(temp!=NULL){
        if(!vis[temp->v]){
            ++tt;
            tt+=dfs(temp->v);
        }
        temp=temp->nx;
    }
    return tt;
}

int main(){
    int t1,t2,ans=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        a[i]=NULL;
    }
    for(int i=1;i<=m;++i){
        scanf("%d%d",&t1,&t2);
        add(t1,t2);
    }
    for(int i=1;i<=n;++i)
        if(!vis[i])
            ans+=dfs(i);

    cout<<m-ans;
    //while(1);
}
