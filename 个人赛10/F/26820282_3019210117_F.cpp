#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int sol(vector<int>&lis,int w){
    if(lis.size()==0||w<0){
        return 0;
    }
    vector<int>zer(0),yiz(0);
    int che=(1<<w);
    for(int i=0;i<lis.size();i++){
        if(lis[i]&che){
            yiz.push_back(lis[i]);
        }else{
            zer.push_back(lis[i]);
        }
    }
    if(yiz.size()==0){
        return sol(zer,w-1);
    }
    if(zer.size()==0){
        return sol(yiz,w-1);
    }
    return min(sol(yiz,w-1),sol(zer,w-1))+che;
}
int main(){
    //freopen("in.txt","r",stdin);
    int n;
    scanf("%d",&n);
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("%d",sol(arr,31));
    return 0; 
}