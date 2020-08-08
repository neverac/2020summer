#include <bits/stdc++.h>

using namespace std;

char a[200];

void ac()
{
    int n;
    cin>>n;
    for(int i=0;i<200;i++) a[i]='a';
    printf("%s\n",a);
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(a[x]=='a')
            a[x]='b';
        else
        {
            a[x]='a';
        }
        
        printf("%s\n",a);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ac();
    }

    //system("pause");

    return 0;
}