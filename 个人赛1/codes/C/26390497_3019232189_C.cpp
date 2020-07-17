#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#define N 100006
#define ll long long
#define dd double
#define esp 1e-10
using namespace std;

int T,n,k;
int a[N],ans[N],ind[N];
bool fla;

int main(){
	int tt;
	scanf("%d",&T);
	while(T--){
		memset(ind,-1,sizeof(ind));
		memset(ans,-1,sizeof(ans));
		fla=1;
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			if(ind[a[i]]==-1)
				ind[a[i]]=i;
		}
		for(int i=1;i<=n;++i)
			if(ind[i]!=-1)
				ans[ind[i]]=i;
		tt=1;
		for(int i=1;i<=n;++i)
			if(ind[i]==-1){
				while(ans[tt]!=-1&&tt<=n)
					++tt;
				if(ans[tt]==-1)
					ans[tt]=i;
				if(i>a[tt])
					fla=0;
			}
		if(!fla)
			printf("-1\n");
		else{
			for(int i=1;i<=n;++i)
				printf("%d ",ans[i]);
			cout<<endl;
		}
	}
}