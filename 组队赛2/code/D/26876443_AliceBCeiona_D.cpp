#include <bits/stdc++.h>
using namespace std;

string a;

int main()
{
    int flag = 0;
    for (int i = 1; i <= 3; i++)
    {
        cin >> a;
        if (a == "tapioka" || a == "bubble")
            continue;
        flag = 1;
        cout << a << " ";
    }
    if (!flag)
        puts("nothing");
    return 0;
}