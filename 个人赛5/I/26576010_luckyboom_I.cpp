#include<iostream>
#include<cmath>
#include<map>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int const maxn=3e5+10;
int ji[maxn],ou[maxn],tot1,tot2,len;
int t;
char s[maxn];
int main(){
    scanf("%d",&t);
    for(int q=1;q<=t;q++){
        scanf("%s",s);
        tot1=0;tot2=0;
        len=strlen(s);
        int num;
        for(int j=0;j<len;j++){
            num=s[j]-'0';
            if(num%2)ji[++tot1]=num;
            else ou[++tot2]=num;
        }
        int l1=1,l2=1;
        for(int i=0;i<len;i++){
            if(l1>tot1){
                printf("%d",ou[l2++]);
                continue;
            }
            if(l2>tot2){
                printf("%d",ji[l1++]);
                continue;
            }   
            if(ou[l2]<ji[l1]){
                printf("%d",ou[l2++]);
            }
            else{
                printf("%d",ji[l1++]);
            }
        }
        cout<<endl;
    }
 
    return 0;
}
/*
10 
100 150 300 400 500 200 150 300 100 50
100 20 10 30 40 50 60 70 80 90
*/