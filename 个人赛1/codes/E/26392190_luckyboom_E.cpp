#include <bits/stdc++.h>
using namespace std;
long long n;
char c[200];
long long aa[25];
int tot=0;
void work2(){
	long long  q=1,t=26;
	while(n>t){
		n-=t;
		t*=26;
		q++;
	}
	n--;
	if(n==0){
		for(int i=1;i<=q;i++)cout<<'a';
		cout<<endl;
		return ;
	}
	while(n){
		c[++tot]=char('a'+(n%26));
		n/=26;
	}
	while(tot<q){
		c[++tot]='a';
	}
	for(int i=tot;i>0;i--){
		cout<<char(c[i]);
	}
	cout<<endl;
}

int main(){
	cin>>n;
	
	work2();
	return 0;
}