#include <iostream>
using namespace std;


int main()
{

    int n,k;
    cin>>n>>k;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(x%k==0)
        sum+=x/k;
        else 
        sum+=x/k+1;
     }
     if(sum%2==0)
     cout<<sum/2;
     else 
     cout<<sum/2+1;
    return 0;
}