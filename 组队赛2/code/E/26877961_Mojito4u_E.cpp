#include <bits/stdc++.h>
using namespace std;
long long a[2100];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while (T--){
		int k,l;
		cin>>k>>l;
		if (l>=2000){
			cout<<-1<<endl;
			continue;
		}
		a[1]=-1;
		int tmp=1999+k;
		for (int i=2;i<=1999;i++){
			if (tmp>=1e6) a[i]=1e6,tmp-=1e6;
			else {
				a[i]=tmp,tmp=0;
			}
		}
		cout<<1999<<endl;
		for (int i=1;i<=1999;i++){
			cout<<a[i]<<" "; 
		}
		cout<<endl;
	}	
	return 0;
}

