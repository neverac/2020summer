#include <iostream>
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
	int n;
	n = read();
	ll money = 100;
	ll cnt = 0;
	ll pre = 0;
	int k = n+1;
	for(int i = 1; i <= n; ++i) {
		int c;
		c = read();
		if(c <= money) {
			pre = c;
			cnt = money / c;
			money %= c;
			k = i+1;
			break;
		}
	}
	for(int i = k; i <= n; ++i){
		int c;
		c = read();
		if(c >= pre) {pre = c; continue;}
		money += cnt*pre;
		ll cap = money/c;
		if(cap > 100000) cnt = 100000;
		else cnt = cap;
		money -= cnt*c;
		pre = c;
	}
	money += cnt*pre;
	cout<<money<<endl;
	return 0;
}