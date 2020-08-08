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
#define Maxn 105
using namespace std;

int a[Maxn];
int b[Maxn];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    int l=1,r=1;
    int numa=n,numb=n;
    while(l<=n&&r<=n){
    if(a[l]<b[r]){
        numa--;
        l++;
    }
    if(a[l]>b[r]){
        numb--;
        r++;
    }
    }
    int sum=numa+numb;
    printf("%d\n",sum);
    return 0;
}
