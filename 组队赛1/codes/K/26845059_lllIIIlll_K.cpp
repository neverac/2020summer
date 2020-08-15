#include <bits/stdc++.h>
#include <vector>
using namespace std;
int a[5010],b[5010],c[5010],n,ans;
vector<int> bb;
int fuck(int ha,int num)
{
	int index = bb.size()-1;
	if (index==ha) index--;
	int cnt = 0;
	for (int i=n-1;i>num;i--)
	{
		if (bb[index]>a[i])
		{
			cnt++;
			index--;
			if (index==ha) index--;
		}
	}
	return cnt;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++) scanf("%d",&b[i]);
	for(int i=0;i<n;i++) c[i]=a[i];
	for(int i=0;i<n;i++) bb.push_back(b[i]);
    sort(a,a+n);
    sort(b,b+n);
	sort(bb.begin(),bb.end());

	int index = n-1;
	for (int i=n-1;i>=0;i--)
	{
		if (b[index]>a[i])
		{
			index--;
			ans++;
		}
	}

    for (int i=0;i<n;i++)
	{
		for (int i=0;i<n;i++) a[i] = c[i]; 
		sort(a+i+1,a+n);
		index = upper_bound(bb.begin(),bb.end(),c[i])-bb.begin();
		// xian da
		int da = bb.size()-1;
		int xiao = index;
		if (index<bb.size() && fuck(da,i)>=ans-1)
		{
			ans--;
			cout<<bb[da]<<' ';
			bb.erase(bb.begin()+da);
		}
		else if (index < bb.size() && fuck(xiao,i)>=ans-1)
		{
			while (xiao < da-1)
			{
				int mid = (da+xiao)>>1;
				if (fuck(mid,i)>=ans-1) xiao = mid;
				else da = mid;
			}
			cout<<bb[xiao]<<' ';
			bb.erase(bb.begin()+xiao);
			ans--;
		}
		else if (fuck(index-1,i)>=ans)
		{
			cout<<bb[index-1]<<' ';
			bb.erase(bb.begin()+index-1);
		}
		else
		{
			da = index-1;
			xiao = 0;
			while (xiao < da-1)
			{
				int mid = (da+xiao)>>1;
				if (fuck(mid,i)>=ans) xiao = mid;
				else da = mid;
			}
			cout<<bb[xiao]<<' ';
			bb.erase(bb.begin()+xiao);
		}
	}
}