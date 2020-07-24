#include <iostream>

using namespace std;

int main()
{
    //kn/(sp)
    int k,n,s,p;
    cin>>k>>n>>s>>p;
    int shuliang = (n%s == 0?(n/s):(n/s+1));
    int sum = shuliang*k;
    int res = (sum%p == 0?(sum/p):(sum/p+1));
    cout<<res<<endl;
    return 0;
}
