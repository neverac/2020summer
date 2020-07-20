#include <iostream>
#include <cstdio>

using namespace std;

const int N=1000010;

int x[N];

int main()
{
    int n,k;
    cin>>n>>k;
    x[0]=1;
    int idx=k;
    for(int i=1;i<=k;i++)
    {
        if(i%2)
        {
            x[i]=x[i-1]+idx;
            idx--;
        }
        else
        {
            x[i]=x[i-1]-idx;
            idx--;
        }
    }
    if(n>=k+2)
        x[k+1]=k+2;
    if(n>=k+3)
        for(int i=k+2;i<n;i++)
        {
            x[i]=x[i-1]+1;
        }
    for(int i=0;i<n;i++)
        cout<<x[i]<<' ';
}