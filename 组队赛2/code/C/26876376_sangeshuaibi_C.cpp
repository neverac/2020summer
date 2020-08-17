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

int n,a[106];

int main(){
    int fla=1;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;++i)
        for(int j=i+1;j<=n;++j)
            for(int k=j+1;k<=n;++k){
                if((a[i]-a[j])%a[k]!=0)
                    fla=0;
                if((a[i]-a[k])%a[j]!=0)
                    fla=0;
                if((a[j]-a[k])%a[i]!=0)
                    fla=0;
            }
    if(fla)
        printf("yes\n");
    else
        printf("no\n");
    //while(1);
}
