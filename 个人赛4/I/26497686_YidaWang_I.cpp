#include<bits/stdc++.h>
using namespace std;
string s[100010];
int fail[1000010];
inline int getfail(string S){
	int len = S.length();
	int j=-1,k=0;
	fail[0] = -1;
	while (k<len){
		if (j==-1 || S[j]==S[k]){
			j++; k++;
			fail[k] = j;
		} else {
			j = fail[j];
		}
	}
	return fail[len]; 
}
char S[1000010]; 
int pos[100010];
string ans;
int N;
int main(){
	scanf("%d",&N);
	for (int i=1; i<=N; i++) cin>>s[i];
	ans = s[1];
	for (int i=1; i<N; i++){
		int j = i+1;
		int len = 0;
		string S;
		S = s[j]+s[i];
		int l1 = s[j].length();
		int l2 = ans.length();
		S = s[j] + "#"+ ans.substr(max(0,l2-l1),l1);
		int p = getfail(S);
		pos[i] = p;
//		ans = ans + s[j].substr(p,s[j].length()-p);
		for (int k=p; k<s[j].length(); k++) ans.push_back(s[j][k]);
	}
	cout<<ans<<endl;
	return 0;
}