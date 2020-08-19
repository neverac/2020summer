#include<cstdio>
#include<iostream>
#include<set>
const int N=2000050;
using namespace std;
int pri[N],a[N],b[N],vis[N];
int main(){
    int n,m;
    cin >> n;
    set<pair<int,int>> se[4];
    for(int i=0;i<n;i++){
        scanf("%d",&pri[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    for(int i=0;i<n;i++){
        se[a[i]].insert({pri[i],i});
        se[b[i]].insert({pri[i],i});
    }
    int ans,w;
    cin >> m;
    for(int i=0;i<m;i++){
        ans=-1;
        scanf("%d",&w);
        while(!se[w].empty()){
            int temp=(*(se[w].begin())).second;
            se[w].erase(se[w].begin());
            if(vis[temp]){
                continue;
            }
            vis[temp]=1;
            ans=pri[temp];
            break;
        }
        cout << ans << " ";
    }
    
}