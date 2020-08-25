#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
using namespace std;
typedef long long LL;
const int SIZEN = 100010;
int N,M;
int du[SIZEN] = {0};
int root[SIZEN] = {0};
int find(int x){
    if(root[x] == x)return root[x];
    return root[x] = find(root[x]);
}
struct Edge{
    int u,v;
}edge[SIZEN << 2];
int ans = 0;
bool Cmp(const Edge &A,const Edge &B){
    if(A.v != B.v)return A.v < B.v;
    return A.u < B.u;
}
int main(){
    scanf("%d%d",&N,&M);
    for(int i = 1;i <= M;i++){
        int x,y;scanf("%d%d",&x,&y);
        if(x > y)swap(x,y);
        edge[i].u = x;
        edge[i].v = y;
    }
    sort(edge+1,edge+1+M,Cmp);
    for(int i = 1;i <= N;i++){
        root[i] = i;
    }
    for(int i = 1;i <= M;i++){
        int x = edge[i].u;
        int y = edge[i].v;
        int fa = find(x);
        int fb = find(y);
        if(fa == fb)continue;
        root[fa] = fb;
        du[x]++;
        du[y]++;
        ans = max(ans,max(du[x],du[y]));
    }
    printf("%d\n",ans);
    return 0;
}