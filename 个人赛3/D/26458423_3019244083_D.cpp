#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int cunt[3];
int ans[200020];
int main(){
	int n;
	n = read();
	int cnt = 0;
	for(int i = 1; i <= n; ++i) {
		int x;
		x = read();
		++cunt[x];
	} 
	if(cunt[1] >= 1 && cunt[2] >= 1){
		ans[1] = 2;
		ans[2] = 1;
		cnt = 2;
		--cunt[1];
		--cunt[2];
		for(int i = 1; i <= cunt[2]; ++i) ans[++cnt] = 2;
		for(int i = 1; i <= cunt[1]; ++i) ans[++cnt] = 1;
		printf("%d",ans[1]);
		for(int i = 2; i <= cnt; ++i) printf(" %d",ans[i]);
	} 
	else if(cunt[1] == 0){
		printf("2");
		for(int i = 2; i <= cunt[2]; ++i) printf(" 2");
	}
	else {
		printf("1");
		for(int i = 2; i <= cunt[1]; ++i) printf(" 1");
	}
	return 0;
}