#include<iostream>
#include<cmath>
#include<map>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int const maxn=2e5+10;
int ans[maxn],len,tot;
int t;
char s[maxn];
void work(){
    if(len<3){
        return ;
    }
    for(int i=0;i<len-2;i++){
       // cout<<"test: "<<s[i]<<endl;
        if(s[i]=='t'&&s[i+1]=='w'&&s[i+2]=='o'){
            if(i+4<len&&s[i+3]=='n'&&s[i+4]=='e')ans[++tot]=i+2;
            else{
                ans[++tot]=i+1;
            }
            continue;
        }
        if(s[i]=='o'&&s[i+1]=='n'&&s[i+2]=='e'){
            if(ans[tot]!=i){
                ans[++tot]=i+1;
            }
            continue;
        }
    }
}
void print(){
    printf("%d\n",tot);
    for(int i=1;i<=tot;i++)printf("%d ",ans[i]+1);
    cout<<endl;
}
int main(){
    scanf("%d",&t);
    for(int q=1;q<=t;q++){
        scanf("%s",s);
        len=strlen(s);
        tot=0;
        ans[0]=-1;
        work();
        print();   
    }
    return 0;
}
/*
*/