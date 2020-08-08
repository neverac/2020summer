#include <bits/stdc++.h>
using namespace std;
string s;
int k,f[30][100100],len,cnt;
int main(){
	cin >> k >> s;
	len=s.length();
	long long ans=0;
	for(int i=0;i<26;++i){
		cnt=0;
		for(int j=0;j<len;++j){
			if(s[j]-'a' == i) f[i][++cnt] = j+1;
			if(cnt <= k && cnt != 0) ans += (long long)f[i][cnt];
			else if(cnt > k) ans += (long long)(f[i][cnt]-f[i][cnt-k]);
		}
	}
	cout << ans << endl;
	return 0;
}
