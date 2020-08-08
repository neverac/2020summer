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

int T,n;
ll a[N],b[N];

int main(){
    ll mn,temp,tot;
    int ind;
    scanf("%d",&T);
    while(T--){
        tot=0;
        mn=0;
        ind=0;
        temp=-1e17;
        scanf("%d",&n);
        for(int i=1;i<=n;++i){
            b[i]=0;
            scanf("%lld",&a[i]);
            tot+=a[i];
        }
        for(int i=1;i<n;++i){
            b[i]=b[i-1]+a[i];
            temp=max(temp,b[i]-mn);
            if(b[i]<mn){
                mn=b[i];
                ind=i;
            }
        }
        for(int i=1;i<=n;++i)
            b[i]=0;
        mn=0;
        ind=0;
        for(int i=2;i<=n;++i){
            b[i]=b[i-1]+a[i];
            temp=max(temp,b[i]-mn);
            if(b[i]<mn){
                mn=b[i];
                ind=i;
            }
        }
        //printf("%lld\n",temp);
        if(tot>temp)
            printf("YES\n");
        else
            printf("NO\n");
    }
    //while(1);
}
/*
1
5
3 -1516516 5 6 6
*/