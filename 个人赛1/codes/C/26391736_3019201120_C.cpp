#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;
const int N=100010;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a[N];
        bool b[N];
        int c[N];
        bool d[N];
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) b[i]=false;
        for(int i=1;i<=n;i++) d[i]=false;
        int j=1;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(i==0||a[i]!=a[i-1])
            {
                c[i]=a[i];
                b[a[i]]=true;
            }
            else
            {
                while(b[j]==true)
                {
                    j++;
                }
                c[i]=min(j++,a[i]);
            }
        }
        for(int i=0;i<n;i++)
        {
            d[c[i]]=true;
        }
        int jdg=1;
        for(int i=1;i<=n;i++)
        {
            if(d[i]==false) jdg=0;
        }
        if(jdg==0) cout<<-1<<endl;
        else{
            for(int i=0;i<n;i++)
                cout<<c[i]<<' ';
            cout<<endl;
        }

    }

    return 0;
}
