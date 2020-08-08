#include <bits/stdc++.h>
using namespace std;
int n;
int a[200];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while (T--){
		cin>>n;
		for (int i=1;i<=n;i++){
			cin>>a[i];
		}
		string last="";
		for (int i=1;i<=101;i++) last+='a';
		cout<<last<<endl;
		for (int i=1;i<=n;i++){
			string now=last.substr(0,a[i]);
			int x=last[a[i]]-'a';
			if (x!=25) now+=(char)(x+'a'+1);
			else now+='a';
			last.erase(0,a[i]+1);
			cout<<now<<last<<endl;
			last=now+last;
		}
	}
	return 0;
	return 0;
}

