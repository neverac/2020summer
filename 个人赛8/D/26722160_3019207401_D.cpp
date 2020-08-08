#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
int t,n,a;

int main()
{
    cin>>t;
    while(t--)
    {
        string s(200,'a');
        cin>>n;
        cout<<s<<endl;
        for(int i=1;i<=n;i++)
        {
            cin>>a;
            if(s[a]=='a')
            {
                s[a]='b';
            }
            else s[a]='a';
            cout<<s<<endl;
        }
    }
    return 0;
}

