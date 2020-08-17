#include<iostream>
using namespace std;
int heap[30001];
void put(int);
void get(int);
int T;
int main()
{
cin>>T;
for(int w=1;w<=T;++w)
{
int tot=0,n=0;
cin>>n;
for(int i=1;i<=n;++i)
{cin>>heap[i];
put(i);}
for(int i=1;i<=n-1;++i)
{int d=heap[1];
get(n-i+1);
d+=heap[1];
get(n-i);
heap[n-i]=d;
put(n-i);
tot+=d;}
cout<<tot<<endl;
}
return 0;
}
void put(int p)
{if(p==1)
return;
if(heap[p]<heap[p/2])
{int t=heap[p];
heap[p]=heap[p/2];
heap[p/2]=t;
put(p/2);}
}
void get(int p)
{int h=1;
heap[1]=heap[p];
while(h*2<=p-1)
{if(h*2==p-1&&heap[p-1]<heap[h])
{int t=heap[p-1];heap[p-1]=heap[h];heap[h]=t;break;}
int m;bool c;
if(heap[h*2]<=heap[h*2+1])
{m=heap[h*2];c=false;}
else
{m=heap[h*2+1];c=true;}
if(m<heap[h])
{int t=heap[h];heap[h]=heap[h*2+c];heap[h*2+c]=t;h=h*2+c;}
else
break;}
}