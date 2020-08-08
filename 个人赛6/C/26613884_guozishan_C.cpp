#include <iostream>
#define maxn 200005
using namespace std;

int rec[maxn];

int findRoot(int num)
{
    if(rec[num] == num)
    {
        return num;
    }else{
        return rec[num]=findRoot(rec[num]);
    }
}

int main()
{
    for(int i =0; i < maxn; i++)
    {
        rec[i] = i;
    }
    int n,k;
    cin>>n>>k;
    int x,y,res = 0;
    for(int i =0 ;i < k; i++){
        cin>>x>>y;
        x = findRoot(x);
        y = findRoot(y);
        //cout<<"x"<<x<<"y"<<y<<endl;
        if(x == y)
        {
            res++;
        }
        else
        {
            rec[x] = y;
           // cout<<"rec[x]"<<rec[x]<<endl;
        }
    }
    cout<<res<<endl;
    return 0;
}
