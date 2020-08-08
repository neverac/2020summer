#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll num[105][105][12];

int main(){
    ll n,q,c;scanf("%lld%lld%lld",&n,&q,&c);
    for(ll i=0;i<n;i++){
        ll x,y,s;scanf("%lld%lld%lld",&x,&y,&s);
        for(int j=0;j<=c;j++){
           num[x][y][j]+=(s+j)%(c+1);
       }
    }
    ll ans=0;
    for(int k=0;k<=c;k++){
        for(int i=1;i<=100;i++){
            for(int j=1;j<=100;j++){
            //for(int k=0;k<=10;k++){
                //cout<<num[i][j][k]<<" "<<num[i][j-1][k]<<" "<<num[i-1][j][k]<<" "<<num[i-1][j-1][k]<<endl;
                num[i][j][k]=num[i][j][k]+num[i][j-1][k]+num[i-1][j][k]-num[i-1][j-1][k];
                //cout<<num[i][j][k]<<endl;
            }
        }
    }
    for(ll i=0;i<q;i++){
        ll t,x1,y1,x2,y2;
        scanf("%lld%lld%lld%lld%lld",&t,&x1,&y1,&x2,&y2);
        t%=(c+1);
        //for(int k=0;k<=10;k++){
        ll ans=num[x2][y2][t]-num[x1-1][y2][t]-num[x2][y1-1][t]+num[x1-1][y1-1][t];
        //}
        printf("%lld\n",ans);
    }
    return 0;
}