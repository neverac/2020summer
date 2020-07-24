#include <iostream>
#include <stdio.h>
#include<cmath>
#include<cctype>
#include<cstdio>
#include <algorithm>
#include <string.h>
#include <string>
#include<math.h>
#include<map>
#include<unordered_map>
#define Maxn 100005
#define ll long long
using namespace std;

long long fastPower(long long base, long long power) {
    long long result = 1;
    while (power > 0) {
        if (power & 1) {//此处等价于if(power%2==1)
            result = result * base % 5;
        }
        power >>= 1;//此处等价于power=power/2
        base = (base * base) % 5;
    }
    return result;
}


char c[Maxn];

int main()
{
    while(scanf("%s",c)!=EOF){
     int len=strlen(c);
     int ans=0;
     for(int i=0;i<len;i++){
        int a=c[i]-'0';
        ans=ans*10+a;
        ans%=4;
     }
     if(ans==0)
        printf("4\n");
     else
        printf("0\n");
    }

    return 0;
}
