#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
const int SIZEN = 200010;
int a[SIZEN];
struct Hero{
	int p,s;
	Hero(){;}
	Hero(int p,int s){
		this->p = p;
		this->s = s;
	}
	bool operator < (const Hero &A)const{
		return s < A.s;
	}
}h[SIZEN],tt[SIZEN];
int N,M,cnt = 0;
int mx[SIZEN << 2];
int get_max(int rt,int l,int r,int x,int y){
	if(x <= l && y >= r)return mx[rt];
	int mid = (l+r)>>1;
	if(y <= mid)return get_max(rt<<1,l,mid,x,y);
	if(x >  mid)return get_max(rt<<1|1,mid+1,r,x,y);
	return max(get_max(rt<<1,l,mid,x,y),get_max(rt<<1|1,mid+1,r,x,y));
}
void build(int rt,int l,int r){
	if(l == r){
		mx[rt] = a[l];
		return;
	}
	int mid = (l+r)>>1;
	build(rt<<1,l,mid);build(rt<<1|1,mid+1,r);
	mx[rt] = max(mx[rt<<1],mx[rt<<1|1]);
}
bool Cmp(const Hero &A,const Hero &B){
	if(B.p!=A.p)return A.p > B.p;
	return A.s > B.s;
}
bool Check(int loc,int len){
	Hero t = Hero(0,len);
	int locc = lower_bound(h+1,h+1+M,t) - h;
	// printf("loc = %d,len = %d,l = %d,r = %d\n",loc,loc+len-1);
	int mx = get_max(1,1,N,loc,loc+len-1);
	
	// printf("len = %d,locc = %d,mx = %d\n",len,locc,mx);
	if(locc <= M && h[locc].p >= mx)return true;
	return false;
}
void work(){
    scanf("%d",&N);
    for(int i = 1;i <= N;i++)scanf("%d",&a[i]);
	build(1,1,N);
    scanf("%d",&M);
    for(int i = 1;i <= M;i++)scanf("%d%d",&h[i].p,&h[i].s);
	sort(h+1,h+1+M,Cmp);
	cnt = 0;
	tt[++cnt] = h[1];
	for(int i = 2;i <= M;i++){
		if(h[i].s <= tt[cnt].s)continue;
		tt[++cnt] = h[i];
	}
	for(int i = 1;i <= cnt;i++)h[i] = tt[i];
	M = cnt;
	// for(int i = 1;i <= M;i++){
	// 	printf("p[%d] = %d,s[%d] = %d\n",i,h[i].p,i,h[i].s);
	// }
    int l,r,mid,ans = 0;
    for(int i = 1,tmp;i <= N;i+=tmp){
        l = 1;r = N-i+1;
        tmp = 0;
        while(l <= r){
            mid = (l+r)>>1;
            if(Check(i,mid))l = mid+1,tmp = mid;
            else r = mid-1;
        }
		if(tmp == 0){
			puts("-1");
			return;
		}
		// printf("i = %d,tmp = %d\n",i,tmp);
		ans++;
    }
    printf("%d\n",ans);
}
int main(){
    int T;scanf("%d",&T);
    while(T--)work();
    return 0;
}
/*
1
6
2 3 11 14 1 8
2
3 2
100 1
*/