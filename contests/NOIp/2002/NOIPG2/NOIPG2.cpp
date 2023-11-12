#include <cstdio>
#include <cstring>
const int inf = int(1e9);
char A[25], B[25], x[7][25], y[7][25];
int tot = 1;
int ans = inf;
bool check(char* a, char* b) {
	int len1=strlen(a), len2=strlen(b);
	if(len1 != len2) return false;
	for(int i = 0; i < len1; ++i)
		if(a[i] != b[i]) return false;
	return true;
}
inline void find(char* a, char (&res)[20][25]) {
	int len = strlen(a), cnt = 0;
	for(int i=0, l; i < len; ++i) {
		for(int j = 1; j < tot; ++j) {
			l = 0;
			int len2=strlen(x[j]),len3=strlen(y[j]);
			while(i+l<len&&l<len2 && a[i+l]==x[j][l]) ++l;
			if(l == len2) {
				++cnt;
				int p = 0;
				for(; p < i; ++p) res[cnt][p] = a[p];
				for(int t=0; t<len3; ++p,++t) res[cnt][p] = y[j][t];
				for(int t=i+len2; t<len; ++p,++t) res[cnt][p] = a[t];
			}
		}
	}
}
inline void dfs(char* a, int step) {
	if(check(a, B)) {
		if(ans > step) ans = step;
		return;
	}
	if(step >= ans || step >= 10) return;
	char res[20][25]; memset(res, 0, sizeof(res));
	find(a, res);
	for(int i = 1; strlen(res[i]); ++i)
		dfs(res[i], step+1);
}
int main() {
	freopen("input.in","r",stdin);
	scanf("%s%s",A,B);
	for(; scanf("%s%s",x[tot],y[tot]) != EOF; ++tot);
	dfs(A, 0);
	if(ans == inf) printf("NO ANSWER!");
	else printf("%d\n",ans);
	return 0;
}
