#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
const int SIZEN = 1010;
char str[20];
char s[20];
LL s0[20],cnt = 0;
LL s1[20],tot = 0;
int N;
bool Isdigit(char c){
 
    return c<='9' && c >= '0';
}
bool Check(){
    int mn = min(cnt,tot);
    for(int i = 1;i <= mn;i++){
        if(s1[i] < s0[i])return true;
        if(s1[i] > s0[i])return false;
    }
    if(cnt == tot)return false;
    return mn == tot;
}
int main(){
    scanf("%d",&N);
    scanf("%s",str+1);
    int len = strlen(str+1);
    for(int i = 1;i <= len;i++){
        if(!Isdigit(str[i]))s0[++cnt] = 1LL*str[i] * 1000000000;
        else{
            LL t = 0;
            while(Isdigit(str[i]) && i <= len){
                t = t * 10 + str[i] - 48;
                i++;
            }
            i--;
            s0[++cnt] = t;
        }
    }
    for(int i = 1;i <= N;i++){
        scanf("%s",str+1);
        len = strlen(str+1);
        tot = 0;
        for(int j = 1;j <= len;j++){
            if(!Isdigit(str[j]))s1[++tot] = 1LL*str[j] * 1000000000;
            else{
                LL t = 0;
                while(Isdigit(str[j]) && j <= len){
                    t = t * 10 + str[j] - 48;
                    j++;
                }
                j--;
                s1[++tot] = t;
            }
        }
        if(Check())puts("-");
        else puts("+");
    }
    return 0;
}