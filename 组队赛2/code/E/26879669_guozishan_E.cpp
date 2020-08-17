#include <iostream>
#include <cstdio>
using namespace std;
int rec[2005];

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        scanf("%d %d",&k, &n);
        if(n<2000)
        {
            cout<<1999<<endl;
            cout<<-1<<" ";
            //rec[1]  = -1;
            int temp = (1999+k)/1998;
            for(int i = 1; i <= 1997; i++)
            {
               cout<<temp<<" ";
               //rec[i+1] = 1;
            }
            cout<<1999+k-temp*1997<<endl;
            //rec[1999] = 2+k;
        }
        else
        {
            cout<<-1<<endl;
        }
        //cout<<"WA "<<WA(rec)<<endl;
        //cout<<"AC "<<AC(rec)<<endl;
    }
    return 0;
}
