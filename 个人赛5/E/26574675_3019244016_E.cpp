#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
#define MAX 200200
#define pb push_back
inline int read()
{
	int x=0;bool t=false;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')t=true,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	return t?-x:x;
}
int n,a[MAX],tot;
struct Node{int ch[2];}t[MAX<<5];
void insert(int &x,int w,int p)
{
	if(!x)x=++tot,t[x].ch[0]=t[x].ch[1]=0;
	if(p==-1)return;
	insert(t[x].ch[(w>>p)&1],w,p-1);
}
int Query(int x,int w,int p)
{
	if(p==-1)return 0;int c=(w>>p)&1;
	if(t[x].ch[c])return Query(t[x].ch[c],w,p-1);
	else return Query(t[x].ch[c^1],w,p-1)^(1<<p);
}
ll Solve(vector<int> v,int p)
{
	if(!v.size()||p==-1)return 0;
	vector<int> d[2];int ret=0,rt;
	for(int i:v)d[(i>>p)&1].pb(i);
	if(d[0].size()&&d[1].size())
	{
		ret=1<<(p+1);rt=tot=0;
		for(int i:d[0])insert(rt,i,30);
		for(int i:d[1])ret=min(ret,Query(rt,i,30));
	}
	return ret+Solve(d[0],p-1)+Solve(d[1],p-1);
}
int main()
{
	n=read();vector<int> a;
	for(int i=1;i<=n;++i)a.pb(read());
	printf("%I64d\n",Solve(a,30));
	return 0;
}
//              