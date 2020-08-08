#include<bits/stdc++.h>
using namespace std;

const int maxn=2e5+7;
int n;
long long  a[maxn];
string s;
int len;
int work(char x,char y){
	int g=0,ans=0;
	while(g<len){
		while(s[g]!=x){
			g++;
			if(g==len)return ans;
		}

		g++;
		if(g==len)return ans;
		while(s[g]!=y){
			g++;
			if(g==len)return ans;
		}
		//cout<<"haha "<<g<<endl;
		ans++;
		g++;
	}return ans;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		cin>>s;
		len=s.length();
		int u=0,v=0;
		for(char i='0';i<='9';i++)
			for(char j='0';j<='9';j++){
				int z=work(i,j);
				//if(z)cout<<i<<j<<"  "<<z<<endl;
				u=max(u,z);
			}
		for(char i='0';i<='9';i++){
			int now=0;
			for(int j=0;j<len;j++){
				if(s[j]==i)now++;
			}
			v=max(v,now);
		}
		int ans=min(len-v,len-2*u);
		printf("%d\n",ans);
	}
	return 0;
}