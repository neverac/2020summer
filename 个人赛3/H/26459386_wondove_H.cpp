#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
typedef int int_;
#define int long long
#define maxn 1000010
const int Mod=998244353;
const int inf=1e9+7;
inline int read(){
	int ret=0,ff=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') ff=-ff;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ret=ret*10+ch-'0';
		ch=getchar();
	}
	return ret*ff;
}
int cntd(int x){
	int qwq=0;
	while(x){
		qwq++;
		x/=10;
	}
	return qwq;
}
char str[100];
bool mp[100][100];
int_ main(){
	int T=read();
	while(T--){
		int n=read(),m=read();
		int qwq=0;
		int TTTT=0;
		for(int i=1;i<=n;++i){
			scanf("%s",str+1);
			for(int j=1;j<=m;++j){
				if(str[j]=='A') mp[i][j]=1,qwq=1;
				else mp[i][j]=0,TTTT=1;
			}
		}
		if(qwq==0){
			puts("MORTAL");
			continue;
		}
		if(TTTT==0){
			puts("0");
			continue;
		}
		int ans=4;
		if(mp[1][1]||mp[1][m]||mp[n][1]||mp[n][m]) ans=min(ans,2ll);
		
		
		for(int i=1;i<=n;++i){
			int qaq=0;
			for(int j=1;j<=m;++j){
				if(mp[i][j]==0) qaq=1;
			}
			if(qaq==0) ans=min(ans,2ll);
		}
		for(int i=1;i<=m;++i){
			int qaq=0;
			for(int j=1;j<=n;++j){
				if(mp[j][i]==0) qaq=1;
			}
			if(qaq==0) ans=min(ans,2ll);
		}
		
		
		int www=0,qqq=0,tat=0;
		for(int i=1;i<=n;++i){
			if(mp[i][1]==0) www=1;
			else tat=1;
			if(mp[i][m]==0) qqq=1;
			else tat=1;
		} 
		if(www==0||qqq==0) ans=min(ans,1ll);
		
		www=0,qqq=0;
		for(int i=1;i<=m;++i){
			if(mp[1][i]==0) www=1;
			else tat=1;
			if(mp[n][i]==0) qqq=1;
			else tat=1;
		} 
		if(www==0||qqq==0) ans=min(ans,1ll);
		if(tat==1) ans=min(ans,3ll);
		printf("%d\n",ans);
		
		
	}
	return 0;
}
/*
5
123456
1234
12
233
55555555
*/