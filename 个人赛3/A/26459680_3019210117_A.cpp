#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
int in[10005],n,m,ans[10005],cnt,u,v;
vector<int>Line[10005];
void cal(){
    queue<int>q;
    while(!q.empty()){
        q.pop();
    }
    for(int i=1;i<=n;i++){
        if(in[i]==0){
            q.push(i);
        }
    }
    int sum=n;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        sum--;
        for(int i=0;i<Line[x].size();i++){
            in[Line[x][i]]--;
            if(in[Line[x][i]]==0){
                q.push(Line[x][i]);
            }
        }
    }
    if(sum==0){
        printf("1\n");
        for(int i=1;i<=m;i++){
            printf("1 ");
        }
    }else{
        printf("2\n");
        for(int i=1;i<=m;i++){
            printf("%d ",ans[i]);
        }
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        Line[i].clear();
    }
    for(int i=1;i<=m;i++){
        scanf("%d %d",&u,&v);
        if(u<v){
            ans[i]=1;
        }else{
            ans[i]=2;
        }
        Line[u].push_back(v);
        in[v]++;
    }
    cal();
    return 0;    
}