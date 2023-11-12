#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = int(1e6)+5;
int len;
int nxt[N], g[N];
char s[N];
inline int re() {
	int x = 0; char ch = getchar(); bool f = 0;
	for(;ch>'9'||ch<'0';ch=getchar()) if(ch=='-')f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x = (x<<1)+(x<<3)+ch-48;
	if(f) return -x;
	return x;
}
inline void Getnext(char* s, int* next) {
	next[0] = -1;
	int len = strlen(s);
	int k;
	for(int i = 1; i < len; ++i) {
		k = next[i-1];
		while(s[k+1]!=s[i] && k!=-1) k = next[k];
		next[i] = k;
		if(s[k+1]==s[i]) ++next[i];
	}
}
int main() {
	scanf("%s",s);
	len = strlen(s);
	Getnext(s,nxt);
	for(int i = 1; i <= len; ++i) {
		int k = nxt[i-1];
		g[i] = i*i+f[i-1][0];
		while(k!=-1) {
			g[i] = max((i-k-1)*(i-k-1)+f[i-1][k+1],g[i]);
			k = nxt[k];
		}

	}
	printf("%d\n",g[len]);
	return 0;
}
