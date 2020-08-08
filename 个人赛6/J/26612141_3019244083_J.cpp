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
int main()
{
    int n,k;
    n = read();
    k = read();
    int ans = 0;
    for(int i = 1;i <= n; ++i)
    {
        int p;
        p = read();
        if(!(p % k)) ans += p/k;
        else ans += p/k+1;
     }
     if(ans%2) printf("%d",ans/2+1);
     else printf("%d",ans/2); 
    return 0;
}