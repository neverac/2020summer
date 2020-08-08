#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
int ans[200020];
int del[200020];
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
        string str;
        cin>>str;
        int len=str.size();
        memset(ans,0,sizeof(ans));
        memset(del,0,sizeof(del));
        for(int i = 4; i < len; ++i) if(str[i-4]=='t' && str[i-3]=='w' && str[i-2]=='o' && str[i-1]=='n' && str[i]=='e') del[i-2]=1;
        for(int i = 2; i < len; ++i){
        	if(str[i-2]=='t' && str[i-1]=='w' && str[i]=='o') if(del[i] == 0) del[i-1] = 1;
            if(str[i-2]=='o' && str[i-1]=='n' && str[i]=='e') if(del[i-2] == 0) del[i-1] = 1;
        }
        int cnt = 0;
		for(int i = 0;i < len; ++i) if(del[i]) ans[++cnt] = i+1;
        printf("%d\n",cnt);
        if(cnt > 0) printf("%d",ans[1]);
        for(int i = 2; i <= cnt; ++i) printf(" %d",ans[i]);
        printf("\n");
    }
    return 0;
}