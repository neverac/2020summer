#include <bits/stdc++.h>
using namespace std;
long long n;
int a[20];
int vis[30];
int main(){
	cin>>n;
	long long l=n,cnt=0;
	while (n){
		if (n%26!=0){
			a[++cnt]=n%26;
			n/=26;	
		}else {
			a[++cnt]=26;
			n/=26;
			n--;
		}
	}
	for (int i=cnt;i>=1;i--){
		cout<<(char)(a[i]+'a'-1);
	}
	cout<<endl;
	return 0;
}

