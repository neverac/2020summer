#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+100;
int a[maxn];

int main(){
    int n,k,i,ans=0;
    scanf("%d%d",&n,&k);

    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    for(i=1;i<=k;i++)ans+=a[i];
    printf("%d\n",ans);
    return 0;
}