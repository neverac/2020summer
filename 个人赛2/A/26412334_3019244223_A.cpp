#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<string.h>
using namespace std;
int n,m;
int maxroom=0;
int sum=0;
int room;
int a[55][55];
int book[55][55];
void dfs(int i,int j)
{
    if(book[i][j])
        return ;
    if(i<1||i>n||j<1||j>m)
        return ;
    room++;
    book[i][j]=sum;
    if((a[i][j]&1)==0) 
        dfs(i,j-1);
    if((a[i][j]&2)==0) 
        dfs(i-1,j);
    if((a[i][j]&4)==0) 
        dfs(i,j+1);
    if((a[i][j]&8)==0) 
        dfs(i+1,j);
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
            cin>>a[i][j];
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(book[i][j]==0)
            {
                sum++;
                room=0;
                dfs(i,j);
                maxroom=max(maxroom,room);
            }
        }
    }
    cout<<sum<<endl;
    cout<<maxroom<<endl;

    system("pause");
    return 0;
}