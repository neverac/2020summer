#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const int SIZEN = 200010;
LL L[SIZEN],R[SIZEN];
int N;
LL S;
int tmp[SIZEN] = {0};
int id[SIZEN] = {0};
bool Cmp(const int &A,const int &B){
	return L[A] < L[B];
}
bool check(LL x){
	LL ret = 0;
	int left = 0;
	int right = 0;
	int both = 0;
	for(int i = 1;i <= N;i++){
		if(L[id[i]] <= x && x <= R[id[i]]){
			tmp[++both] = id[i];
		}
		else if(x < L[id[i]]){
			right++;
			ret += L[id[i]];
		}
		else if(x > R[id[i]]){
			left++;
			ret += L[id[i]];
		}
	}
	if(left + both < N/2 || right + both < (N+1)/2)return false;
	//printf("------------------------- > %d %d %d %lld %lld\n",left,right,both,x,ret); 
	int cnt = 0;
	for(int i = left+1;i <= N/2;i++){
		ret += L[tmp[++cnt]];
		//printf("--(%d,%d)\n",L[tmp[cnt]],R[tmp[cnt]]);
	}
	//printf("ret = %lld\n",ret);
	ret += x * (both - cnt);
	return ret <= S;
}
bool Cmp1(const int &A,const int &B){
	return R[A] < R[B];
}
void work(){
	scanf("%d%lld",&N,&S);
	LL l = S,r = 0,mid,ans = 0;
	for(int i = 1;i <= N;i++){
		scanf("%lld%lld",&L[i],&R[i]);
	}
	for(int i = 1;i <= N;i++)tmp[i] = i,id[i] = i;
	sort(tmp+1,tmp+1+N,Cmp1);
	r = R[tmp[N/2+1]]; 
	sort(tmp + 1,tmp + 1 + N,Cmp); 
	sort(id + 1,id + 1 + N,Cmp);
	l = L[tmp[N/2+1]];
	
	//printf("debug = %d\n",debug);
	while(l <= r){
		mid = ((l+r)>>1);
		//printf("l = %d,r = %d\n",l,r);
		if(check(mid))l = mid + 1,ans = mid;
		else r = mid - 1;
	}
	printf("%lld\n",ans);
} 
int main(){
	int T;scanf("%d",&T);
	while(T--)work(); 
	return 0;
} 
/*
1
19 1175
44 87
68 100
93 98
76 79
10 58
74 99
87 97
23 75
62 73
100 100
71 76
73 87
76 82
44 84
54 90
2 82
67 99
85 97
66 88

*/