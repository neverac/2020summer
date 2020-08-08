#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int alls[N];
int n,k;

int main(){
    scanf("%d%d",&n,&k);
    int ans=0;
    for(int i=0;i<n;++i){
        scanf("%d",&alls[i]);
        if(alls[i]%k==0)ans+=alls[i]/k;
        else ans+=alls[i]/k+1;
    }
    if(ans%2==0)ans=ans/2;
    else ans=ans/2+1;
    printf("%d",ans);
}
