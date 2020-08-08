#include <iostream>

using namespace std;

int n;
int k;
const int N=1e5+10;
int q[N];
int sum;
int main()
{
    cin>>n;
    cin>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>q[i];
        sum+=(q[i]+k-1)/k;
        
    }
    cout <<(sum+1)/2<<endl;



    return 0;
}