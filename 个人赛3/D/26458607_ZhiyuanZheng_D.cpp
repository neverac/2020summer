#include <bits/stdc++.h>
int prime[100000];
bool used[400020]; 
#define maxn 400010
using namespace std;
int a1,b2;
set <int> p;
int main()
{
	int k=0;
	memset(used,0,sizeof(used));
	for (int i=2;i<=maxn;i++){
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
	for (int i=0;i<=k;i++) p.insert(prime[i]);
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if (x==1) a1++;else b2++;		
	}
	int num=0,ans=0;
	if (b2>0) {
		ans++;
		num=2;
		b2--;
		cout<<2<<" ";
		if (a1>0){
			ans++;
			num=3;
			a1--;
			cout<<1<<" "; 
		}
	}
	while (b2>0){
		num+=2;
		if (p.find(num)!=p.end()) ans++;
		cout<<2<<" ";
		b2--;	
	}
	while (a1>0){
		num+=1;
		if (p.find(num)!=p.end()) ans++;
		cout<<1<<" ";
		a1--;
	}
	return 0;
} 