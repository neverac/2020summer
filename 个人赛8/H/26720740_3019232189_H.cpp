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
#define N 1000006
using namespace std;

int n,a[N],f[N][2];

int main(){
    int ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        f[i][0]=-1e9;
        f[i][1]=-1e9;
        scanf("%d",&a[i]);
    }
    f[1][0]=1;
    if(a[2]>a[1])
        f[2][0]=f[1][0]+1;
    else
        f[2][0]=1;
    if(n>=1)
        ans=max(f[1][0],ans);
    if(n>=2)
        ans=max(f[2][0],ans);
    for(int i=3;i<=n;++i){
        if(a[i]>a[i-1]){
            f[i][0]=max(f[i][0],f[i-1][0]+1);
            f[i][1]=max(f[i][1],f[i-1][1]+1);
        }
        else
            f[i][0]=1;
        if(a[i]>a[i-2])
            f[i][1]=max(f[i][1],f[i-2][0]+1);
        ans=max(ans,f[i][0]);
        ans=max(ans,f[i][1]);
    }
    cout<<ans;
   // while(1);
}
