#include <bits/stdc++.h>
int prime[1000];
bool used[2000]; 
#define maxn 1100
using namespace std;

int main()
{
	int n=1100;
	int k=0;
	memset(used,0,sizeof(used));
	for (int i=2;i<=n;i++){
		if (!used[i]){
			prime[k]=i;
			k++;
		}
		for (int j=0;j<=k-1;j++){
			if (i*prime[j]>maxn) break;else used[i*prime[j]]=1;
			if (i%prime[j]==0) break;
		}
	}
	k--;
	
	int t;
	cin>>t;
	int i=0;
	while (prime[i]<t) i++;
	if (prime[i]>(t*(t-1)/2)){
		cout<<-1<<endl;
		return 0;
	}
	cout<<prime[i]<<endl;
	if (prime[i]==t){
		for (int ii=1;ii<t;ii++){
			cout<<ii<<" "<<ii+1<<endl;
		}
		cout<<1<<" "<<t<<endl;
	}else {
		for (int ii=1;ii<t;ii++){
			cout<<ii<<" "<<ii+1<<endl;
		}
		cout<<1<<" "<<t<<endl;
		for (int ii=1;ii<=prime[i]-t;ii++){
			cout<<ii<<" "<<ii+t/2<<endl;
		}
	}
	return 0;
} 