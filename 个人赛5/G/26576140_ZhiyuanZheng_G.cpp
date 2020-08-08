#include <bits/stdc++.h>
using namespace std;
int a[301100];
int main(){
	int T;
	cin>>T;
	while (T--){
		string s;
		cin>>s;
		int ans=0;
		int i=0;
		if (s.size()<=2) cout<<"0\n\n";
		else{
			while (i<(s.size()-2)){
			string tmp=s.substr(i,3);
			if (i<(s.size()-4)){
				string tt=s.substr(i,5);
				if (tt=="twone"){
					a[++ans]=i+3;
					i=i+5;
				}else if (tmp=="one") {
						a[++ans]=i+2;
						i=i+3;
					}else if (tmp=="two"){
						a[++ans]=i+2;
						i=i+3; 
					}else i++;
			}else {
				if (tmp=="one") {
					a[++ans]=i+2;
					i=i+3;
				}else if (tmp=="two"){
					a[++ans]=i+2;
					i=i+3; 
				}else i++;
			}
		}
		cout<<ans<<endl;
		if (ans!=0){
			for (int k=1;k<ans;k++) cout<<a[k]<<" ";
			cout<<a[ans]<<endl;
		}else cout<<endl;
		}
		
	}
	return 0;
}

