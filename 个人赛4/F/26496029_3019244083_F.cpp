#include <bits/stdc++.h>
using namespace std;
int main()
{
    int k,n,s,p;
    int cnt;
    scanf("%d%d%d%d",&k,&n,&s,&p);
    if(n%s==0) cnt = n/s;
    else cnt = n/s+1;
    int ans = cnt * k;
    if(ans%p == 0) cout<<ans/p<<endl;
   else cout<<(ans/p)+1<<endl;
    return 0;
} 