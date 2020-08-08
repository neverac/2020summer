#include <cstdio>
#include <string>
using namespace std;

const int MAX_N = 300008;

char ch[MAX_N];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf(" \n%s", ch);
        string s[2];
        int L = -1;
        while (ch[++L])
        {
            s[(ch[L] - '0') & 1].push_back(ch[L]);
        }
        s[0].push_back('z');
        s[1].push_back('z');
        int p[2] = {0, 0};
        for (int i = 0; i < L; i++)
        {
            if (s[0][p[0]] < s[1][p[1]])
            {
                ch[i] = s[0][p[0]++];
            }
            else
            {
                ch[i] = s[1][p[1]++];
            }
        }
        printf("%s\n", ch);
    }
    return 0;
}