#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long LL;
 
char str[300050];
 
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
    	getchar();
        scanf("%s",str);
        int p1 = -1, p2 = -1;
        int len = strlen(str);
        for (int i = 0;i < len;i++)
        {
            if (p1 == -1 && ((int)str[i]-'0')%2 == 0)
                p1 = i;
            if (p2 == -1 && ((int)str[i]-'0')%2 == 1)
                p2 = i;
        }
        while(p1 < len && p2 < len && p1 != -1 && p2 != -1)
        {
            if ((int)(str[p1]-'0') < (int)(str[p2]-'0'))
            {
                printf("%c", str[p1]);
                p1++;
                while(p1 < len && (int)(str[p1]-'0')%2 == 1)
                    p1++;
            }
            else
            {
                printf("%c", str[p2]);
                p2++;
                while(p2 < len && (int)(str[p2]-'0')%2 == 0)
                    p2++;
            }
        }
        if (p1 < len && p1 != -1)
        {
            for (int i = p1;i < len;i++)
            {
                if ((int)(str[i]-'0')%2 == 0)
                    printf("%c", str[i]);
            }
        }
        else if (p2 < len && p2 != -1)
        {
            for (int i = p2;i < len;i++)
            {
                if ((int)(str[i]-'0')%2 == 1)
                    printf("%c", str[i]);
            }
        }
        puts("");
    }
    return 0;
}