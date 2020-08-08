#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[110][110][20];
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
    int n = read(),q = read(),c = read();
    for(int i = 1; i <= n; ++i)
    {
    	int x = read(),y = read(),k = read();
        ++a[x][y][k];
    }
    for(int i = 1; i <= 101; ++i)
    	for(int j = 1; j <= 101; ++j)
    		for(int k = 0; k <= c; ++k)
    				a[i][j][k] += a[i][j-1][k] + a[i-1][j][k] - a[i-1][j-1][k];
    /*
    for(int i = 1; i <= 50; ++i)
      for(int j = 1; j <= 50; ++j){
        for(int k = 0; k <= c; ++k) printf("%d ",a[i][j][k]);
    	printf("\n")
	  }
    */
	for(int i = 1; i <= q; ++i)
    {
       	int t = read(), x1 = read(), y1 = read(), x2 = read(), y2 = read();
        int ans = 0;
        for(int j = 0; j <= c; ++j)
        {
            int cnt = t % (c+1) + j;
            for(int k = 1; k <= cnt % (c+1); ++k) ans += (a[x2][y2][j] - a[x2][y1-1][j] + a[x1-1][y1-1][j] - a[x1-1][y2][j]);
        }
        printf("%d\n",ans);
    }
    return 0;
}