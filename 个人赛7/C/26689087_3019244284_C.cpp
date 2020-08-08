#include <iostream>
using namespace std;
int n;
int a[1010];
int b[1010];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
	 cin>>a[i];
    for(int i=1;i<=n;i++)
	 cin>>b[i];
    int i=1,j=1;
    while(i<=n&&j<=n)
	{
        if(a[i]>b[j]) j++;
        else i++;
    }
    cout<<max(n-i,n-j)+1<<endl;
    return 0;
}