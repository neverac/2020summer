#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int p[N];
int find(int x)
{
	return p[x]==x? x:p[x]=find(p[x]);
}

int main()
{
	int n,k;
	int ans=0;
	scanf("%d%d", &n, &k);
	for(int i=0; i<n; i++) {
            p[i]=i;
	}
	while(k--)
	{
		int a,b;
		scanf("%d%d",&a, &b);
		 a=find(a);
		 b=find(b);
		if(a==b) ans++;
		p[a]=b;
	}
	printf("%d", ans);
	return 0;
}