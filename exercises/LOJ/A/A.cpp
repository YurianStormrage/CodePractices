#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define lowbit(x) (x)&(-(x))
const int N = 100005;
int n;
int bit[N];
int numtot;
struct number{int id, key;}num[N];
inline bool cmpK(number a, number b){return a.key < b.key;}
inline bool cmpI(number a, number b){return a.id < b.id;}

inline void addbit(int p) {
	for(int i = p; i <= n; i += lowbit(i))
		bit[i] += 1;
}

inline int sumbit(int p) {
	int res = 0;
	for(int i = p; i >= 1; i -= lowbit(i))
		res += bit[i];
	return res;
}

int main() {
	int ans = 0;
	char s[15];
	scanf("%d\n",&n);
	for(int i = 1; i <= n; ++i) {
		scanf("%s",s);
		if(s[0] == 'X') ++ans;
		else {
			int len = strlen(s)-1;
			int x = 0;
			for(int i = len; i >= 0; --i)
				x = (x<<1)+(x<<3)+s[i]-48;
			num[num[++numtot].id=numtot].key = x;
		}
	}
	if(n==1) printf("L");
	else if(ans&1) printf("W");
	else if(!ans) {
		sort(num+1,num+1+n,cmpK);
		for(int i = 1; i <= numtot; ++i)num[i].key = i;
		sort(num+1,num+1+n,cmpI);
		
		int res = 0;
		for(int i = numtot; i >= 1; --i) {
			res += sumbit(num[i].key-1);
			addbit(num[i].key);
		}
		
		if(res&1) printf("W");
		else printf("L");
	}
	else printf("L");
	return 0;
}
