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
int a[100010],b[100010];
ll f1[100010],f2[100010];
int main()
{
	int n;
	n = read();
	for(int i = 1; i <= n; ++i) a[i] = read();
	for(int i = 1; i <= n; ++i) b[i] = read();
	for(int i = 1; i <= n; ++i){
		f1[i]=max(f2[i-1] + a[i],f1[i-1]);
        f2[i]=max(f1[i-1] + b[i],f2[i-1]);
	}	
	if(f1[n] > f2[n]) cout<<f1[n]<<endl;
	else cout<<f2[n]<<endl;
	return 0;
}