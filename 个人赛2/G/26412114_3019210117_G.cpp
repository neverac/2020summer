#include <iostream>
using namespace std;
const int Max=100010;
int ans[Max],tmp[Max],vis[Max];
int main(){
    //freopen("in.txt", "r", stdin);
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k-1;i++){
        tmp[i]=n-i;
    }
    tmp[k]=1;
    for(int i=1;i<=n;i++){
        vis[i]=0;
    }
    vis[1]=1;
    ans[0]=1;
    int t=1;
    for(int i=1;i<n;i++){
        int a=ans[i-1]-tmp[t],b=ans[i-1]+tmp[t];
        if(a>0&&!vis[a]){
            ans[i]=a;
            vis[a]=1;
        }else{
            ans[i]=b;
            vis[b]=1;
        }
        if(t<k){
            t++;
        }
    }
    for(int i=0;i<n;i++){
        if(i!=0){
            printf(" ");
        }
        printf("%d",ans[i]);
    }
    printf("\n");
    return 0;
}