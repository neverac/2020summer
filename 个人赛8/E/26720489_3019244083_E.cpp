#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		n = read();
		ll tot = 0,temp = 0, ans = 0,sum = 0;
		int maxl,maxr,ll,rr;
		for(int i = 1; i <= n; ++i) {
			int x = read();
			sum += x;
			if(temp <= 0) {temp = x;ll = i; rr = i;}
			else {temp += x; rr = i;}
			if(temp > ans) {ans = temp;maxl = ll; maxr = rr;}
		}
		bool flag = false;
		if(sum > ans) flag = true;
		if(sum == ans && maxl == 1 && maxr == n) flag = true;
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
} 