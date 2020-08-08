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

int n;
ll pre3[50],pre5[50],pre7[50];

int main(){

    pre3[0]=pre5[0]=pre7[0]=1;
    for(int i=1;i<=40;++i){
        pre3[i]=pre3[i-1]*3;
        pre5[i]=pre5[i-1]*5;
        pre7[i]=pre7[i-1]*7;
    }
    for(int i=1;i<=40;++i){
        pre3[i]+=pre3[i-1];
        pre5[i]+=pre5[i-1];
        pre7[i]+=pre7[i-1];
    }
        

    ll temp,num3,num5,num7;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%lld",&temp);
        while(temp%2==0)
            temp/=2;
        num3=0; num5=0; num7=0;
        while(temp%3==0){
            temp/=3;
            ++num3;
        }
        while(temp%5==0){
            temp/=5;
            ++num5;
        }
        while(temp%7==0){
            temp/=7;
            ++num7;
        }
        printf("%lld\n",pre3[num3]*pre5[num5]*pre7[num7]);
    }
    //while(1);
}
/*
2
2
90
*/