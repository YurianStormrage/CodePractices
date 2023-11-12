#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 2000010;
int n, x, y, f, d;
ll cnt[N];
ll sum[N], ans = ll(1e18), tmp;
inline int re() {
	int x = 0; char ch = getchar(); bool f = 0;
	for(; ch>'9'||ch<'0'; ch = getchar()) if(ch == '-')f = 1;
	for(; ch>='0'&&ch<='9'; ch = getchar()) x = (x<<1)+(x<<3)+ch-48;
	if(f) return -x;
	return x;
}

int main() {
	n = re(); x = re(); y = re();
	f = x/y;
//	int lim=0, limp;
	for(int i = 1, t; i <= n; ++i) {
		t = re();
		++cnt[t];
		sum[t] += t;
//		lim = max(lim, t);
	}
//	limp = lim<<1;
	
	for(int i = 2; i <= /*limp*/2e6; ++i) cnt[i]+=cnt[i-1], sum[i] += sum[i-1];
	
	for(int i = 2; i <= /*lim*/1e6; ++i) {
		tmp = 0;
		for(int j = i; j <= /*limp*/2e6; j += i) {
			d = min(f, i-1);
			tmp += ((cnt[j]-cnt[j-d-1])*j-(sum[j]-sum[j-d-1]))*y;
			tmp += (cnt[j-d-1]-cnt[j-i])*x;
		}
		ans = min(ans, tmp);
	}
	printf("%lld",ans);
	return 0;
}
//Solution:
//define cost(g) the cost if we want gcd of the array becomes g
//the answer is min(cost(g)) for g>1 
//now for each multiple of g like k,
//let's find the cost of numbers in the range (k - g, k],
//and sum up these values. 
//We must find the best f
//and divide the range into two segments (k - g, f] and (f, k]
//and delete the numbers in the first range
//and add the numbers in second range till they become k.
//the total cost for this range is ()
//cnt(k - g + 1, k - f) × x + (cnt(k - f+ 1, k) × k - sum(k - f + 1, k)) × y.
//
//* "lim" in my code is unavailable while there the maximum of a[i] equal to 1
//* a[i] is in the range [1, 1e6], however, j is no greater than 2e6.
//  that's because there couold be some numbers which is greater than i while i*2 is greater than 1e6
//
// That's all










