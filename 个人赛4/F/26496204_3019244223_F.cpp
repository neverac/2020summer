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
using namespace std;
int main()
{  
    long long   k,n,s,p;
    cin>>k>>n>>s>>p;
    long double a=ceil(n*1.0/s);
    long double b=a*k*1.0;
    long long  c=ceil(b*1.0/p);
    cout<<c<<endl;

    

   
    





   // system("pause");
    return 0;
}