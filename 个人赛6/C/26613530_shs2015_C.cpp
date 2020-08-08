#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef long long LL;
const int SIZEN = 100010;
int N,K;
int root[SIZEN] = {0},sz[SIZEN] = {0};
int find(int x){
    return root[x] = (root[x] == x?x:find(root[x]));
}
int main(){
    scanf("%d%d",&N,&K);
    int ans = 0;
    for(int i = 1;i <= N;i++)root[i] = i,sz[i] = 1;
    for(int i = 1;i <= K;i++){
        int x,y;scanf("%d%d",&x,&y);
        int fa = find(x),fb = find(y);
        if(fa == fb)continue;
        root[fa] = fb;
        sz[fb] += sz[fa];
    }
    for(int i = 1;i <= N;i++){
        if(find(i) != i)continue;
        ans += sz[find(i)] - 1;
    }
    printf("%d",K-ans);
    return 0;
}