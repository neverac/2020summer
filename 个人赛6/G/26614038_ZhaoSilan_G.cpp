#include<stdio.h>
#include<iostream>
using namespace std;
long long int n,m,ans;
int main(){
    cin>>n>>m;
    if(n>m)
        ans+=n/m,n%=m;
    
    while(n)
    {
        if(n==1)
        {
            ans+=m;
            break;
        }
        ans+=m/n;
        m%=n;
        swap(n,m);
    }
    cout<<ans<<endl;
    return 0;
}
