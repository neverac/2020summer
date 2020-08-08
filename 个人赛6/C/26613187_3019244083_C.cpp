#include <bits/stdc++.h> 
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int f[100010];
int find(int x)
{
    if(f[x] == -1) return x;
    else return f[x] = find(f[x]);
}
int main()
{
    int n,k;
	int cnt = 0;
    n = read();
	k = read();
    memset(f, -1, sizeof(f));
    for(int i = 1; i <= k; ++i)
    {
    	int x,y,xfind,yfind;
        x = read();
        y = read();
        xfind = find(x);
        yfind = find(y);
        if(xfind != yfind) f[xfind] = yfind;
        else ++cnt; 
    }
    printf("%d",cnt);
    return 0;
}