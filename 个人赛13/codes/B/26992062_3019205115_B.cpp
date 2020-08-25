#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    double dst;
    double x,y,z;
    cin >>x >>y >>z;
    dst=x*x+y*y+z*z;
    n--;
    while(n--){
        cin >>x >>y >>z;
        dst=min(dst,x*x+y*y+z*z);
        /*if(dst>x*x+y*y+z*z){
            dst=x*x+y*y+z*z;
        }*/
    }
    dst=sqrt(dst);
    cout <<fixed<<setprecision(3)<<dst<<endl;
    return 0;
}