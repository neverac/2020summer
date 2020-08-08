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

int n,a[N];

bool cmp(int x,int y){
    return a[x]>a[y];
}

int main(){
    int temp,l,r;
    scanf("%d",&n);
    for(int i=n;i>=1;--i)
        scanf("%d",&a[i]);
    for(int i=n+1;i<=n*2;++i)
        scanf("%d",&a[i]);
    l=n; r=n+1;
    while(l>=1&&r<=2*n){
        if(a[l]>a[r])
            ++r;
        else
            --l;
    }
    if(l==0)
        printf("%d\n",2*n-r+1);
    else
        printf("%d\n",l);
    //while(1);
}
