#include <bits/stdc++.h>
using namespace std;
int n,a[370],ans=0x3f3f3f3f;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);
    for(int i=1;i<=n;++i){
        int sum=0;
        for(int j=i;j<=n;++j){
            sum+=a[j];
            ans=min(ans,abs(360-2*sum));
        }
    }
    printf("%d",ans);
}