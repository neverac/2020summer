#include <iostream>
#include <bits/stdc++.h>

using namespace std;
/*
int n;
char s0[11],str[11];
bool judge[1000];
int main()
{
    scanf("%d",&n);
    scanf("%s",s0);
    int l0=strlen(s0);
    for(int i=0;i<n;i++){
        bool cmp=true;
        scanf("%s",str);
        int l=strlen(str);
        int ml=min(l,l0);
        for(int j=0;j<ml;j++){
            if(str[j]>'9'){
                if(str[j]<s0[j]){
                    judge[i]=false;cmp=false;break;
                }
                else if(str[j]>s0[j]){
                    judge[i]=true;cmp=false;break;
                }
            }
            else{
                if(s0[j]<='9'){
                    int t=j;
                    while(s0[t]<='9' && t<l0){
                        t++;
                    }
                    int h=t;
                    t--;
                    int temp=0;
                    int num1=0,num2=0;
                    while(t>=j){
                        num1+=(s0[t--]-'0')*pow(10,temp++);
                    }
                    t=j;
                    while(str[t]<='9' && t<l){
                        t++;
                    }
                    t--;temp=0;
                    while(t>=j){
                        num2+=(str[t--]-'0')*pow(10,temp++);
                    }
                    if(num1>num2){
                        judge[i]=false;cmp=false;break;
                    }
                    else if(num1<num2){
                        judge[i]=true;cmp=false;break;
                    }
                    j=h;
                }
                else{
                    judge[i]=false;cmp=false;break;
                }
            }
        }
        if(cmp){
            judge[i]=(l>=l0);
        }
    }
    for(int i=0;i<n;i++){
        if(judge[i]){
            printf("+\n");
        }
        else{
            printf("-\n");
        }
    }
    return 0;
}
*/

#include<cassert>
#include<string>
#include<cmath>
#include<cstring>
#include<stack>
#include<iostream>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
#include<cstdlib>
#pragma warning(disable:4996)
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f
#define itn int
#define ll long long
#define mes(a,k) memset(a,k,sizeof(a))
#define max(a,b) a>b?a:b
//#define min(a,b) a<b?a:b
//#define pb(a) push_back(a)
#define eps 1e-9
#define PI acos(-1)
using namespace std;
const int N = 2e5 + 5;
const ll mod = 998244353;
ll a[5020], dp[5020][5020];
void io() { ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); }

int main() {
	io();
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + T + 1);
	for (int i = 1; i <= T; i++) {
		for (int j = 1; j <= T; j++) {
			dp[i][j] = 2;//初始化
		}
	}
	int maxx = 2;//小心2，刚开始写的-inf错了很憨憨好吧
	for (int i = 2; i <= T - 1; i++) {
		int l = i - 1, r = i + 1;
		while (l >= 1 && r <= T) {
			if (a[l] + a[r] == a[i] * 2) {
				dp[i][r] = dp[l][i] + 1;
				maxx = max(maxx, dp[i][r]);
				l--;
				r++;
			}
			else if (a[l] + a[r] < a[i] * 2) {
				r++;
			}
			else {
				l--;
			}
		}
	}
	cout << maxx << endl;
	return 0;
}
