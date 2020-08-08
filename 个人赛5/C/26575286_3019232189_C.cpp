#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#define ll long long
#define N 100006
using namespace std;

int n;
ll p[370];

int main(){
    int sta;
    ll now,mon,tt;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%lld",&p[i]);
    
    now=0; mon=100;
    for(int i=1;i<n;++i){
        if(p[i]==p[i+1])
            continue;
        else if(p[i]<p[i+1]){
            tt=min(100000-now,mon/p[i]);
            mon-=tt*p[i];
            now+=tt;
        }
        else{
            mon+=now*p[i];
            now=0;
        }
    }
    mon+=now*p[n];;
    cout<<mon;

    //while(1);
}
