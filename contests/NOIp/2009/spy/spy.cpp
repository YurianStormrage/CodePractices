#include <cstdio>
#include <cstring>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
const int N = 105;
int len1, len2, cnt;
int used[200];
char str1[N], str2[N], str3[N], str4[N];
int list[200];
int main() {
	scanf("%s%s",str1+1,str2+1); len1 = strlen(str1+1);
	rep(i,1,len1) {
		if(used[str2[i]] && used[str2[i]]!=str1[i]) {printf("Failed"); return 0;}
		if(list[str1[i]] && list[str1[i]]!=str2[i]) {printf("Failed"); return 0;}
		if(!list[str1[i]]) ++cnt;
		list[str1[i]] = str2[i];
		used[str2[i]] = str1[i];
	}
	if(cnt < 26) {printf("Failed"); return 0;}

	scanf("%s",str3+1); len2 = strlen(str3+1);
	rep(i,1,len2) {
		str4[i] = list[str3[i]];
	}
	printf("%s",str4+1);
	return 0;
}
