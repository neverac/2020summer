#include<iostream>
using namespace std;
int a[500010];
int main()
{
	int r,s,p;
	cin>>r>>s>>p;
	int da = 0;
	for (int i=0;i<p;i++)
	{
		int x,y;
		cin>>x>>y;
		int tmp = y>s ? y-s+r-x+1:s-y+1+r-x+1;
		da = max(da,tmp);
		a[tmp]++;
	}
	int tmp = 0;
	for (int i=1;i<=da;i++)
	{
		tmp+=a[i];
		if (tmp) tmp--;
	}
	cout << da+tmp << endl;
	return 0;
}