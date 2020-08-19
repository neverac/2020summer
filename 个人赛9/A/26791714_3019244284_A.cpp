#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=1e5+5;
int arr[2*maxn];

int main()
{
    int n;
    while(cin>>n)
    {
    	int i;
    	for(i=0;i<2*n;i++)
    	scanf("%d",&arr[i]);
    	sort(arr,arr+2*n);
    	long long a=arr[n-1]-arr[0];
		long long b=arr[2*n-1]-arr[n];
		long long minn=a*b;
		a=arr[2*n-1]-arr[0];
		for(int i=1;i<n;i++)
		{
			b=arr[i+n-1]-arr[i];
			minn=min(minn,a*b);
		}
		cout<<minn<<endl;
	}
    return 0;    
}

