#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<string.h>
#include<time.h>
#include<queue>
#include<stack>
using namespace std;
int x[100005];
int main()
{  
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;++i)
        cin>>x[i];
    int sum=0;
    int pos=0;
    while(pos<n)
    {
        if(x[pos]>k)
            x[pos]=x[pos]-k;
        else 
            pos++;
        if(x[pos]>k)
            x[pos]=x[pos]-k;
        else 
            pos++;
        sum++;
    }
    cout<<sum<<endl;
    
    


    
    
    //system("pause");
    return 0;
}

