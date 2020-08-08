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
	
	int T;
	T = read();
	while(T--)
	{
		int n,k;
		n = read();
		k = read();
		bool flag = false;
		if(k % (n-1) == 0) flag = true;
		if(n>k) printf("%d\n",k);
		else
		{
			ll ans = k/(n-1) + k;
			if(flag) cout<<ans-1<<endl;
			else cout<<ans<<endl;
		}
	}
}