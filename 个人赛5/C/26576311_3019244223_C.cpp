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
int main()
{  
    int n;
    cin>>n;
    long long x[400];
    long long ans=100;
    for(int i=1;i<=n;++i)
        cin>>x[i];
    x[0]=100;
    for (int i=1; i<n; i++) 
    {
        int j=i+1;
        while (j<=n && x[j]>=x[j-1]) 
            j++;
        j--;
        if (i!=j) 
        {
            ans=ans+(min(ans/x[i],(long long)100000))*(x[j]-x[i]);
            i=j;
        }
    }
    cout<<ans<<endl;

   
    //system("pause");
    return 0;
}