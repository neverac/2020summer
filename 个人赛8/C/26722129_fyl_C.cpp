#include <bits/stdc++.h>
using namespace std;
#define ll long long
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=getchar();
	return x*f;
}
const int maxn=400100;
int n,m,size,c[maxn],block[maxn],b[maxn];
ll ans;

void resort(int i){
	int l=(i-1)*size+1,r=min(i*size,n);
	for(int i=l;i<=r;i++) b[i]=c[i];
	sort(b+l,b+r+1);
}
int query(int l,int r,int x){
	if(l>r)return 0;
	int bl=block[l],br=block[r],rec=0;
	if(bl==br){
		for(int i=l;i<=r;i++) if(c[i]>x) rec++;
		return rec;
	}else{
		for(int i=l;block[i]==bl;i++)if(c[i]>x)rec++;
		for(int i=r;block[i]==br;i--)if(c[i]>x)rec++;
		for(int i=bl+1;i<br;i++){
			int ml=(i-1)*size+1,mr=min(n,i*size);
			rec+=mr-ml+1-(upper_bound(b+ml,b+mr+1,x)-(b+ml));
		}
		return rec;
	}
}
int query2(int l,int r,int x){
	//printf("%d %d %d\n",l,r,x);
	if(l>r)return 0;
	int bl=block[l],br=block[r];
	int rec=0;
	if(bl==br){
		for(int i=l;i<=r;i++) if(c[i]<x) rec++;
		return rec;
	}else{
		for(int i=l;block[i]==bl;i++)if(c[i]<x)rec++;
		for(int i=r;block[i]==br;i--)if(c[i]<x)rec++;
		for(int i=bl+1;i<br;i++){
			int ml=(i-1)*size+1,mr=min(n,i*size);
			rec+=lower_bound(b+ml,b+mr+1,x)-(b+ml);
		}
		return rec;
	}
}
void modify(int l,int r){
	if(c[l]>c[r]) ans--;
	if(c[r]>c[l]) ans++;
	int aa=0,bb=0,cc=0,dd=0;
	if(r-1>=l+1){
		aa=query(l+1,r-1,c[l]),cc=query2(l+1,r-1,c[l]);
		bb=query(l+1,r-1,c[r]),dd=query2(l+1,r-1,c[r]);
		//printf("%d %d %d %d\n",aa,bb,cc,dd);
	}
	ans=ans+aa-cc+dd-bb;
	swap(c[l],c[r]);
	resort(block[l]);resort(block[r]);
}
int main(){
	n=read(),size=sqrt(n),m=read();
	for(int i=1;i<=n;i++){
		b[i]=c[i]=i;
		block[i]=(i-1)/size+1;
	}
	for(int i=1;i<=m;i++){
		int a=read(),b=read();
		if(a>b) swap(a,b);
		modify(a,b);
		printf("%lld\n",ans);
	}
	return 0;
}
/*
42 42
23 7
9 6
17 22
19 23
15 42
14 10
17 12
2 25
8 39
13 9
29 26
17 2
11 14
33 20
29 1
4 28
25 4
37 32
6 37
30 42
39 1
12 29
39 3
6 41
26 34
11 21
21 32
20 35
6 22
32 35
34 40
33 14
13 10
1 2
5 12
21 9
41 30
5 27
29 35
22 32
1 1
2 10
*/