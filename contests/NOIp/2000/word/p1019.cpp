#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 25, maxm = 105;
int n;
int num[maxn][maxn];
char s[maxn][maxm];
inline void init() {
	scanf("%d\n",&n);
	for(int i = 0; i < n; ++i)
		scanf("%s", s[i]);
	
	int l, r, lim, len;
	for(int i = 0; i< n; ++i) {
		for(int j = 0; j < n; ++j) {
			len = strlen(s[j]);
			l = strlen(s[i]) - 1; r = 0;
			int sum = 0;
			for(; l && r < len; --l, ++r) {
				if()
			}
		}
	}
}
int main() {
	init();
	scanf("%d\n",&n);
	for(int i = 0; i < n; ++i)
		scanf("%s",s[i]);
	
	
	return 0;
}
