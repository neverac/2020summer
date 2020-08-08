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

ll work(ll a,ll b){
    if(b==0)
        return 0;
    return a/b+work(b,a%b);
}

ll a,b;

int main(){
    scanf("%I64d%I64d",&a,&b);
    printf("%I64d",work(a,b));

    //while(1);
}
