#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
using namespace std;
int const maxn=5007;
int n,a[maxn],d[maxn*maxn],tot,m,num[maxn];
map<int,int>s;
int work(int x){
	num[0]=1;
	int nm=2;
	for(int i=1;i<n;++i){
		if(!s.count(a[i]-x)){
			num[i]=1;
			continue;
		}
		num[i]=num[s[a[i]-x]]+1;
		if(num[i]>nm)nm=num[i];
	}
	return nm;
}
inline int Read()
{
    int x=0,f=1;char c=getchar();
    while(c>'9'||c<'0') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') {x=x*10+c-'0'; c=getchar();}
    return x*f;
}
int main(){
	n=Read();
	for(int i=0;i<n;++i){
		a[i]=Read();
	}
	sort(a,a+n);
	for(int i=0;i<n;++i){
		s.insert(pair<int,int>(a[i],i));
	}
	tot=0;
	for(int i=0;i<n-2;++i)
		for(int j=i+2;j<n;++j){
			if ((a[j]-a[i])%2==0&&s.count((a[j]+a[i])/2)) 
				d[tot++]=(a[j]-a[i])/2;	
		}
	sort(d,d+tot);
	m=unique(d,d+tot)-d;
	//cout<<m<<endl;
	int ans=2;
	for(int i=0;i<m;++i){
		ans=max(ans,work(d[i]));
	}
	printf("%d\n",ans);
	return 0;
}
