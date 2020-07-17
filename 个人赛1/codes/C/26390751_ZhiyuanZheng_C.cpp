#include <bits/stdc++.h>
using namespace std;
bool vis[100100];
int a[100100];
int main(){
	int T;
	cin>>T;
	while (T--){
		memset(vis,0,sizeof vis);
		bool flag=true;
		int n;
		cin>>n;
		int tmp=1,last;
		for (int i=1;i<=n;i++){
			int x;
			cin>>x;
			if (i==1) a[i]=x,vis[x]=true;
			else {
				if (x>last) a[i]=x,vis[x]=true;
				else {
					if (tmp<x) a[i]=tmp,vis[tmp]=true,tmp++;
					else flag=false;
				}
			}
//			cout<<tmp<<" "<<a[i]<<endl;
			while (vis[tmp]) tmp++;
			last=x;
		}
		memset(vis,0,sizeof vis);
		for (int i=1;i<=n;i++){
			vis[a[i]]=true;
		}
		for (int i=1;i<=n;i++){
			if (!vis[i]) flag=false;
		}
		if (!flag) cout<<-1<<endl;
		else {
			for (int i=1;i<=n;i++){
				cout<<a[i];
				if (i!=n) cout<<" ";else cout<<endl;
			}
		}
	}
	return 0;
}

