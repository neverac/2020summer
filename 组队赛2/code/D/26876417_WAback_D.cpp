#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3;
int main(){
	cin>>s1>>s2>>s3;
	int cnt = 0;
	if (s1 != "bubble" && s1 != "tapioka"){
		cout<<s1;
		cnt++;
	}
	if (s2 != "bubble" && s2 != "tapioka"){
		if (cnt) cout<<" "<<s2;
		else cout<<s2;
		cnt++;
	}
	if (s3 != "bubble" && s3 != "tapioka"){
		if (cnt) cout<<" "<<s3;
		else cout<<s3;
		cnt++;
	}
	if (cnt) puts("");
	else puts("nothing");
	return 0;
}