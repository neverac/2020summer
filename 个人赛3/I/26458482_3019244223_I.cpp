#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<string.h>
#include<set>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string x;
    cin>>x;
    int a[3]={0};
    for(int i=0;i<n;++i)
    {
        if(x[i]=='-')
            a[0]++;
        else 
            a[1]++;
    }

        int maxx=0;
        int num=0;
        for(int i=0;i<n;++i)
        {
            if(x[i]=='-')
            {
                num++;
                maxx=max(num,maxx);
            }
            else
            {
                num--;
            }
            
        }
        cout<<maxx+a[1]-a[0]<<endl;
    
    


    //system("pause");
    return 0;
}