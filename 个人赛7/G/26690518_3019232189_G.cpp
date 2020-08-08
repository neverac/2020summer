#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <ctime>
#include <vector>
#include <cstdio>
#include <map>
#include <queue>
#define ll long long
#define N 1006
using namespace std;

int n,m,ans;
int a[1006][1006],num1[1006][1006],num2[1006][1006];

int main(){
    char cc;
    ans=1e9;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        cc=getchar();
        for(int j=1;j<=m;++j){
            cc=getchar();
            a[i][j]=cc-'0';
        }
    }

    /*for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j)
            printf("%d",a[i][j]);
        cout<<'\n';
    }*/

    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j){
            num1[i][j]=max(num1[i-1][j],num1[i][j-1]);
            num2[i][j]=max(num2[i-1][j],num2[i][j-1]);
            if(a[i][j]==1){
                num1[i][j]=i+j;
                if(num2[i][j])
                    ans=min(ans,i+j-num2[i][j]);
            }
            if(a[i][j]==2){
                num2[i][j]=i+j;
                if(num1[i][j])
                    ans=min(ans,i+j-num1[i][j]);
            }
        }
    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j){
            num1[i][j]=-1e9;
            num2[i][j]=-1e9;
        }
    for(int i=n;i>=1;--i)
        for(int j=1;j<=m;++j){
            num1[i][j]=max(num1[i+1][j],num1[i][j-1]);
            num2[i][j]=max(num2[i+1][j],num2[i][j-1]);
            if(a[i][j]==1){
                num1[i][j]=j-i;
                if(num2[i][j]!=-1e9)
                    ans=min(ans,j-i-num2[i][j]);
            }
            if(a[i][j]==2){
                num2[i][j]=j-i;
                if(num1[i][j]!=-1e9)
                    ans=min(ans,j-i-num1[i][j]);
            }
        }
    cout<<ans+1;
    //while(1);
}
