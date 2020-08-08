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
using namespace std;
int w;
int main()
{
    int n,k;
    int ans=0;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&w);
        if(w%k==0){
            ans+=w/k;
        }
        else{
            ans+=w/k+1;

        }
    }
    if(ans%2==0)
        printf("%d\n",ans/2);
    else
        printf("%d\n",ans/2+1);

    return 0;
}
