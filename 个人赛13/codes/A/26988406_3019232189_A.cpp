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

int T;
ll n,m,x,y;

int main(){
    ll temp;
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld%lld%lld",&n,&m,&x,&y);
        if(x<=y)
            printf("%lld\n",m);
        else{
            temp=(n-x)/(x-y);
            if(m<=temp+1)
                printf("%lld\n",m);
            else
                printf("%lld\n",(n+(m-1)*y)/x);
        }
    }
    //while(1);
}
