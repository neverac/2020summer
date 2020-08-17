#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#define ll long long
#define N 2100
#define ms(x, y) memset(x, y, sizeof x)
#define INF 0x3f3f3f3f
//ll mod = 12;
using namespace std;

vector<string> ans;
string s[N];
int main()
{
    cin >> s[1] >> s[2] >> s[3];
    for (int i = 1; i <= 3;i++){
        if(s[i] == "bubble" || s[i] == "tapioka")
            continue;
        ans.push_back(s[i]);
    }
    if(ans.size() == 0){
        printf("nothing");
    }else{
        for (int i = 0; i < ans.size();i++){
            cout << ans[i];
            if(i != ans.size()-1){
                cout << " ";
            }
        }
    }
    printf("\n");
    return 0;
}
// #include<bits/stdc++.h>



// using namespace std;



// int main() 

// {

//     string str1 ;

//     string str2 ;

//     string str3 ;

//     cin>>str1;

//     cin>>str2;

//     cin>>str3;

	

// 	if(str1!="bubble"&&str1!="tapioka"&&str2!="bubble"&&str2!="tapioka"&&str3!="bubble"&&str3!="tapioka")

// 	cout<<str1<<" "<<str2<<" "<<str3<<endl;

// 	else if((str1=="bubble"||str1=="tapioka")&&(str2!="bubble"&&str2!="tapioka")&&(str3!="bubble"&&str3!="tapioka"))

// 	cout<<str2<<" "<<str3<<endl;

// 	else if((str1=="bubble"||str1=="tapioka")&&(str2=="bubble"||str2=="tapioka")&&(str3=="bubble"||str3=="tapioka"))

// 	cout<<"nothing"<<endl;

// 	else if((str1!="bubble"&&str1!="tapioka")&&(str2=="bubble"||str2=="tapioka")&&(str3!="bubble"||str3!="tapioka"))

// 	cout<<str1<<" "<<str3<<endl;

// 	else if((str1!="bubble"&&str1!="tapioka")&&(str2!="bubble"||str2!="tapioka")&&(str3=="bubble"||str3=="tapioka"))

// 	cout<<str1<<" "<<str2<<endl;

// 	else if((str1=="bubble"||str1=="tapioka")&&(str2=="bubble"&&str2=="tapioka")&&(str2!="bubble"&&str2!="tapioka"))

// 	cout<<str3<<endl;

// 	else if((str1=="bubble"&&str1=="tapioka")&&(str2!="bubble"||str2!="tapioka")&&(str3=="bubble"||str3=="tapioka"))

// 	cout<<str2<<endl;

// 	else if((str1!="bubble"&&str1!="tapioka")&&(str2=="bubble"||str2=="tapioka")&&(str3=="bubble"||str3=="tapioka"))

// 	cout<<str1<<endl;

//     return 0;

// }
