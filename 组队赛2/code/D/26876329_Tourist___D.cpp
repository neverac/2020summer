#include <bits/stdc++.h>
using namespace std;
int len =60;
int main(){
    string s1,s2,s3;
    cin >> s1>>s2>>s3;
    int flag = 0;
    if (s1!="bubble" && s1!="tapioka") flag=1,cout << s1 <<' ';
    if (s2!="bubble" && s2!="tapioka") flag=1,cout << s2 <<' ';
    if (s3!="bubble" && s3!="tapioka") flag=1,cout << s3;
    if (flag==0) cout << "nothing"<<endl;

}