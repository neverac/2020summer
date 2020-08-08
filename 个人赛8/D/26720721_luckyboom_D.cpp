#include<bits/stdc++.h>
using namespace std;

const int N=200;
char s[N];
int a[N],len,n;
void print(){
	for(int i=0;i<=len;i++)printf("%c",s[i]);
		cout<<endl;
}
void work(){
	for(int i=0;i<=len;i++)s[i]='a';
	print();
	for(int i=1;i<=n;i++){
		int z=(s[a[i]]+1)%123;
		if(z<97)z+=97;
		//cout<<z<<endl;
		s[a[i]]=(char)(z);
		print();
	}
}
typedef long long LL;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		len=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]>len)len=a[i];
		}
		if(len==0)len++;
		work();
	}
}