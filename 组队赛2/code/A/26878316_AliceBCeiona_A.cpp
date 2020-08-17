#include <bits/stdc++.h>
using namespace std;
struct node {
    int f[6][6];
	int del;
    friend bool operator < (node p, node q) {
        for (int i = 0; i<6; ++i)
            for (int j = 0; j<6; ++j)
                if (p.f[i][j] != q.f[i][j]) return p.f[i][j] < q.f[i][j];
        return 0;
    }
}a;
queue<node>q;
set<node>vis;
int s[4][2] = {0,1,0,-1,1,0,-1,0};
inline bool judge(int x,int y){
    return x>=0 && x<6 && y>=0 && y<6;
}
int main() 
{
    for(int i = 0; i< 6; ++i)
        for(int j = 0; j<6; ++j)
            scanf("%d", &a.f[i][j]);
    a.del = 0;
    q.push(a);
    vis.insert(a);
    while(q.size()){
        node puz = q.front();
        node p;
        q.pop();
        if(puz.f[2][5] == 1){
            int len = 1;
            for (int i = 4; i >= 0; --i) {
                if (puz.f[2][i]!=1) break;
                ++len;
            }
            int ans = (puz.del + len);
            if (ans > 10) ans = -1;
            printf("%d\n", ans);
            return 0;
        }
        if(puz.del == 10) break;
        for(int i = 0; i<6; ++i)
            for(int j = 0; j<6; ++j) 
                if(puz.f[i][j] == 0) 
                    for(int k = 0; k < 4; ++k){
                        int x = s[k][0] + i;
						int y = s[k][1] + j;
                        if((!judge(x,y))||puz.f[x][y] == 0) continue;
                        int xx = s[k][0]+x;
						int yy = s[k][1]+y;
                        if((!judge(xx,yy)) || puz.f[x][y] != puz.f[xx][yy]) continue;
                        while(judge(xx,yy) && puz.f[x][y] == puz.f[xx][yy]){
                            xx = xx+s[k][0];
                            yy = yy+s[k][1];
                        }
                        xx = xx-s[k][0];
                        yy = yy-s[k][1];
                        p = puz;
                        ++p.del;
                        swap(p.f[i][j],p.f[xx][yy]);
                        if(!vis.count(p)) {
                            vis.insert((p));
                            q.push(p);
                        }
                    }        
    }
    printf("-1\n");
    return 0;
}