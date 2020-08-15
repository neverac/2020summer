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

ll n;
ll a[50],b[50];
ll na,nb;
char s[50];

ll work(ll x[]){
    ll len,now,nt=0;
    scanf("%s",s);
    len=strlen(s);
    for(int i=0;i<len;++i){
        ++nt;
        //printf("nt=%d\n",nt);
        x[nt]=0;
        if(s[i]>='0'&&s[i]<='9'){
            now=i;
            while(now<len&&s[now]>='0'&&s[now]<='9'){
                x[nt]=x[nt]*10+s[now]-'0';
                ++now;
            }
            i=now-1;
            x[nt]-=1e11;
        }
        else{
            x[nt]=s[i];
        }
    }
    return nt;
}

int cmpp(){
    ll nt=min(na,nb);
    /*printf("cmpp\n");
    printf("na=%d nb=%d\n",na,nb);
    for(int i=1;i<=na;++i)
        printf("%d ",a[i]);
    cout<<'\n';
    for(int i=1;i<=nb;++i)
        printf("%d ",b[i]);
    cout<<'\n';*/
    for(int i=1;i<=nt;++i){
        if(b[i]>a[i])
            return 1;
        else if(b[i]<a[i])
            return 0;
    }
    return nb>=na;
}

int main(){
    scanf("%lld",&n);
    na=work(a);
    for(int i=1;i<=n;++i){
        nb=work(b);
        if(cmpp())
            printf("+\n");
        else
            printf("-\n");
    }
    //while(1);
}
/*
11
X52Y
X
X5
X52
X52Y
X52Y6
32
ABC
XYZ
x51y
X8Y
X222
*/