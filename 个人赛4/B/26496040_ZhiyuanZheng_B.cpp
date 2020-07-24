#include <bits/stdc++.h>
using namespace std;
int n;

int main(){
	string s;
	cin>>s;
	if (s.size()==1){
		int a=s[s.size()-1]-'0';
		if (a%4==0) cout<<4<<endl;
		else cout<<0<<endl;
	}else {
		int a=s[s.size()-1]-'0';
		int b=s[s.size()-2]-'0';
		int x=b*10+a;
		if (x%4==0) cout<<4<<endl;else cout<<0<<endl;
	}
	
	return 0;
}

