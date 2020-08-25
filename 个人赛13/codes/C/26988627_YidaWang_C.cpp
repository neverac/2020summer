#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
string s[1010];
int id[1010],tot;
bool cmp(int x,int y){
	return s[x].length()<s[y].length();
}
int main(){
	int N,M;
	cin>>N>>M;
	for (int i=1; i<=M; i++) {
		string t;
		cin>>t;
		if (!mp[t]) s[++tot] = t,id[tot] = tot,mp[t]=1;
	}
	sort(id+1,id+tot+1,cmp);
//	for (int i=1; i<=tot; i++) printf("%d  %d\n",id[i],s[id[i]].length());
	int ans=0;
	for (int i=1; i<=tot; i++){
		if (N>=s[id[i]].length()){
			N-=s[id[i]].length();
			ans++;
			N--;
			if (N<=0) break;
//			printf("debug %d %d %d\n",N,ans,s[id[i]].length());
		} else break;
	}
	printf("%d\n",ans);
	return 0;
}