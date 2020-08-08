#include <iostream>
#include <vector>
using namespace std;
int fa[100005],siz[100005],N,rot;
vector<int>chi[100005],ans;
void getsiz(int rt){
    for(int i=0;i<chi[rt].size();i++){
        getsiz(chi[rt][i]);
        siz[rt]+=siz[chi[rt][i]];
    }
}
int main(){
    //freopen("in.txt","r",stdin);
    scanf("%d",&N);
    ans.clear();
    for(int i=1;i<=N;i++){
        chi[i].clear();
        fa[i]=0;
    }
    for(int i=1;i<=N;i++){
        scanf("%d",fa+i);
        if(fa[i]==0){
            rot=i;
        }
        siz[i]=1;
        chi[fa[i]].push_back(i);
    }
    getsiz(rot);
    for(int i=1;i<=N;i++){
        if(2*siz[i]>N){
            bool flag=true;
            for(int j=0;j<chi[i].size();j++){
                if(2*siz[chi[i][j]]>N){
                    flag=false;
                    break;
                }
            }
            if(flag){
                ans.push_back(i);
            }
        }
    }
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++){
        printf("%d ",ans[i]);
    }
	return 0;
} 