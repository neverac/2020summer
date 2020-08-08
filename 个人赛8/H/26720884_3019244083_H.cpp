#include <bits/stdc++.h>
using namespace std;
int a[200020],ll[200020],rr[200020];
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
    for(int i = 1;i <= n; i++) ll[i] = 1;
    for(int i = 1;i <= n; i++) rr[i] = 1;
    for(int i = 1;i <= n; i++) a[i] = read();
    int len = 1;
    for(int i = n-1;i >= 1; i--)
    {
        if(a[i] < a[i+1]) rr[i] = rr[i+1] + 1;
        len=max(len,rr[i]);
    }
    for(int i = 2;i <= n; i++)
    {
        if(a[i] > a[i-1]) ll[i] = ll[i-1] + 1;
        len=max(len,ll[i]);
    }
    for(int i = 1;i <= n-2; i++) if(a[i] < a[i+2]) len=max(len,ll[i] + rr[i+2]);
	printf("%d",len);
    return 0;
}