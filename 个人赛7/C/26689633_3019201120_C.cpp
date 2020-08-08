#include <bits/stdc++.h>

using namespace std;
const int N=110;

int q[N],tt=-1,hd;
int que[N],t=-1,head;

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        q[++tt]=x;
    }
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        que[++t]=x;
        //cout<<"q"<<t<<' '<<que[t]<<endl;
    }
    //int i=0;
    while((head<n)&&(hd<n))
    {
        
        if(que[head]>q[hd]) {
            hd++;
        }
        else if(que[head]<q[hd]) {
            head++;
        }
    }
    cout<<t-head+1+tt-hd+1<<endl;
    
    system("pause");
    return 0;
}