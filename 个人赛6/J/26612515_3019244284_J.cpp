#include<bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    int sum=0;
    for(int i=0;i<n;i++)
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