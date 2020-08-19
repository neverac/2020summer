#include <bits/stdc++.h>
using namespace std;
#define Min(a,b) a<b?a:b
using namespace std;
const int maxn=107;
int p[maxn],a[maxn];//注意dp爆不爆int 
int t,n,m;
struct node{
    int v,ind;
}no[maxn];
bool cmp(struct node x,struct node y){
    if(x.v!=y.v){
        return x.v>y.v;
    }
    return x.ind<y.ind;
}
int main()
{
                                
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&no[i].v);

            no[i].ind=i;
            a[i]=no[i].v;
        }
        sort(no+1,no+1+n,cmp);
        scanf("%d",&m);
        int k,pos;
        
        for(int i=1;i<=m;i++){
            scanf("%d%d",&k,&pos);
            for(int i=1;i<=k;i++){
                p[i]=no[i].ind;
            }
            sort(p+1,p+1+k);
            printf("%d\n",a[p[pos]]);
        }
        // for(int i=1;i<=n;i++)dp[i][1]=v[1],pos[i][1]=1,ans[i]=1;
        // for(int i=1;i<=n;i++){
        //     for(int j=i;j<=n;j++){
        //         if(dp[i][j-1]<dp[i-1][j-1]+v[j]){
        //             dp[i][j]=dp[i-1][j-1]+v[j];
        //             pos[i][j]=pos[i-1]
        //         }
        //     }
        // }
        // int ans=0;
        // for(int i=1;i<=n;i++){
        //     v1=v[i];
        //     if(abs(360-2*v1)<abs(360-2*ans))ans=v1;
        //     if(v1>=180) continue;
        //     int u=i+n-1;
        //     for(int j=i+1;j<u;j++){
        //         v1+=v[j];
        //         if(abs(360-2*v1)<abs(360-2*ans))ans=v1;
        //         if(v1>=180) break;
        //     }
        // }
        
    return 0;
}