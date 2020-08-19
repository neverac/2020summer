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
ll a[400],sum[400];
int main()
{
	int n = read();
	for(int i = 1; i <= n; ++i) {
		a[i] = read();
		sum[i] = sum[i-1] + a[i]; 
	}
	ll minn = 1000;
	for(int i = 0; i < n; ++i)
	  for(int j = i+1; j <= n; ++j) {
	  	 ll tmp = sum[j] - sum[i];
	  	 if(abs(tmp-180) < minn) minn = abs(tmp-180);
	  }
	cout<<2*minn<<endl;
	return 0;
} 