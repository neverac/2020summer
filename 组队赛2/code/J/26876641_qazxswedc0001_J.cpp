#include <iostream>
#include <bitset>
#include <cmath>
using namespace std;
bitset<505>Inp[20];
int ans,m;
void sol(bitset<505> tem,int w,int cnt){
    if(w==0){
        if(tem.count()==m){
            if(ans==-1){
                ans=cnt;
            }else{
                ans=min(ans,cnt);
            }
        }
        return;
    }
    sol(tem|Inp[w],w-1,cnt+1);
    sol(tem,w-1,cnt);
}
int main(){
   // freopen("in.txt","r",stdin);
    int T,n;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&m,&n);
        for(int i=1;i<=n;i++){
            cin>>Inp[i];
        }
        ans=-1;
        sol(0,n,0);
        printf("%d\n",ans);
    }
    return 0;
}