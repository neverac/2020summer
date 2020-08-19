#include <bits/stdc++.h>
using namespace std;
#define Min(a,b) a<b?a:b
using namespace std;
const int N=1000;
int v[N];//注意dp爆不爆int 
int t,n,v1;
int main()
{
                                
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&v[i]);
            v[i+n]=v[i];
        }
        
      
        int ans=0;
        for(int i=1;i<=n;i++){
            v1=v[i];
            if(abs(360-2*v1)<abs(360-2*ans))ans=v1;
            if(v1>=180) continue;
            int u=i+n-1;
            for(int j=i+1;j<u;j++){
                v1+=v[j];
                if(abs(360-2*v1)<abs(360-2*ans))ans=v1;
                if(v1>=180) break;
            }
        }
        

        printf("%d\n",abs(360-ans-ans));
    return 0;
}