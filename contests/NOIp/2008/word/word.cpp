#include <cstdio>
#include <cstring>
const int N = 105;
int len;
char s[N];
int num[150], maxN, minN=(int)1e9;
int ans;
int main() {
	scanf("%s",s); len = strlen(s);
	for(int i=0; i<len; ++i) {
		num[s[i]]++;
	}
	for(int i=0; i<len; ++i) {
		maxN = maxN>num[s[i]]? maxN:num[s[i]];
		minN = minN<num[s[i]]? minN:num[s[i]];
	}
	ans = maxN-minN;
	int lim = (int)sqrt(ans);
	for(int i=2; i<=lim; ++i)
		if(ans%i == 0)
			{printf("No Answer\n0\n"); return 0;}
	printf("Lucky Word\n%d\n",ans);
	return 0;
}