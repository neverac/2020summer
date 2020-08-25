#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
const int SIZEN = 20;
int num[10];
int fans[10] = {0},y;
void Judge(int x){
	int flag = 0;
	for(int i = 9;i>=0;i--){
		if(fans[i] == num[i])continue;
		if(fans[i] > num[i])return;
		flag = 1;
		break;
	}
	if(flag){
		for(int i = 9;i >= 0;i--)fans[i] = num[i];
		y = x;
	}
	else{
		y = max(y,x);
	}
}
void Print(){
	int tmp = 0;
	for(int i = 1;i <= 9;i++){
		tmp += num[i];
	}
	if(tmp == 0){
		printf("%d\n",y);
		return;
	}
	for(int i = 9;i>= 0;i--){
		while(fans[i])putchar(i + '0'),fans[i]--;
	}
	printf("%02d\n",y);
}
void work(){
	memset(fans,0,sizeof fans);
	y = -1;
	int sum = 0;
	for(int i = 0;i < 10;i++){
		scanf("%d",&num[i]);
		sum += num[i];
	}
	if(sum == 1){
		if(num[8])puts("8");
		else if(num[4])puts("4");
		else if(num[0])puts("0");
		else puts("-1");
		return;
	}
	else if(sum == 2){
		int ans = -1;
		for(int i = 0;i <= 9;i++){
			for(int j = 0;j <= 9;j++){
				if(i == j && num[i] != 2)continue;
				if(!num[i] || !num[j])continue;
				int x = i * 10 + j;
				if(x % 4 == 0)ans = max(ans,x);
			}
		}
		for(int i = 0;i <= 9;i++){
			if(i % 4 == 0 && num[i])ans = max(ans,i);
		}
		printf("%d\n",ans);
		return ;
	}
	for(int i = 0;i < 10;i++){
		for(int j = 0;j < 10;j++){
			if(i == j && num[i] < 2)continue;
			if(!num[i] || !num[j])continue;
			int x = i * 10 + j;
			num[i]--;
			num[j]--;
			if(x % 4 == 0)Judge(x);
			num[i]++;
			num[j]++;
		}
	}
	if(y!=-1)Print();
	else{
		if(num[8])puts("8");
		else if(num[4])puts("4");
		else if(num[0])puts("0");
		else puts("-1");
	}
	//skfdjgs;okgoksfh;ofgh;oj
}
int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}