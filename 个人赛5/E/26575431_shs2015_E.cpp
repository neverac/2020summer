#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int SIZEN = 200100;
int ch[SIZEN * 90][2];
int val[SIZEN * 90] = {0};
int node=1;
int now; 
int N;
int a[SIZEN] = {0};
int bit[SIZEN][30] = {0};
LL ans = 0;
void insert(int num){ 
    int u=0; 
    for(int i=29;i>=0;i--){ 
        int c=((num>>i)&1);
        if(!ch[u][c]){ 
            ch[u][c]=++node; 
        } 
        u=ch[u][c];
        val[u]++; 
    } 
} 
void Delete(int num)
{
    int u=0;
    for(int i=29;i>=0;i--)
    {
        int c=((num>>i)&1);
        int pre = u;
        u = ch[u][c];
        if(--val[u]==0) ch[pre][c]=0;
    }
}
   
int findmin(int num){ 
    int p=0,v=0;
    for(int i=29;i>=0;i--)
    {
        int c=((num>>i)&1);
        if(ch[p][c])p=ch[p][c];
        else
        {
            p=ch[p][c^1];
            v+=(1<<i);
        }
    }
    return v;
} 

int id[SIZEN] = {0};
void solve(int deep,int l,int r){
	if(deep == -1)return;
	int mid = 0;
	for(int i = l;i < r;i++){
		if(bit[ id[i] ][deep] != bit[ id[i+1] ][deep]){
			mid = i;
			break;
		}
	}
//	printf("deep = %d,l = %d,r = %d,mid = %d\n",deep,l,r,mid);
	if(!mid)solve(deep-1,l,r);
	else{
		solve(deep-1,l,mid);
		solve(deep-1,mid+1,r);
		for(int i = l;i <= mid;i++){
			insert(a[id[i]]);
		}
		LL tmpans = 0x3f3f3f3f3f3f3f3fLL;
		for(int i = mid+1;i <= r;i++)tmpans = min( 1LL*findmin(a[id[i]]),tmpans);
		ans += tmpans;
		node = 1;
		for(int i = l;i <= mid;i++){
			Delete(a[id[i]]);
		}
	}
}
bool Cmp(const int &A,const int &B){
	for(int i = 29;i >= 0;i--){
		if(bit[A][i] > bit[B][i])return 0;
		if(bit[A][i] < bit[B][i])return 1;
	}
	return 0;
}
int main(){
	scanf("%d",&N);
	for(int i = 1;i <= N;i++){
		scanf("%d",&a[i]);
		for(int j = 29;j >= 0;j--){
			bit[i][j] = ((a[i] >> j) & 1);
		}
		id[i] = i;
	}
	sort(id + 1,id + 1 + N,Cmp);
	//for(int i = 1;i <= N;i++)printf("%d ",a[id[i]]);printf("\n");
	solve(29,1,N);
	printf("%lld\n",ans);
	return 0;
}