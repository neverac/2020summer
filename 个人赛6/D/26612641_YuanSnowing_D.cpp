#include<bits/stdc++.h>
using namespace std;
int n,q,c,x,y,s,f[150][150][15];
int t,x1,y11,x2,y2;

int cont(int x,int y,int t){
	int sum=0;
	for(int i=0;i<=c; ++i){
		sum += f[x][y][i]*((i+t)%(c+1));
	}
	return sum;
}
int main(){
    cin >> n >> q >> c;
    for(int i=0;i < n; ++ i){
    	cin >> x >> y >> s;
    	f[x][y][s] ++;
    }
    for(int ss=0;ss<=c; ++ ss){
	    for(int i=1;i<=100;++ i){
	    	for(int j=1;j<=100;++ j){
	    		f[i][j][ss] += f[i-1][j][ss]+f[i][j-1][ss];
	    		f[i][j][ss] -= f[i-1][j-1][ss];
	    	}
	    }
	}
    while(q --){
    	cin >> t >> x1 >> y11 >> x2 >> y2;
    	x1 --;
    	y11 --;
    	printf("%d\n",cont(x2,y2,t)-cont(x1,y2,t)-cont(x2,y11,t)+cont(x1,y11,t));
    }
    return 0;
}