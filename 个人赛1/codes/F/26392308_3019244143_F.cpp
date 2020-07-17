#include <iostream>
#include<memory.h>
using namespace std;
int a[1000001];
int main()
{
    memset(a,0,sizeof(a));
    int n;
    cin>>n;
    long long int count=0;
    for(int i=0;i<n;i++)
    {
    	int b;
    	cin>>b;
    	count+=b;
    	a[b]++;
	}
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		int m,n;
		cin>>m>>n;		
		a[n]+=a[m];
		int c=a[m];
		a[m]=0;
		count=count+c*(n-m);
		cout<<count<<endl;
	}
} 