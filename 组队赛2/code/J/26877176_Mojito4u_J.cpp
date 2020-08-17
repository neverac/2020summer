#include <bits/stdc++.h>
using namespace std;
int n,m;
int mp[20][600];
bool vis[600];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while (T--){
		cin>>n>>m;
		int ans=n,tot=0;
		memset(vis,0,sizeof(bool)*(n+1));
		for (int i=1;i<=m;i++){
			string s;
			cin>>s;
			int b;
			mp[i][0]=0;
			for (int j=0;j<n;j++){
				b=s[j]-'0';
				if (b){
					mp[i][++mp[i][0]]=j+1;
					if(!vis[j+1]){
						vis[j+1]=1;
						tot++;
					} 
				}
			}
		}
		if(tot<n){
			cout<<-1<<endl;
			continue;
		}
		int count=0,num;
		for (int i=1;i<=pow(2,m)-1;i++){
			memset(vis,0,sizeof(bool)*(n+1));
			num=0;count=0;
			for (int j=1;j<=m;j++){
				
				if (i&(1<<(j-1))){
					// cout<<j<<' ';
					for (int k=1;k<=mp[j][0];k++){
						if (!vis[mp[j][k]]) {
							vis[mp[j][k]]=1;
							count++;
						}
					}
					num++;	
				}
			}
			// cout<<endl;
			if (count<n||num>=ans) continue;
			ans=num;
		}
		
		cout<<ans<<endl;
	}
	return 0;
}
