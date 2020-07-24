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
    string n;
    cin>>n;
    long long a=n.size();
    if(a>1)
    {
        int b;
        char c,d;
        c=n.at(a-2);
        d=n.at(a-1);
        b=10*(c-'0')+(d-'0');
        if(b==0||b%4==0)
            cout<<4<<endl;
        else 
            cout<<0<<endl;
    }
    else
    {
        char c=n[0];
        int d=c-'0';
        if(d%4==0)
            cout<<4<<endl;
        else
            cout<<0<<endl;
    }
    

   
    





    //system("pause");
    return 0;
}