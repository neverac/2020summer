#include <iostream>
#include <string.h>
#include <vector>
#include <cmath>
using namespace std;


int main()
{   int n,a;
    cin>>n;
    int cont1=0,cont2=0,sum=0;
    vector<int> lis;

    for(int i=0;i<n;i++){
        cin>>a;
        if(a==1){
            cont1++;
            sum++;
        }
        else {
            cont2++;
            sum+=2;
        }
    }
    /*bool sx[200007];
    for(int i=0;i<=sum;i++){
        sx[2i]==false;
        sx[2i+1]==true;
    }
    for(int i=0;i<=sqrt(sum);i++){
        if(sx[i]){
            for(int j=i+i;j<=n;j=j+i){
                sx[j]=false;
            }
        }
    }
    for(int i=2;i<=sum;i++){
        if(sx[i]){
            lis.push_back(i);
        }
    }*/
    if(cont2>0){
        cout<<2<<" ";
        cont2--;
    }
    if(cont1>0){
        cout<<1<<" ";
        cont1--;
    }
    while(cont2--){
        cout<<2<<" ";
    }
    while(cont1--){
        cout<<1<<" ";
    }
    return 0;
}
