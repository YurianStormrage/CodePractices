#include <cstdio>
#include <cstring>
char s[500];
int len;
int now;
int main() {
	scanf("%s",s);
	len = strlen(s);
	now = 'a';
	for(int i = 0; i < len; ++i) {
		if(now < s[i]) {printf("NO"); return 0;}
		if(now == s[i]) ++now;
	}
	printf("YES");
	return 0;
}
