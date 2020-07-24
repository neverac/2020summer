#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int k,n,s,p;


int main()
{
    cin>>k>>n>>s>>p;
    int nump=(n+s-1)/s;
    int ans=(k*nump+p-1)/p;
    cout<<ans<<endl;
    

    return 0;
}