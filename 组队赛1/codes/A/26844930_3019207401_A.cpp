#include <iostream>
#include <cstring>

using namespace std;

int n;
string s0;
string s;
bool flag;
bool judge (char x)
{
    if(x>='0'&&x<='9') return true;
    return false;
}
int main()
{
    cin>>n;
    cin>>s0;
    int len1=s0.length();
    while(n--)
    {
        cin>>s;
        int len2=s.length();
        flag=false;
        int pos1=0;
        int pos2=0;
        while(pos1<len1&&pos2<len2)
        {
            if(judge(s[pos2])==1&&judge(s0[pos1])==1)
            {
                int num1=s0[pos1]-'0';

                int num2=s[pos2]-'0';

                int cnt1=pos1+1;
                int cnt2=pos2+1;
                while(judge(s0[cnt1]))
                {
                    num1=num1*10+s0[cnt1]-'0';

                    cnt1++;
                }
                while(judge(s[cnt2]))
                {
                    num2=num2*10+s[cnt2]-'0';

                    cnt2++;
                }
                if(num1>num2)
                {   cout<<"-"<<endl;

                    flag=true;
                    break;
                }
                else if(num1<num2){
                    flag=true;
                    cout<<"+"<<endl;

                    break;
                }
                else {
                    pos1=cnt1;
                    pos2=cnt2;
                    continue;
                }
            }
            else if(judge(s[pos2])==0&&judge(s0[pos1])==0)
            {
                if(s[pos2]>s0[pos1])
                {
                    cout<<"+"<<endl;
                    flag=true;
                    break;
                }
                else if(s[pos2]<s0[pos1])
                {
                    cout<<"-"<<endl;
                    flag=true;
                    break;
                }
                else {
                    pos2++;
                    pos1++;
                }
            }
            else if(judge(s[pos2])==1&&judge(s0[pos1])==0)
            {
                cout<<"-"<<endl;
                flag =true;
                break;
            }
            else
            {
                cout<<"+"<<endl;
                flag=true;
                break;
            }
        }
        if(!flag)
        {
            if(len1<=len2) cout<<"+"<<endl;
			else  cout<<"-"<<endl;
        }

    }
    return 0;
}
