#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
	ll less,great;
}arr[1000020];
bool cmp(const node &a,const node &b)
{
	return a.less < b.less;
}
inline ll read()
{
    int x=0,f=1;
    char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int main()
{
	ll T,n,m;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		for(int i = 1; i <= n; ++i){
			arr[i].less = read();
			arr[i].great = read();
		}
		sort(arr+1, arr+n+1, cmp); 
		ll min=0,maxx=m;
		while(min <= maxx)
		{
			//cout<<min<<" "<<maxx<<endl;
			ll mid = (min + maxx)/2;
		//	bool flag = true;
			ll p = n/2+1;
			ll totsal = m;
			for(int i = n; i >= 1; --i)
        		if(p > 0 && arr[i].great >= mid) {--p;totsal -= max(mid, arr[i].less);}
				else totsal -= arr[i].less;
			//  cout<<p<<" "<<totsal<<endl;
			if(p > 0 || totsal < 0) maxx = mid-1; //lower
			else min = mid+1; //higher
		}
		cout<< min-1 <<endl;
	}
}