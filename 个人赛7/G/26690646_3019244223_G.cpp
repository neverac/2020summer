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
#include<map>
using namespace std;

struct Node 
{
    int x,y;
};
char s[1005][1005];

int main()
{  
    int n,m;
    cin>>n>>m;
    int num1=0;
    int num2=0;
    Node n1[1005];
    Node n2[1005];
    for(int i=0; i<n ; ++i)
    {
        for(int j=0 ; j<m ; ++j)
        {
            cin>>s[i][j];

            if(s[i][j]=='1')
            {
                n1[num1].x=i;
                n1[num1].y=j;
                num1++;
            }
            else if(s[i][j]=='2')
            {
                n2[num2].x=i;
                n2[num2].y=j;
                num2++;
            }
        }
    }
    int minn=5000;
    for(int i=0;i<num1;++i)
    {
        for(int j=0;j<num2;++j)
        {
            minn=min(minn , (abs(n1[i].x-n2[j].x) + abs(n1[i].y-n2[j].y)+1 )); 
        }
    }
    cout<<minn<<endl;



    //system("pause");
    return 0;
}

