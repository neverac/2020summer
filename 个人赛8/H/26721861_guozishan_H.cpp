#include <iostream>

using namespace std;

int rec[200005], no[200005], yes[200005];

int main()
{
    int n;
    cin>>n;
    for(int i = 1; i <= n; i ++)
    {
        cin>>rec[i];
    }
    int Max = 0;
    no[1] = 1;
    for(int i = 2 ; i <= n; i ++)
    {
        if(rec[i] > rec[i-1])
        {
            no[i] = no[i-1] + 1;
        }else
        {
            no[i] = 1;
        }
        if(no[i] > Max)
        {
            Max = no[i];
        }
    }
    yes[n] = 1;
    for(int i = n-1; i >= 1; i-- )
    {
        if(rec[i+1] > rec[i])
        {
            yes[i] = yes[i+1]+1;
        }else
        {
            yes[i] = 1;
        }
        if(yes[i] > Max)
        {
            Max = yes[i];
        }
    }

    //for(int i = 1; i <= n; i ++)
    //{
       // cout<<no[i]<<" "<<yes[i]<<endl;
    //}

    for(int i = 2; i <= n -1; i++)
    {
        if(rec[i-1] < rec[i+1])
        {
            if(no[i-1] + yes[i+1] > Max)
            {
                Max = no[i-1] + yes[i+1];
            }
        }
    }
    cout<<Max<<endl;
    return 0;
}
