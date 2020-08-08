#include <bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
char arr[maxn];
int ji[maxn],ou[maxn];
int sji,sou;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        sji=0;
        sou=0;
        scanf("%s",arr);
        int n=strlen(arr);
        for(int i=0;i<n;++i){
            if((arr[i]-'0')%2==0)ou[sou++]=arr[i]-'0';
            else ji[sji++]=arr[i]-'0';
        }
        int jiidx=0,ouidx=0;
        while(jiidx<sji&&ouidx<sou){
            while(ouidx<sou&&ji[jiidx]>ou[ouidx])printf("%d",ou[ouidx++]);
            while(jiidx<sji&&ji[jiidx]<ou[ouidx])printf("%d",ji[jiidx++]);
        }
        while(jiidx<sji)printf("%d",ji[jiidx++]);
        while(ouidx<sou)printf("%d",ou[ouidx++]);
        printf("\n");
    }
}
