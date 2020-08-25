#include <iostream>
#include <cmath>
using namespace std;
long long int Mod=998244353;
unsigned long long int a[505][505],times[505][2],ans=0,t;
int main(){
    for(int i=0;i<505;i++){
        times[i][0]=times[i][1]=0;
    }
    int n,m,k,x;
    char opt;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%llu",&a[i][j]);
        }
    }
    getchar();
    while(k--){
        scanf("%c %d %llu",&opt,&x,&t);
        getchar();
        times[x][opt=='c']=max(t,times[x][opt=='c']);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ans=(ans+a[i][j]%Mod*(max(times[i][0],times[j][1])%Mod)%Mod)%Mod;
        }
    }
    printf("%llu",ans);
    return 0;
}