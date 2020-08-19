#include <iostream>
#include <set>
#include <cmath>
using namespace std;
long long int zuob[2005][3],temdis,ijdis;
bool vis[2005];
long long int dis(int i,int j){
    long long int sum=0;
    for(int k=0;k<3;k++){
        sum+=abs(zuob[i][k]-zuob[j][k]);
    }
    return sum;
}
int main(){
   // freopen("in.txt","r",stdin);
    int n,ansi,ansj;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        vis[i]=1;
        for(int j=0;j<3;j++){
            scanf("%lld",&zuob[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        temdis=100000000009;
        ansi=ansj=0;
        for(int j=1;j<=n;j++){
            if(i!=j){
                if(vis[i]&&vis[j]){
                    ijdis=dis(i,j);
                    if(ijdis<temdis){
                        ansi=i;
                        ansj=j;
                        temdis=ijdis;
                    }
                }
            }
        }
        if(ansi*ansj!=0){
            vis[ansi]=vis[ansj]=0;
            printf("%d %d\n",ansi,ansj);
        }
    }
    return 0;
}