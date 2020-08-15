#include<bits/stdc++.h>

using namespace std;

string ans;
char a[4004],b[4004];
int lena,lenb;
int ida[4004][2],idb[4004][2],vis[4004][4004];
struct node
{
	int x,y;
	string s;
	node()
	{
		x=0;y=0;
		s="";
	}
	node(int xx,int yy,string ss)
	{
		x=xx,y=yy;
		s=ss;
	}
};
queue< node > q;

void init()
{
    ida[lena][0]=ida[lena][1]=lena+1;
    ida[lena+1][0]=ida[lena+1][1]=lena+1;
    for(int i=lena-1;i>=0;i--)
    {
        for(int j=0;j<2;j++)
            ida[i][j]=ida[i+1][j];
        ida[i][a[i+1]-'0']=i+1;
    }
    idb[lenb][0]=idb[lenb][1]=lenb+1;
    idb[lenb+1][0]=idb[lenb+1][1]=lenb+1;
    for(int i=lenb-1;i>=0;i--)
    {
        for(int j=0;j<2;j++)
            idb[i][j]=idb[i+1][j];
        idb[i][b[i+1]-'0']=i+1;
    }
}

int main()
{
    scanf("%s",a+1);
    scanf("%s",b+1);
    lena=strlen(a+1);
    lenb=strlen(b+1);
    init();
    int x,y;
    string st;
    x=ida[0][0];
    y=idb[0][0];
    if(x==lena+1&&y==lenb+1)
    {
        printf("0\n");
        return 0;
    }
    st="0";
    q.push(node(x-1,y-1,st)); 
    vis[x-1][y-1]=1;
    x=ida[0][1];y=idb[0][1];
    if(x==lena+1&&y==lenb+1)
    {
        printf("1\n");
        return 0;
    }
    st="1";
    q.push(node(x-1,y-1,st));
    vis[x-1][y-1]=1;
    while(!q.empty())
    {
        node dang=q.front();
        q.pop();
        int x=dang.x,y=dang.y;
        string st=dang.s;
        x++;y++;
        int i=ida[x][0],j=idb[y][0];
        st+='0';
        if(i-1==lena&&j-1==lenb)ans=st;
        if(!vis[i-1][j-1])q.push(node(i-1,j-1,st)),vis[i-1][j-1]=1;
        if(vis[lena][lenb])break;
        i=ida[x][1],j=idb[y][1];
        st=dang.s+'1';
        if(i-1==lena&&j-1==lenb)ans=st;
        if(!vis[i-1][j-1])q.push(node(i-1,j-1,st)),vis[i-1][j-1]=1;
    	if(vis[lena][lenb])break;
	}
    cout<<ans<<endl;
    return 0;
}