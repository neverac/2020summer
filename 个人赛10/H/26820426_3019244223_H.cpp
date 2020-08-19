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
#include<set>
using namespace std;
#define ll  long long
#define ull unsigned long long


int main()
{  
    int n;
    cin>>n;
    int x[400];
    for(int i=0;i<n;++i)
        cin>>x[i];
    int minn=360;
    int tmp;
    for(int i=0;i<n;++i)
    {
        tmp=0;
        int j=i;
        while(tmp<180)
        {
            j=j%n;
            tmp+=x[j];
            minn=min(minn,2*abs(180-tmp));
            j++;
        }
    }
    cout<<minn<<endl;






    //system("pause");
    return 0;
}

