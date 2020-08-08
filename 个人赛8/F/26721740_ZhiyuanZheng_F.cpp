#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while (T--){
		string s;
		cin>>s;
		int best=0;
		int l=s.size();
		for (int a='0';a<='9';a++){
			for (int b='0';b<='9';b++){
				string tmp="";
				tmp=(char)a;
				tmp+=(char)b;
				int pos=0,i=0,ans=0;
				while (i<l){
					if (s[i]==tmp[pos]){
						pos=!pos;	
						if (pos==0) ans+=2;
					}
					i++; 
				}
				best=max(best,ans);
			}
		}
		for (int a='0';a<='9';a++){
			string tmp="";
			tmp=(char)a;
			int pos=0,i=0,ans=0;
			while (i<l){
				if (s[i]==tmp[pos]){	
					ans++;
				}
				i++; 
			}
			best=max(best,ans);	
		}
		cout<<l-best<<endl;
	}	
	return 0;
}

