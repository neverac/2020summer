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
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define ll long long
#define Maxn 10005
using namespace std;

long long a[Maxn];

ll over(ll x){
    ll sum2=1;
        while(x%2==0)
            x/=2;
        for(int i=3;i<=7;i+=2){
        ll ans=1;
        ll sum=1;
        while(x%i==0){
            x/=i;
            ans*=i;
            sum+=ans;
        }
        sum2*=sum;
        }
        return sum2;
}

int main(){
    int n;
    ios::sync_with_stdio(false);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(int j=1;j<=n;j++){
        printf("%lld\n",over(a[j]));
    }
    return 0;
}
