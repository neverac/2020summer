#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
#define rep(i,l,k) for(int i=l;i<=k;i++)
int n,m,c[N];
bool vis[N];
struct Neko{
    int a,b,p,id;
    bool operator < (const Neko &zech)const {
        return p>zech.p||(p==zech.p&&id>zech.id);
    }
}E[N];
priority_queue<Neko>q[4];
int ip(){
    int x=0,w=0;char ch=0;
    while(!isdigit(ch)) w|=ch=='-',ch=getchar();
    while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return w?-x:x;
}
int main(){
    n=ip();
    rep(i,1,n) E[i].p=ip(),E[i].id=i;
    rep(i,1,n) E[i].a=ip();
    rep(i,1,n) E[i].b=ip();
    rep(i,1,n) q[E[i].a].push(E[i]),q[E[i].b].push(E[i]);
    m=ip();rep(i,1,m){
        c[i]=ip();
        if(q[c[i]].empty()) {puts("-1");continue;}
        int u=q[c[i]].top().id;
        while(vis[u]&&!q[c[i]].empty()){
            q[c[i]].pop();u=q[c[i]].top().id;
        }
        if(q[c[i]].empty()) {puts("-1");continue;}
        printf("%d ",q[c[i]].top().p);vis[q[c[i]].top().id]=1;
    }
    return 0;
}