#include <bits/stdc++.h>
using namespace std;
long long does(string s){
	long long l=0;
	for (int i=0;i<s.size();i++){
		l=l*10+(s[i]-'0');
	}
	return l;
}
int main(){
	int T;
	cin>>T;
	int tt=1;
	while (tt<=T){
		string s;
		cin>>s;
		int l=s.size();
		long long maxx=-1e18;
		
		maxx=max(maxx,does(s.substr(0,l-4))+does(s.substr(l-4,1))-does(s.substr(l-3,1))*does(s.substr(l-2,1))/does(s.substr(l-1,1)));
		maxx=max(maxx,does(s.substr(0,1))+does(s.substr(1,l-4))-does(s.substr(l-3,1))*does(s.substr(l-2,1))/does(s.substr(l-1,1)));
	
		if (l>5){
			maxx=max(maxx,does(s.substr(0,l-5))+does(s.substr(l-5,1))-does(s.substr(l-4,1))*does(s.substr(l-3,1))/does(s.substr(l-2,2)));
			maxx=max(maxx,does(s.substr(0,1))+does(s.substr(1,l-5))-does(s.substr(l-4,1))*does(s.substr(l-3,1))/does(s.substr(l-2,2)));	
		}
		
		cout<<"Case #"<<tt<<": "<<maxx<<endl;
		tt++;
	}
	return 0;
} 