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

int n,a[106],ind[106],ans[106][106];
int m;

bool cmp(int x,int y){
    return a[x]>a[y];
}

int main(){
    int l,r,t1,t2;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        ind[i]=i;
        scanf("%d",&a[i]);
    }
    sort(ind+1,ind+1+n,cmp);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j)
            ans[i][j]=ind[j];
        l=i; r=i;
        while(l>1&&a[ind[l-1]]==a[ind[i]])
            --l;
        while(r<n&&a[ind[r+1]]==a[ind[i]])
            ++r;
        sort(ans[i]+l,ans[i]+1+r);
        sort(ans[i]+1,ans[i]+1+i);
    }
    scanf("%d",&m);
    for(int i=1;i<=m;++i){
        scanf("%d%d",&t1,&t2);
        printf("%d\n",a[ans[t1][t2]]);
    }
    //while(1);
}
