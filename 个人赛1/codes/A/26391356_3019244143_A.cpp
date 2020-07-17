#include <iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int* a=new int [n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int count=0;
    for(int i=0;i<k;i++)
        count+=a[i];
    cout<<count<<endl;
} 