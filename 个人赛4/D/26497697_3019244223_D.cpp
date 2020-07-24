#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
int gcd(int a,int b)//a<b
{
	return b?gcd(b,a%b):a;
}
int main()
{  
    int t;
    cin>>t;
    for(int i=1;i<=t;++i)
    {
        int n;
        int a,b;
        scanf("%d%d%d",&n,&a,&b);
        if(a>b)
        {
            int aa=a;
            a=b;
            b=aa;
        }
        int c=gcd(a,b);
        int ans=n/c;
        if(ans%2==0)
            cout<<"Case #"<<i<<": Iaka"<<endl;
        else 
            cout<<"Case #"<<i<<": Yuwgna"<<endl;
    }





    //system("pause");
    return 0;
}