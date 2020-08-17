#include <bits/stdc++.h>
using namespace std;

int mp[10][10];
const int dir[2][2][2] = {0, -1, 0, 1, -1, 0, 1, 0};

void print()
{
    for (int i = 1; i <= 6; i++, cout << endl)
        for (int j = 1; j <= 6; j++)
            cout << mp[i][j] << " ";
}

struct Vehicle
{
    int id;
    int sx, sy;
    int ex, ey;
    // 0 横 1 竖
    int dd;
    bool move(int k)
    {
        // cout << id << " " << k << " " << sx + dir[dd][k][0] << " " << sy + dir[dd][k][1] << endl;
        if ((k == 0 && mp[sx + dir[dd][k][0]][sy + dir[dd][k][1]]) || (k == 1 && mp[ex + dir[dd][k][0]][ey + dir[dd][k][1]]))
            return false;
        // if (mp[sx + dir[dd][k][0]][sy + dir[dd][k][1]])
        //     return false;
        // cout << "dd" << endl;
        if (dd)
        {
            for (int i = sx; i <= ex; i++)
                mp[i][sy] = 0;
            sx = sx + dir[dd][k][0], ex = ex + dir[dd][k][0];
            for (int i = sx; i <= ex; i++)
                mp[i][sy] = id;
        }
        else
        {
            for (int i = sy; i <= ey; i++)
                mp[sx][i] = 0;
            sy = sy + dir[dd][k][1], ey = ey + dir[dd][k][1];
            for (int i = sy; i <= ey; i++)
                mp[sx][i] = id;
        }
        // print();
        return true;
        
    }
} vehicles[15];
int vcnt;
int base5[15];

map<int, int> vis;
int ans = 50;
inline bool gethash(int step)
{
    int h = 0;
    for (int i = 1; i <= vcnt; i++)
        h += (vehicles[i].dd ? vehicles[i].sx - 1 : vehicles[i].sy - 1) * base5[i];
    // for (int i = 1; i <= vcnt; i++)
    // {
    //     cout << i << " " << (vehicles[i].dd ? vehicles[i].sx - 1 : vehicles[i].sy - 1) << " " << (vehicles[i].dd ? vehicles[i].sy - 1 : vehicles[i].sx - 1) * base5[i] << endl;
    // }
        // h += (vehicles[i].dd ? vehicles[i].sy - 1 : vehicles[i].sx - 1) * base5[i];
    // cout << h << " " << vis[h] << endl;
    if (vis[h] == 0 || vis[h] > step)
    {
        vis[h] = step;
        return true;
    }
    else
    {
        return false;
    }
    
    // return vis[h] ? false : vis[h] = 1;
}

int lim = 10;
int slen;
void dfs(int step)
{
    // cout << endl;
    // cout << step << endl;
    if (!gethash(step))
        return;
    // cout << "dd" << endl;
    // print();
    // cout << endl;
    if (mp[3][6] == 1)
    {
        // cout << step << endl;
        if (step - 1 < ans)
            ans = step - 1;
        return;
    }
    if (step == lim + 1)
        return;

    for (int i = 1; i <= vcnt; i++)
    {
        for (int k = 0; k < 2; k++)
        {
            if (vehicles[i].move(k))
            {
                // cout << i << " " << k << endl;
        //         for (int i = 1; i <= vcnt; i++)
        // {
        //     cout << vehicles[i].id << " " << vehicles[i].sx << " " << vehicles[i].sy << " " << vehicles[i].ex << " " << vehicles[i].ey << " " << vehicles[i].dd << endl;
        // }
                // if (gethash(step + 1))
                    dfs(step + 1);
                vehicles[i].move(k ^ 1);
                // cout << "back " << i << " " << k << endl;
            }
        }
    }
}

void bfs()
{

}

void init()
{
    memset(mp, 0x3f, sizeof mp);
    for (int i = 1; i <= 6; i++)
        for (int j = 1; j <= 6; j++)
            cin >> mp[i][j];
    base5[0] = 1;
    for (int i = 1; i < 12; i++)
        base5[i] = base5[i - 1] * 5;
    // cout << "dd" << endl;
    vcnt = 0;
    for (int i = 1; i <= 6; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (mp[i][j])
            {
                int id = mp[i][j];
                // cout << id << endl;
                if (vehicles[id].id)
                {
                    vehicles[id].ex = i;
                    vehicles[id].ey = j;
                }
                else
                {
                    vehicles[id].id = id;
                    vehicles[id].sx = i;
                    vehicles[id].sy = j;
                }
                vcnt = max(vcnt, id);
            }
        }
    }
    // cout << "dd" << endl;
    for (int i = 1; i <= vcnt; i++)
        vehicles[i].dd = vehicles[i].sx != vehicles[i].ex;

    slen = vehicles[1].dd ? (vehicles[1].ex - vehicles[1].sx) : (vehicles[1].ey - vehicles[1].sy);
    slen += 1;
    lim = 10 - slen;
    // for (int i = 1; i <= vcnt; i++)
    // {
    //     cout << vehicles[i].id << " " << vehicles[i].sx << " " << vehicles[i].sy << " " << vehicles[i].ex << " " << vehicles[i].ey << " " << vehicles[i].dd << endl;
    // }
}

int main()
{

    init();
    // cout << "dd" << endl;
    dfs(1);

    cout << (ans < 50 ? ans + slen : -1) << endl;
}