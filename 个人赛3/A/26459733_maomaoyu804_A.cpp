#include <bits/stdc++.h>
using namespace std;

vector<int> ve[5005];
queue<int> q;
int in[5005];
int ans[5005];
int uu[5005],vv[5005];

int main(){
    int n,m;scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d",&uu[i],&vv[i]);
        ve[uu[i]].push_back(vv[i]);
        in[vv[i]]++;
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(in[i]==0) q.push(i);
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        cnt++;
        for(int i=0;i<ve[u].size();i++){
            int v=ve[u][i];
            in[v]--;
            if(in[v]==0) q.push(v);
        }
    }
    if(cnt==n){
        printf("1\n");
        for(int i=0;i<m;i++) printf("1 ");
    }
    else{
        printf("2\n");
        for(int i=0;i<m;i++){
            if(uu[i]<vv[i]) printf("1 ");
            else printf("2 ");
        }
    }
    return 0;
}