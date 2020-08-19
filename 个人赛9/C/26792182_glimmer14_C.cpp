#include <bits/stdc++.h>
using namespace std;

const int N = 2e4 + 100;

int a[N], x[N], y[N], z[N];

bool comp(int a, int b)
{
    if (x[a] != x[b])
        return x[a] < x[b];
    else if (y[a] != y[b])
        return y[a] < y[b];
    else  
        return z[a] < z[b];
}

void solvex(int l, int r);
void solvey(int l, int r);
void solvez(int l, int r);

int sta[N], top;
void solve(int l, int r)
{
    int pp = top;
    for (int i = l; i <= r; i ++)
    {
        int ll = i, rr = i;
        while (rr + 1 <= r && x[a[rr + 1]] == x[a[ll]]) rr ++;
        solvex(ll, rr);
        i = rr;
    }
    while (top - pp >= 2)
        cout << sta[top - 2] << " " << sta[top - 1] << endl, top -= 2;
}

void solvex(int l, int r)
{
    int pp = top;
    for (int i = l; i <= r; i ++)
    {
        int ll = i, rr = i;
        while (rr + 1 <= r && y[a[rr + 1]] == y[a[ll]]) rr ++;
        solvey(ll, rr);
        i = rr;
    }
    while (top - pp >= 2)
        cout << sta[top - 2] << " " << sta[top - 1] << endl, top -= 2;
}

void solvey(int l, int r)
{
    int pp = top;
    for (int i = l; i <= r; i ++)
    {
        int ll = i, rr = i;
        while (rr + 1 <= r && z[a[rr + 1]] == z[a[ll]]) rr ++;
        solvez(ll, rr);
        i = rr;
    }
    while (top - pp >= 2)
        cout << sta[top - 2] << " " << sta[top - 1] << endl, top -= 2;
}

void solvez(int l, int r)
{
    int i;
    for (i = l; i < r; i += 2)
        cout << a[i] << " " << a[i + 1] << endl;
    
    if (i == r)
        sta[top++] = a[r];
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> x[i] >> y[i] >> z[i], a[i] = i;
    sort(a + 1, a + 1 + n, comp);

    solve(1, n);
    // for (int i = 1; i <= n; i += 2)
    //     cout << a[i] << " " << a[i + 1] << endl;
}