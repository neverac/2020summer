#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
typedef long long LL;

LL a[3][100010];
LL f[100010][3]= {0};
int main(){
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)scanf("%lld",&a[1][i]);
	for(int i = 1;i <= n;i++)scanf("%lld",&a[2][i]);
	f[1][1] = a[1][1];
	f[1][2] = a[2][1];
	LL mx1 = f[1][1],mx2 = f[1][2];
	for(int i = 2;i <= n;i++){
		f[i][1] = mx2 + a[1][i];
		f[i][2] = mx1 + a[2][i];
		mx2 = max(mx2,f[i][2]);
		mx1 = max(mx1,f[i][1]);
	//	printf("%lld %lld _ \n",mx1,mx2);
	}
	printf("%lld\n",max(mx1,mx2));
	return 0;
}
 