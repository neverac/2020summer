#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
struct node{
    int id;
    int price;
    bool operator < (const node &n) const
    {
        return n.price < price;
    }
};
priority_queue<node> q[3];
int vis[200005];
node rec[200005];
int main()
{
    int c;
    cin>>c;
    for(int i = 1; i <= c; i++)
    {
        cin>>rec[i].price;
    }
    for(int i = 1; i <= c; i++)
    {
        rec[i].id = i;
    }
    for(int i = 1; i <= c; i++)
    {
        int temp;
        cin>>temp;
        q[temp-1].push(rec[i]);
    }

    for(int i = 1; i <= c; i++)
    {
        int temp;
        cin>>temp;
        q[temp-1].push(rec[i]);
    }
    memset(vis,0,sizeof(vis));
    int m;
    cin>>m;
    for(int i = 1; i <= m ; i++)
    {
        int temp;
        cin>>temp;
        bool flag = false;
        while(!q[temp-1].empty())
        {
            node p = q[temp-1].top();
            q[temp-1].pop();
            if(vis[p.id])
            {
                continue;
            }else
            {
                cout<<p.price<<" ";
                vis[p.id] = 1;
                flag = true;
                break;
            }
        }
        if(!flag)
        {
            cout<<-1<<" ";
        }
    }
    cout<<endl;
    return 0;
}
