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

using namespace std;

const int Maxn=2e5+5;
int num[Maxn],a[Maxn],l[Maxn],r[Maxn];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        l[i]=1;
        r[i]=1;
    }
    int Max=1;
    for(int i=n-1;i>=1;i--){
        if(a[i]<a[i+1])
            r[i]=r[i+1]+1;
        Max=max(Max,r[i]);
    }
    for(int i=2;i<=n;i++){
        if(a[i]>a[i-1])
            l[i]=l[i-1]+1;
        Max=max(Max,l[i]);
    }
    for(int i=1;i<=n-2;i++){
        if(a[i]<a[i+2]){
            Max=max(Max,l[i]+r[i+2]);
        }
    }
    printf("%d\n",Max);
    return 0;

}
