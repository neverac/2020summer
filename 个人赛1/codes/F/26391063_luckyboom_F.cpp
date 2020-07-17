#include <bits/stdc++.h>
using namespace std;
inline int get_num(){
	char ch;
	int num=0;
	ch=getchar();
	while(ch<'0'||ch>'9'){ch=getchar();}
	while(ch>='0'&&ch<='9'){num=(num<<3)+(num<<1)+ch-'0';ch=getchar();}
	return num;
}
int n,q,b,c;
int const maxn=1e5+10;
long long a[maxn],sum=0,tot[maxn];
int main(){
	n=get_num();
	for(int i=1;i<=n;i++){
		a[i]=get_num();
		tot[a[i]]++;
		sum+=a[i];
	}
	q=get_num();
	for(int i=1;i<=q;i++){
		b=get_num(),c=get_num();
		tot[c]+=tot[b];
		sum=sum+(c-b)*tot[b];
		printf("%lld\n",sum);
		tot[b]=0;
	}
	return 0;
}