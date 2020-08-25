#include<bits/stdc++.h>
using namespace std;
int N;
int mn;
int main(){
	scanf("%d",&N);
	mn = 3* 1000*1000;
	for (int i=1; i<=N; i++){
		int x,y,z; scanf("%d%d%d",&x,&y,&z);
		mn = min(mn, x*x+y*y+z*z);
	}
	printf("%.3lf\n",(double)sqrt(1.0*mn));
	return 0;
}