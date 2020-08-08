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
int a[1100],b[1100];
int main(){
	int n;
    n = read();
    for(int i=1; i<=n; ++i) a[i] = read();
    for(int i=1; i<=n; ++i) b[i]= read();
    int x=1,y=1;
    while(x<=n && y<=n){
        if(a[x] > b[y]) y++;
        else x++;
    }
    int ans = max(n-x,n-y) + 1;
    printf("%d",ans);
    return 0;
}