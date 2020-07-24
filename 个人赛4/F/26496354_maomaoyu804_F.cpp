#include <bits/stdc++.h>
using namespace std;

int main(){
    int k,n,s,p;
    scanf("%d%d%d%d",&k,&n,&s,&p);
    int x=n/s;
    if(n%s!=0) x++;
    x*=k;
    if(x%p==0) cout<<x/p<<endl;
    else cout<<x/p+1<<endl;
    return 0;
}