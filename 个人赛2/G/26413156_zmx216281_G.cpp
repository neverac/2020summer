#include<cstdio>
#include<iostream>
int ans[100010]={};
using namespace std;
int main(){
    int n,k;
    while(scanf("%d %d",&n,&k)!=EOF){
        ans[1] = 1;
        int bis = -1;
        int diff = 1;
        for(int i=2;i<=k+1;i++){
            ans[i] = ans[i-1] + (n + bis)*diff;
            bis--;
            diff*=-1;
        }
        int temp = ans[k];
        if(k%2==0){
            for (int i=k+1;i<=n;i++)
            ans[i] = --temp;
        }
        else{
            for (int i=k+1;i<=n;i++)
            ans[i] = ++temp;
        }
        for(int i=1;i<=n;i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
 }
