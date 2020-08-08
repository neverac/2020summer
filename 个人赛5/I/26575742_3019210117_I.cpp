#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
char a[300005];
vector<int>ous,jis;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        ous.clear();
        jis.clear();
        scanf("%s",a+1);
        int len=strlen(a+1);
        for(int i=1;i<=len;i++){
            if((a[i]-'0')%2==0){
                ous.push_back(a[i]-'0');
            }else{
                jis.push_back(a[i]-'0');
            }
        }
        int len0=ous.size(),len1=jis.size();
        int cnt0=0,cnt1=0;
        while(cnt0<len0&&cnt1<len1){
            if(ous[cnt0]>jis[cnt1]){
                printf("%d",jis[cnt1++]);
            }else{
                printf("%d",ous[cnt0++]);
            }
        }
        for(int i=cnt0;i<len0;i++){
            printf("%d",ous[i]);
        }
        for(int i=cnt1;i<len1;i++){
            printf("%d",jis[i]);
        }
        printf("\n");
    }
    return 0;
}