#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        double q,w,a,s,z,x;
        cin>>q>>w>>a>>s>>z>>x;
        double S;
        S=-(s-w)/6/(a-q)/(a-q)*(z-a)*(z-a)*(z-a);
        cout<<fixed<<setprecision(2)<<S<<endl;
    }
    system("pause");
    return 0;
}