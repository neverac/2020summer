#include <iostream>

using namespace std;

int main()
{
    int k,n,s,p;
    cin >>k >>n >>s >>p;
    int i=1;
    while(i*s<n){
        ++i;
    }
    int ans;
    if((i*k)%p==0)
        ans = i*k/p;
    else
        ans = i*k/p +1;
    cout <<ans <<endl;
    return 0;

}
