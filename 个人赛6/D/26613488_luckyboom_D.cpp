#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int const len=105, maxn=1e5+7;
int n,q,c,cc[12][len+5][len+5];
void add(int x,int y,int g){
	for(int i=x;i<=len;i+=i&(-i))
	  for(int j=y;j<=len;j+=j&(-j))
	    cc[g][i][j]+=1;
} 
struct Query{
    int t,x1,y1,x2,y2,num;
}qu[maxn];
int query(int x,int y,int g){
	int ans=0;
	for(int i=x;i>0;i-=i&(-i))
	 for(int j=y;j>0;j-=j&(-j))
	   ans+=cc[g][i][j];
	return ans;
}
struct star{
    int x,y,s,t;
}st[maxn];
int main(){
    scanf("%d%d%d",&n,&q,&c);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&st[i].x,&st[i].y,&st[i].s);
        add(st[i].x,st[i].y,st[i].s);
    }
    for(int i=1;i<=q;i++){
        qu[i].num=i;
        scanf("%d%d%d%d%d",&qu[i].t,&qu[i].x1,&qu[i].y1,&qu[i].x2,&qu[i].y2);
    }
    c++;
    for(int i=1;i<=q;i++){
        int tt=qu[i].t;
        long long ans=0;
        for(int j=0;j<c;j++){
            ans+=((tt+j)%c)*(query(qu[i].x2,qu[i].y2,j)-query(qu[i].x2,qu[i].y1-1,j)-query(qu[i].x1-1,qu[i].y2,j)+query(qu[i].x1-1,qu[i].y1-1,j));
        }
        printf("%lld\n",ans);
    }
    return 0;
}