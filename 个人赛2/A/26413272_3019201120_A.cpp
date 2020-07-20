#include <iostream>

using namespace std;

const int N=60;

int room[N][N];
bool room2[N][N];
int num;
int maxare;
int are;

void dfs(int i,int j)
{
    if(room2[i][j]==false) return ;
    are++;
    room2[i][j]=false;
    if((room[i][j]&1)==0) dfs(i,j-1);
    if((room[i][j]&2)==0) dfs(i-1,j);
    if((room[i][j]&4)==0) dfs(i,j+1);
    if((room[i][j]&8)==0) dfs(i+1,j);
}
int main()
{
    int a,b;
    cin>>a>>b;
    for(int i=1;i<=a;i++)
        for(int j=1;j<=b;j++)
        {
            cin>>room[i][j];
            room2[i][j]=true;
        }
    for(int i=1;i<=a;i++)
        for(int j=1;j<=b;j++)
        {
            if(room2[i][j]==true)
            {
                num++;
                are=0;
                dfs(i,j);
                maxare=max(maxare,are);
            }
        }
    cout<<num<<endl;
    cout<<maxare<<endl;
}