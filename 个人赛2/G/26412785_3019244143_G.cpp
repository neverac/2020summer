#include <iostream>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	int* ans=new int [n];
	ans[0]=1;
	int x=1,y=n-1;
	for(int i=1;i<n;i++)
	{
		ans[i]=ans[i-1]+x*y;
		y--;
		x=x*(-1);
	}
	for(int i=0;i<k;i++)
	    cout<<ans[i]<<" ";
	int mid=ans[k-1];
	if(k%2==1)
	{
		for(int i=k;i<n;i++)
		    cout<<++mid<<" ";
	}
	else
	{
		for(int i=k;i<n;i++)
		    cout<<--mid<<" ";
	}
}