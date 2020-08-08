#include <iostream>
#include <cstring>
using namespace std;
char rec[105];
int num[105];

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(rec,0,sizeof(rec));
        int n;
        cin>>n;
        int Max = 0;
        for(int i = 0; i < n; i++)
        {
            cin>>num[i];
            if(num[i] > Max)
            {
                Max = num[i];
            }
        }
        if(Max == 0)
        {
            Max = 3;
        }
        for(int i = 0; i < Max; i ++)
            {
                rec[i]  = 'a';
            }
        for(int i = 0; i < Max ;i ++)
        {
            cout<<'a';
        }
        cout<<endl;
        for(int i = 0; i < n; i++)
        {
            //cout<<rec[temp]<<endl;
            if(rec[num[i]]== 'a')
            {
                rec[num[i]] = 'b';
            }else
            {
                rec[num[i]] = 'a';
            }
            for(int j = 0 ;j < Max ;j++)
            {
                cout<<rec[j];
            }
            cout<<endl;
        }
    }
    return 0;
}
