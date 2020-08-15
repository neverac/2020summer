#include <bits/stdc++.h>
using namespace std;
int n;
string s,now;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	cin>>s;
	while (n--){
		cin>>now;
		int i=0;
		while (true){
			while (s[i]==now[i]&&i<s.size()&&i<now.size()){
				if (s[i]>='0'&&s[i]<='9') break;
				i++;
			}
			if (i==s.size()&&i!=now.size()){
				cout<<"+"<<endl;
				break;
			}
			if (i==now.size()&&i!=s.size()){
				cout<<"-"<<endl;
				break;
			}
			if (s[i]>='0'&&s[i]<='9'){
				if (!(now[i]>='0'&&now[i]<='9')){
					cout<<"+"<<endl;
					break;
				}else {
					int s1=i+1,s2=i+1;
					while (s1<s.size()&&s[s1]>='0'&&s[s1]<='9') s1++;
					while (s2<now.size()&&now[s2]>='0'&&now[s2]<='9') s2++;
					s1--;s2--;
					if (s1>s2) {
						cout<<"-"<<endl;
						break;
					}else if (s1<s2){
						cout<<"+"<<endl;
						break;
					}else {
						while (s[i]==now[i]&&i<=s1) i++;
						if (s[i]>now[i]) {
							cout<<"-"<<endl;
							break;
						}else if (s[i]<now[i]){
							cout<<"+"<<endl;
							break;
						}
					}
				}
			}else {
				if (!(now[i]>='0'&&now[i]<='9')){
					if (s[i]>now[i]){
						cout<<"-"<<endl;
						break;
					}else {
						cout<<"+"<<endl;
						break;
					}
				}else {
					cout<<"-"<<endl;
					break;
				}
			}
		}
		
	}
	return 0;
}

