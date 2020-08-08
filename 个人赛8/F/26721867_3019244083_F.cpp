#include <bits/stdc++.h>
using namespace std;
char c[200020];
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
        scanf("%s",c+1);
        int n = strlen(c+1);
        int del = n-2;
        for(int i = 0;i <10; ++i) 
            for(int j = 0;j < 10; ++j) {
                int tot = 0,tmp = i;
                for(int k = 1;k <= n; ++k) 
                    if(c[k] == tmp + '0') tmp = (tmp - i == 0)?j:i;
                    else ++tot;
                if(tmp == i) del = min(del,tot);
    		}
        printf("%d\n",del);
    }
    return 0;
}