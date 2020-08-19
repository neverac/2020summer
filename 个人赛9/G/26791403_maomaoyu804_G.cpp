#include <bits/stdc++.h>
using namespace std;
int pp[200005];

int vis[200005];
struct node{
	int id,p;
	bool operator<(const node &b) const{
		return p>b.p;
	}
};

priority_queue<node> q[5];

int main(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&pp[i]);
	for(int i=0;i<n;i++){
		int aa;scanf("%d",&aa);
		node no;no.id=i;no.p=pp[i];
		q[aa].push(no);
	}
	for(int i=0;i<n;i++){
		int aa;scanf("%d",&aa);
		node no;no.id=i;no.p=pp[i];
		q[aa].push(no);
	}
	int m;scanf("%d",&m);
	for(int i=0;i<m;i++){
		int temp;scanf("%d",&temp);
		if(q[temp].empty()){
			printf("-1 ");
			continue;
		}
		node nn=q[temp].top();
		while(vis[nn.id]){
			q[temp].pop();
			if(q[temp].empty()){
				printf("-1 ");
				break;
			}
			nn=q[temp].top();
		}
		if(q[temp].empty()) continue;
		printf("%d ",nn.p);
		vis[nn.id]=1;
		q[temp].pop();
	}
}