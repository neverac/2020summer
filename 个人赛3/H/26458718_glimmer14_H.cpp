#include <bits/stdc++.h>
using namespace std;

const int N = 65;

char val[N][N];

int r, c;

bool allA()
{
    for (int i = 1; i <= r; i ++)
        for (int j = 1; j <= c; j ++)
            if (val[i][j] != 'A') return false;

    return true;
}

bool allP()
{
    for (int i = 1; i <= r; i ++)
        for (int j = 1; j <= c; j ++)
            if (val[i][j] != 'P') return false;

    return true;
}

bool rowAll(int i)
{
    for (int j = 1; j <= c; j ++)
        if (val[i][j] != 'A') return false;
    return true;
}

bool colAll(int j)
{
    for (int i = 1; i <= r; i ++)
        if (val[i][j] != 'A') return false;
    return true;
}

bool rowHas(int i)
{
    for (int j = 1; j <= c; j ++)
        if (val[i][j] == 'A') return true;
    return false;
}

bool colHas(int j)
{
    for (int i = 1; i <= r; i ++)
        if (val[i][j] == 'A') return true;
    return false;
}


bool one()
{
    return (rowAll(1) || rowAll(r) || colAll(1) || colAll(c));
}

bool two()
{
    if (val[1][1] == 'A' || val[r][1] == 'A' || val[1][c] == 'A' || val[r][c] == 'A') return true;
    for (int i = 2; i <= r - 1; i ++)
        if (rowAll(i)) return true;
    for (int j = 2; j <= c - 1; j ++)
        if (colAll(j)) return true;
    return false;
}

bool three()
{
    if (rowHas(1) || rowHas(r) || colHas(1) || colHas(c)) return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> r >> c;

        for (int i = 1; i <= r; i ++)
            for (int j = 1; j <= c; j ++)
                cin >> val[i][j];
                // scanf("%c", &val[i][j]);
        
        // for (int i = 1; i <= r; i ++)
        //     for (int j = 1; j <= c; j ++)
        //         printf("%c", val[i][j]);
        
        if (allA()) printf("0\n");
        else if (allP()) printf("MORTAL\n");
        else if (one()) printf("1\n");
        else if (two()) printf("2\n");
        else if (three()) printf("3\n");
        else printf("4\n"); 
    }
    
}