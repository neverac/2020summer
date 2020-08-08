#include <bits/stdc++.h>
using namespace std;
char s[200005];
int qwq[15];
map<int,int> mp;

int main(){
    int t;scanf("%d",&t);
    while(t--){
        for(int i=0;i<=9;i++) qwq[i]=0;
        scanf("%s",s);
        int len=strlen(s);
        int cnt=0;
        int minn=200005;
        for(int i=0;i<len;i++) qwq[s[i]-'0']++;
        for(int i=0;i<=9;i++) minn=min(minn,len-qwq[i]);
        for(int i=0;i<=9;i++){
            for(int j=0;j<=9;j++){
                int cnt=0;
                int k=0;
                while(k<len){
                    while(s[k]!=i+'0'&&k<len) k++;
                    k++;
                    while(s[k]!=j+'0'&&k<len) k++;
                    if(k<len)cnt++;
                    k++;
                }
                //cout<<cnt<<endl;
                minn=min(minn,len-2*cnt);
            }
        }
        printf("%d\n",minn);
    }
    return 0;
}