#include<bits/stdc++.h>
using namespace std;
set<int> s[3];
int pri[200005];
int n,m,tmp;
int main(){
	cin >> n;
	for(int i= 0;i < n; ++ i){
		cin >> pri[i];
	}
	for(int i = 0,x;i < n; ++ i){
		cin >> x;
		s[--x].insert(pri[i]);
	}
	for(int i = 0,x;i < n; ++ i){
		cin >> x;
		s[--x].insert(pri[i]);
	}
	cin >> m;
	for(int i=1;i<m;++i){
		cin >> tmp;
		tmp--;
		if(s[tmp].size() == 0) cout << "-1 ";
		else{
			int pr = *(s[tmp].begin());
			cout << pr << " ";
			if(s[0].find(pr)!=s[0].end()) s[0].erase(pr);
			if(s[1].find(pr)!=s[1].end()) s[1].erase(pr);
			if(s[2].find(pr)!=s[2].end()) s[2].erase(pr);
		}
	}
	cin >> tmp;
	tmp--;
	if(s[tmp].size() == 0) cout << "-1"<<endl;
	else{
		int pr = *(s[tmp].begin());
		cout << pr << endl;
		if(s[0].find(pr)!=s[0].end()) s[0].erase(pr);
		if(s[1].find(pr)!=s[1].end()) s[1].erase(pr);
		if(s[2].find(pr)!=s[2].end()) s[2].erase(pr);
	}
}