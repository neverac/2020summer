#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN=3E5+10;
char str[MAXN];
int ji[MAXN],ou[MAXN];
void doing() {
	/*
	*
	* ????????
	*
	*/
	scanf("%s",str);
	int *a=ji;int *b=ou;
	for(char*c=str;*c;++c) {
		if((*c-'0')%2==0) {
			*(a++)=*c-'0';
		}else {
			*(b++)=*c-'0';
		}
	}*(a++)=-1;*(b++)=-1;
	a=ji;b=ou;
	while(!(*a==-1 && *b==-1)) {
		if(*a==-1)printf("%d",*(b++));
		else if(*b==-1)printf("%d",*(a++));
		else {
			if(*a<*b) {
				printf("%d",*(a++));
			}else {
				printf("%d",*(b++));
			}
		}
	} printf("\n");
}
int main() {
	int T;scanf("%d",&T); 
	while(T-->0)doing();
	return 0;
}