#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int rec[370];
int main()
{
    int n;
    cin>>n;
    for(int i = 0; i < n; i ++)
    {
        cin>>rec[i];
    }
    int Min= 360,sum=0;
    for(int i = 0; i < n ;i ++)
    {
        sum = 0;
        for(int j = i; j <n; j++ )
        {
            sum += rec[j];
            Min = min(Min,abs(360-2*sum));
        }
    }
    cout<<Min<<endl;
    return 0;
}
