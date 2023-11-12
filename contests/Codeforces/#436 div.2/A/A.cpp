#include <cstdio>
const int N = 105;
int n, x, key;
int a,b,used[N];
inline int re() {
	int x = 0; char ch = getchar(); bool f = 0;
	for(; ch>'9'||ch<'0'; ch = getchar())if(ch=='-')f = 1;
	for(; ch>='0'&&ch<='9'; ch = getchar()) x = x*10+ch-48;
	if(f) return -x;
	return x;
}
int main() {
	n = re();
	for(int i = 1; i <= n; ++i) {
		x = re();
		if(!used[x]) {
			++key;
			if(key==1)a=x;
			else if (key==2)b=x;
			else if(key>2) {printf("NO");return 0;}
		}
		used[x]++;
	}
	if(used[a]!=used[b])printf("NO");
	else printf("YES\n%d %d\n",a,b);
	return 0;
}
