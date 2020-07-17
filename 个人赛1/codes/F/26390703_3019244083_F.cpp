#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
//ksm
ll ksm(int a,int b){
	if(b==1) return a;
     else 
     {
	    int s=ksm(a,b/2);
	    if(b%2==0) return (s%inf)*(s%inf);
	    else return (s%inf)*(s%inf)*a%inf;
	 }
}
//gcd
int gcd(int a,int b)
{
	int x=a%b;
	while(x>0)
	{ 
        a=b;
        b=x;
        x=a%b;
	}
	return b;
}
//quickprime
const int MAXN = 1000010;
/*int prime[MAXN];
void getPrime(){
	memset(prime,0,sizeof(prime));
	for(int i=2;i<=MAXN;i++){
 		if(!prime[i]) prime[++prime[0]] = i;
 		for(int j=1; j<=prime[0] && prime[j]<=MAXN/i; j++)
		{
 			prime[prime[j]*i]=1;
 			if(i%prime[j]==0) break;
 		}
 	}
}
*/
//quickread
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
//ptree
/*
ll num[1000010];
ll seg[1000010];//线段树上除了add之外的值
ll add[1000010];//当前区间共同加上的值
inline ll ls(ll x){return x<<1;}//左儿子
inline ll rs(ll x){return x<<1|1;}//右儿子
void build(ll now,ll l,ll r) //now：现在所在的结点 l-r：原区间 
{
    if(l==r)
    {
        seg[now]=num[l];
        return;
    }
    ll mid=(l+r)>>1;
    build(ls(now),l,mid);              //建立左儿子
    build(rs(now),mid+1,r);            //建立右儿子
    seg[now]=seg[ls(now)]+seg[rs(now)];//当前节点为其左右儿子的值之和
}
void modify(ll now,ll l,ll r,ll x,ll y,ll v)//给定区间[x,y]所有数加上v
{
    if(x<=l&&y>=r) //如果给定区间包含当前区间就更新
    {
        add[now]+=v; //加上这个区间共同的值
        return;
    }
    seg[now]+=(min(r,y)-max(l,x)+1)*v;//计算子节点对当前节点的影响
    ll mid=(l+r)>>1;
    if(x<=mid)modify(ls(now),l,mid,x,y,v);
    if(mid<y)modify(rs(now),mid+1,r,x,y,v);
}
ll query(ll now,ll l,ll r,ll x,ll y)//询问区间[x,y]的和
{
    if(l>=x&&r<=y)return seg[now]+(r-l+1)*add[now];//加上这个区间的应当加上的add的值
    ll mid=(l+r)>>1;
    ll res=(min(r,y)-max(l,x)+1)*add[now];  //计算标记的影响
    if(x<=mid)res+=query(ls(now),l,mid,x,y);       //计算左节点的贡献
    if(mid<y)res+=query(rs(now),mid+1,r,x,y);      //计算右节点的贡献
    return res;
}
*/

// Bignum
class Bignum{
public:
	int w;
	ll num[100];
	Bignum operator = (ll x){
		memset(num, 0, sizeof num);
		w = 0;
		while(x){
			num[++w] = x % 10;
			x /= 10;
		}
		if(w == 0) w = 1;
		return *this;
	}
	Bignum operator * (ll x){
		for(int i = 1; i <= w; i++){
			num[i] *= x;
		}
		for(int i = 1; i <= w; i++){
			if(num[i] > 9){
				num[i + 1] += num[i] / 10;
				num[i] %= 10;
				if(i == w) w++;
			}
		}
		return *this;
	}
	Bignum operator + (ll x){
		num[1] += x;
		for(int i = 1; i <= w; i++){
			if(num[i] > 9){
				num[i + 1] += num[i] / 10;
				num[i] %= 10;
				if(i == w) w++;
			}
		}
		return *this;
	}
	void print(){
		for(int i = w; i; i--) printf("%lld", num[i]);
		puts("");
	}
};
//bcj
/*
int F[MAXN];
int find(int x){
	if(F[x] == -1) return x;
	else return F[x] = find(F[x]);
} 
*/

int n,m,T; 
/* 
const int mod = 19260817;
int b[5000010];
int a[5000010];
int fhash(ll x){
	int st = x % mod; 
	if(b[st] == -1) return st;
    while(b[st] != x && a[st] != 0) st = (st + 1) % mod;
    return st;
}*/



/*
//int a[MAXN],temp[MAXN]; 
void mergesort(int l,int r)
{
    if(l==r) return ;
    int mid=(l+r)>>1;
    bin(l,mid);
    bin(mid+1,r);
    int i=l,j=mid+1,k=l;
    while(i<=mid && j<=r) 
    {
        if(a[i]<=a[j]) {
            temp[k]=a[i];
            k++,i++;
        }
        else 
        {
            temp[k]=a[j];
            k++,j++;
        }
    }
    
    while(i<=mid)
    {
        temp[k]=a[i];
        k++,i++;
    }
    while(j<=r)
    {
        temp[k]=a[j];
        k++,j++;
    }
    for(int i=l;i<=r;++i){
        a[i]=temp[i];
    }
}
*/ 
int a[1100000];
int main()
{
	scanf("%d",&n);
	ll sum = 0;
	for(int i = 1; i <= n; ++i){
		int x;
		scanf("%d",&x);
		++a[x];
		sum += x;
	}
	scanf("%d",&m);
	for(int i = 1; i <= m; ++i){
		int b,c;
		scanf("%d%d",&b,&c);
		ll s = a[b];
		a[b] = 0;
		a[c] += s;
		sum = sum - b*s;
		sum = sum + c*s;
		cout<<sum<<endl;
	}
	return 0;  
} 