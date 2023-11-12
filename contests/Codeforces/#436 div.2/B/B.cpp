#include <cstdio>
#include <cstring>
const int N = 205;
int n, len;
int tmp, ans;
bool used[200];
char s[N];
inline int re() {
	int x = 0; char ch = getchar(); bool f = 0;
	for(; ch>'9'||ch<'0'; ch = getchar())if(ch=='-')f = 1;
	for(; ch>='0'&&ch<='9'; ch = getchar()) x = x*10+ch-48;
	if(f) return -x;
	return x;
}
int main() {
	n = re();
	scanf("%s",s); len = strlen(s);

	int l=-1, r=-1;
	char last=s[0];
	for(int i = 0; i < len; ++i) {
		if(s[i]>='A'&&s[i]<='Z') {
			tmp = 0;
			memset(used,0,sizeof(used));
			continue;
		}
		if(!used[s[i]]) {
			used[s[i]] = 1;
			++tmp;
			if(tmp>ans)ans = tmp;
		}
	}
	printf("%d\n",ans);
	return 0;
}
