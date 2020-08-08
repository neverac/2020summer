#include <iostream>

using namespace std;
int rec[100005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        long long sum = 0,Max = -1,temp = 0;
        for(int i = 1; i <= n; i++)
        {
            cin>>rec[i];
            sum += rec[i];
        }
        for(int i = 1; i <= n-1; i ++)
        {
            temp += rec[i];
            if(temp < rec[i])
            {
                temp = rec[i];
            }
            if(temp > Max)
            {
                Max = temp;
            }
        }
        temp = 0;
        for(int i = 2; i <= n; i ++)
        {
            temp += rec[i];
            if(temp < rec[i])
            {
                temp = rec[i];
            }
            if(temp > Max)
            {
                Max = temp;
            }
        }
        //cout<<sum<<endl;
        //cout<<Max<<endl;
        if(sum > Max)
        {
            cout<<"YES"<<endl;
        }else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
