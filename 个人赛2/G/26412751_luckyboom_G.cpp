#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int const maxn=1e5+7;
int n,k,a[maxn];
void work(){
	a[1]=1;
	int q=1,u=k,i;
	for(i=2;i<=n;i++){
		a[i]=a[i-1]+q*u;
		u--;
		q*=-1;
		if(u==0){
			break;
		}
	}
	i++;
	for(int gg=1+k+1;i<=n;i++,gg++){
		a[i]=gg;
	}
}
int main(){
	scanf("%d%d",&n,&k);
	work();
	for(int i=1;i<n;i++)printf("%d ",a[i]);
		cout<<a[n]<<endl;
	return 0;
}