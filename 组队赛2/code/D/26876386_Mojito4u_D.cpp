#include <bits/stdc++.h>
using namespace std;
string s;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	string f="";
	while (cin>>s){
		if (s!="bubble"&&s!="tapioka"){
			f+=s+" ";
		}
	}
	if (f.size()==0) cout<<"nothing"<<endl;
	else cout<<f.substr(0,f.size()-1)<<endl;
	
	return 0;
}

