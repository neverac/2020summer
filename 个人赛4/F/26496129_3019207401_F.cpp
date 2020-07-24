#include <iostream>

using namespace std;

int main()
{
    int k,n,s,p;
    cin>>k>>n>>s>>p;
    int ans1;
    if(n%s==0){
        ans1=n/s;
    }
    else ans1=n/s+1;
    int ans2;
    if((ans1*k)%p==0){
        ans2=(ans1*k)/p;
    }
    else ans2=(ans1*k)/p+1;
    cout<<ans2<<endl;

    return 0;
}
