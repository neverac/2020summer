#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#define LL long long
#define INF 0x7fffffffffffffff
using namespace std;
LL num;
int len;
char s[50];


int main(){
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
    int t;
    cin >> t;
    for (int ccc = 1;ccc<=t;ccc++){
        num = -INF;
        scanf("%s",s+1);

        len = strlen(s + 1);
        for (int i=2; i <= len - 3; i++){
            LL maxx = 0,a = 0,b = 0;
            for (int j=1;j<=i-1;j++){
                a = b = 0;
                for (int k = 1;k<=j;k++)  a = a*10+s[k]-'0';
                for (int k = j+1;k<=i;k++) b = b*10+s[k]-'0';
//                for (int k = j+2;k<=1+i;k++) b = b*10+s[k]-'0';
                if (a+b>maxx) maxx = a+b;
            }
            string s2 = s;
            s2[1] = s[len-1];
            int cnt = 0;
            for (int pp = 0;pp<1;pp++)
                cnt++;
            LL c = 0;
            a = s[i+1] - '0';
            b = s[i+2] - '0';

            for (int j = i+3; j <= len; j++) c = c*10+s[j]-'0';
            if (maxx-a*b/c > num) num = maxx-a*b/c;
//            for (int j = i+3; j <= len; j++) c = c*10+s[j]-'0';
//            if (maxx-a*b/c > num) num = maxx-a*b/c;
        }
        printf("Case #%d: %lld\n", ccc, num);
    }
}