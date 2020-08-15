#include <bits/stdc++.h>
using namespace std;
const int N = 4040;
int autoa[N][2],autob[N][2],f[N][N],w[N][N];
char p[N],q[N];
int cnt,len1,len2,ans[N];
int func(int x,int y){
	if(x == len1+1 && y == len2+1) return 0;
	if(f[x][y]) return f[x][y];
	int s1 = func(autoa[x][0], autob[y][0]);
	int s2 = func(autoa[x][1], autob[y][1]);
	if(s1 > s2) w[x][y] = 1; 
	else w[x][y] = -1;
	int k = min(s1,s2);
	return f[x][y] = k+1;
}
void save(int x, int y) {
    if (x == len1+1 && y == len2+1) return;
    int k = w[x][y] > 0;
    ans[++cnt] = k;
    save(autoa[x][k], autob[y][k]);
}
int main()
{
	scanf("%s%s",p+1,q+1);
	len1 = strlen(p+1);
	len2 = strlen(q+1);
	autoa[len1+1][1] = len1+1;
	autoa[len1+1][0] = len1+1;
    autob[len2+1][1] = len2+1;
	autob[len2+1][0] = len2+1;
    for (int i = len1; i >= 0; --i) {
        autoa[i][1] = autoa[i+1][1];
        autoa[i][0] = autoa[i+1][0];
        if (p[i+1] == '1') autoa[i][1] = i+1;
        else autoa[i][0] = i+1;
    }
	for (int i = len2; i >= 0; --i) {
        autob[i][1] = autob[i+1][1];
        autob[i][0] = autob[i+1][0];
        if (q[i+1] == '1') autob[i][1] = i+1;
        else autob[i][0] = i+1;
    }
    func(0,0);
    save(0,0);
    for(int i = 1; i <= cnt; ++i) printf("%d",ans[i]);
	return 0;
}
