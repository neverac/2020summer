#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin>>T;
	while (T--){
		string s;
		cin>>s;
		string ji="",ou="";
		for (int i=0;i<s.size();i++){
			if ((s[i]-'0')&1) ji+=s[i];else ou+=s[i];
		}
		int i=0,j=0;
		while (i<ji.size()&&j<ou.size()){
			if (ji[i]<ou[j]) {
				cout<<ji[i];
				i++;
			}else {
				cout<<ou[j];
				j++;
			}
		}
		for (int t=i;t<ji.size();t++) cout<<ji[t];
		for (int t=j;t<ou.size();t++) cout<<ou[t];
		cout<<endl;
	}
	return 0;
}
