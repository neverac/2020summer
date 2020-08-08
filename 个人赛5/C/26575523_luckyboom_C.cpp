#include<iostream>
#include<cmath>
#include<map>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int const maxn=370;
long long ans[maxn],a[maxn],now,getans,k,st;
int t;
void work(){
    now=100,getans=100,k=0,st;
    int i=1;
    while(i<=t){
        while(i+1<=t&&a[i+1]<=a[i]){
            i++;
        }
        if(now>=a[i]){
            k=now/a[i];
            if(k>100000)k=100000;
            st=k*a[i];
            now=now-st;
        }
        while(i+1<=t&&a[i+1]>=a[i]){
            i++;
        }
        now=now+k*a[i];
        st=0;
        k=0;
        if(now>getans)getans=now;
        if(i==t)break;
    }

    printf("%lld\n",getans);
}
int main(){
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        scanf("%lld",&a[i]);
    }
    work();
    return 0;
}
/*
10 
100 150 300 400 500 200 150 300 100 50
100 20 10 30 40 50 60 70 80 90
*/