#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
int T;
double x1,x2,x3,y11,y2,y3,a,ans,tmp,k,b;
int main(){
	cin >> T;
	while(T --){
		cin >> x1 >> y11 >> x2 >> y2 >> x3 >> y3;
		a = (y2-y11)/((x2-x1)*(x2-x1));
		k =(y2-y3)/(x2-x3);
		b = y2-k*x2;
		ans = a*x3*x3*x3/3.0-(a*x1+k/2.0)*x3*x3+(a*x1*x1+y11-b)*x3 - (a*x2*x2*x2/3.0-(a*x1+k/2.0)*x2*x2+(a*x1*x1+y11-b)*x2);
		printf("%.2lf\n",ans);
	}
    return 0;
}