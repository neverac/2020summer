#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct city{
    int dep,siz;
}C[200005];
vector<int>Line[200005];
void dfs(int rt,int de){
    C[rt].dep=de;
    for(int i=0;i<Line[rt].size();i++){
        if(C[Line[rt][i]].dep==-1){
            dfs(Line[rt][i],de+1);
            C[rt].siz+=C[Line[rt][i]].siz+1;
        }
    }
}
bool comp(city &a,city &b){
    return a.dep-a.siz>b.dep-b.siz;
}
int main(){
    //freopen("in.txt","r",stdin);
    int n,k,u,v;
    long long int totans=0;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        C[i].siz=0;
        C[i].dep=-1;
    }
    for(int i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        Line[u].push_back(v);
        Line[v].push_back(u);
    }
    dfs(1,0);
    sort(C+1,C+n+1,comp);
    for(int i=1;i<=k;i++){
        totans+=C[i].dep-C[i].siz;
    }
    printf("%lld",totans);
    return 0;
}