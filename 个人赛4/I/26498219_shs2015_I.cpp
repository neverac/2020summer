#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
typedef long long LL;
string s[100010];
int N;
int fail[1000100];
void KMP(string S){
	string a = " "+S;
//	cout<<"KMP : "<<a<<endl;
	int j = 0;fail[0] = fail[1] = 0;
	for(int i = 2;i < a.size();i++){
		while(j && a[i]!=a[j+1])j = fail[j];
		if(a[i] == a[j+1])j++;
		fail[i] = j;
	}
}
int main(){
	scanf("%d",&N);
	for(int i = 1;i <= N;i++)cin>>s[i];
	string ans = s[1];
	for(int i = 2;i <= N;i++){
		string tmp = s[i];
		int len = min(ans.size(),tmp.size());
		tmp.push_back('#');
		for(int j = ans.size()-len;j < ans.size();j++)tmp.push_back(ans[j]);
		KMP(tmp);
		int n = fail[tmp.size()];
		//printf("n = %d\n",n);
		for(int j = n;j < s[i].size();j++)ans.push_back(s[i][j]);
	//	cout<<"ans : "<<ans<<endl;
	}
	cout<<ans;
	return 0;
} 