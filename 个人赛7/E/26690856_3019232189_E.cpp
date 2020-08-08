#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <ctime>
#include <vector>
#include <cstdio>
#include <map>
#include <queue>
#define ll long long
#define N 100006
using namespace std;

ll gcd(int x,int y){
    return y==0?x:gcd(y,x%y);
}

ll n,m,a[20],sta[100],he,ans,k;

void dfs(int now,int len){
    if(he==len){
        ll temp=sta[1];
        for(int i=2;i<=he;++i)
            temp=temp*sta[i]/gcd(temp,sta[i]);
        if(!k)
            ans+=(n/temp);
        else
            ans-=(n/temp);
        return ;
    }
    for(int i=now;i<=m;++i){
        sta[++he]=a[i];
        dfs(i+1,len);
        --he;
    }
}

int main(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=m;++i)
        scanf("%lld",&a[i]);
    k=0;
    for(int i=1;i<=m;++i){
        dfs(1,i);
        //printf("i=%d ans=%lld\n",i,ans);
        k^=1;
    }
    cout<<ans;
    //while(1);
}
