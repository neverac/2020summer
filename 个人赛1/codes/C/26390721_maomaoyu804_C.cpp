#include <bits/stdc++.h>
using namespace std;

int vis[100005];
int ans[100005];

int main(){
    int t;scanf("%d",&t);
    while(t--){
        memset(vis,0,sizeof(vis));
        memset(ans,0,sizeof(ans));
        int n;scanf("%d",&n);
        int temp=0;
        int flag=0;
        for(int i=1;i<=n;i++){
            int num;scanf("%d",&num);
            if(num<i) flag=1;
            if(num>temp) ans[i]=num;
            vis[num]=1;
            temp=num;
        }
        int p=1;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                while(ans[p])p++;
                ans[p]=i;
            }
        }
        if(flag) printf("-1\n");
        else {
            for(int i=1;i<=n;i++){
                printf("%d ",ans[i]);
            }
            printf("\n");
        }
    }
    return 0;
}