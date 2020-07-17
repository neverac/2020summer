#include<bits/stdc++.h>
using namespace std;
int tmp,mx,ans[100050],t,n,pl[100050],f,tmpmx;
int main(){
	scanf("%d",&t);
	while(t --){
		memset(pl,0,sizeof pl);
		f = 1;
		scanf("%d",&n);
		tmp = 1;
		scanf("%d",&mx);
		ans[1] = mx;
		pl[mx] = 1;
		tmpmx = mx;
		if(mx == 1) tmp = 2;
		for(int i = 2;i <=n; ++ i){
			scanf("%d",&mx);
			if(mx > tmpmx){
				ans[i] = mx;
				if(pl[mx] == 0)
				    pl[mx] = 1;
				else{
					f = 0;
				}
			}else{
				while(pl[tmp]) tmp ++;
				if(tmp > n || tmp > mx){
					f = 0;
				}
				ans[i] = tmp;
				pl[tmp] = 1;
			}
			tmpmx = mx;
		}
		if(f == 0) printf("-1\n");
		else{
			for(int i = 1;i < n; ++ i){
				printf("%d ",ans[i]);
			}
			printf("%d\n",ans[n]);
		}
	}
    return 0;
}