#include <bits/stdc++.h>
using namespace std;
struct node{
	int mp[6][6];
	int step;
	bool operator<(const node b) const {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                if (this->mp[i][j] < b.mp[i][j]) return true;
            }
        }
        return false;
    }
}ini;
set <node> s;
queue <node> q;
int dx[4]={0,-1,1,0};
int dy[4]={1,0,0,-1};

bool carmove(node now,int x,int y,int k,int nm){
	node nxt=now;
	if (k==0){
		for (int i=0;i<6;i++){
			if (now.mp[x][i]==now.mp[x][y]){
				nxt.mp[x][i]=0;
				nxt.mp[x+dx[k]][y+dy[k]]=now.mp[x][y];
				break;
			} 
		}
	}else if (k==1){
		for (int i=5;i>=0;i--){
			if (now.mp[i][y]==now.mp[x][y]){
				nxt.mp[i][y]=0;
				nxt.mp[x+dx[k]][y+dy[k]]=now.mp[x][y];
				break;
			} 
		}
	}else if (k==3){
		for (int i=5;i>=0;i--){
			if (now.mp[x][i]==now.mp[x][y]){
				nxt.mp[x][i]=0;
				nxt.mp[x+dx[k]][y+dy[k]]=now.mp[x][y];
				break;
			} 
		}
	}else {
		for (int i=0;i<6;i++){
			if (now.mp[i][y]==now.mp[x][y]){
				nxt.mp[i][y]=0;
				nxt.mp[x+dx[k]][y+dy[k]]=now.mp[x][y];
				break;
			} 
		}
	}
//	cout<<"----"<<endl;
//	for (int i=0;i<6;i++){
//		for (int j=0;j<6;j++){
//			cout<<nxt.mp[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	if (nxt.mp[2][5]==1) return true;
	int la;
	for (int i=0;i<6;i++){
		if (nxt.mp[2][i]==1) la=7-i;
	}
	if (s.find(nxt)==s.end()&&nm+la<=10){
		q.push(nxt);
		s.insert(nxt);	
	}
	return false;
}
bool flag=false;
void bfs(){
	q.push(ini);
	s.insert(ini);
	int num=0;
	while (!q.empty()){
		int sz=q.size();
		if (num>=8) return;
		num++;
//		cout<<sz<<" "<<num<<endl;
		while (sz--){
			node now=q.front();
			q.pop();
			//遍历图 
			for (int i=0;i<6;i++){
				for (int j=0;j<6;j++){
					if (now.mp[i][j]){//如果当前有车 
						for (int k=0;k<4;k++){
							int x=i+dx[k],y=j+dy[k];
							if (x<0||y<0||x>=6||y>=6) continue;
							//cout<<x<<" "<<y<<" "<<now.mp[i][j]<<endl; 
							if (now.mp[x][y]==0&&now.mp[i][j]==now.mp[i+dx[3-k]][j+dy[3-k]]){
//								cout<<x<<" "<<y<<" "<<now.mp[i][j]<<endl; 
								bool ok=carmove(now,i,j,k,num);
								if (ok){
									if (num<=8) {
										cout<<num+2<<endl;
										flag=true;
										return;
									}
								}
							}
						} 
					}
				}
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i=0;i<6;i++)
		for (int j=0;j<6;j++)
			cin>>ini.mp[i][j];
	ini.step=0;
	int nn=0;
	for (int i=0;i<6;i++) if (ini.mp[2][i]==1) nn++;
	if (nn<=1) {
		cout<<-1<<endl;
		return 0;
	}
	if (ini.mp[2][5]==1) cout<<2<<endl;
	else {
		bfs();
		if (!flag) {
			cout<<-1<<endl;
		}
	}
	return 0;
}

