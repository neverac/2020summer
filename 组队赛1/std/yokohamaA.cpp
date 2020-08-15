#include<bits/stdc++.h>

using namespace std;

struct node
{
    int type;
    char lt;
    int nm;
}itm0[15], itm[15];
int n, cnt0, cnt;
char s0[15], s[15];

int brk(char a[], node it[])
{
    int ret=0;
    int i=0, len=strlen(a);
    while (i<len)
    {
        if (a[i]>='0'&&a[i]<='9')
        {
            it[++ret].type=1;
            it[ret].nm=0;
            while (i<=len&&a[i]>='0'&&a[i]>='0'&&a[i]<='9')
            {
                it[ret].nm=it[ret].nm*10+a[i]-'0';
                i++;
            }
        }
        else
        {
            it[++ret].type=2;
            it[ret].lt=a[i];
            i++;
        }
    }
    return ret;
}

int main()
{
    scanf("%d", &n);
    scanf("%s", s0+1);
    cnt0=brk(s0+1, itm0);
    for (int i=1;i<=n;i++)
    {
        memset(s, 0, sizeof(s));
        scanf("%s", s+1);
        memset(itm, 0, sizeof(itm));
        cnt=brk(s+1, itm);
        int kk=min(cnt, cnt0);
        int f=2;
        for (int i=1;i<=kk;i++)
        {
            if (itm[i].type<itm0[i].type)
            {
                f=0;break;
            }
            else if (itm[i].type>itm0[i].type)
            {
                f=1;break;
            }
            else
            {
                if (itm[i].type==1)
                {
                    if (itm[i].nm==itm0[i].nm)continue;
                    else
                    {
                        f= itm[i].nm>=itm0[i].nm;break;
                    }
                }
                else
                {
                    if (itm[i].lt==itm0[i].lt)continue;
                    else
                    {
                        f= itm[i].lt>=itm0[i].lt;break;
                    }
                }
            }
        }
        if (f==1) printf("+\n");
        else if (f==0)printf("-\n");
        else printf(cnt<cnt0? "-\n":"+\n");
    }

}
