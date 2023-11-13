#include <cstdio>
typedef long long ll;
const int N = (int)1e5+2;

int n, k;
//bool isnP[320];

int p[66] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277,
281, 283, 293, 307, 311, 313, 317};

int hashmap[N];
ll ans;

inline ll read()
{
	ll x = 0; char ch = getchar();
	for(; ch>'9'||ch<'0'; ch = getchar());
	for(; ch>='0'&&ch<='9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
	return x;
}
/*
inline void getPrime()
{
	for(int i = 2; i < 320; ++i)
	{
		if(!isnP[i]) p[pTot++] = i;
		for(int j = 0; j < pTot && p[j]*i < 320; ++j)
		{
			isnP[p[j]*i] = 1;
			if(i%p[j] == 0) break;
		}
	}
}
*/
inline void solve(int x)
{
	ll ans1 = 1, ans2 = 1;
	int cnt;
	for(int i = 0; i < 66; ++i)
	{
		cnt = 0;
		if(x < p[i]) break;
		while(!(x%p[i]))
		{
			x /= p[i];
			++cnt;
		}
		cnt %= k;
		for(int j = cnt; j; --j) ans1 *= p[i];
		for(int j = (k-cnt)%k; j; --j)
		{
			if(ans2 > N) break;
			ans2 *= p[i];
		}
	}
	if(x != 1)
	{
		ans1 *= x;
		for(int j = k-1; j; --j) {if(ans2 > N) break; ans2 *= x;}
	}
	if(ans2 < N) ans += hashmap[ans2];
	++hashmap[ans1];
}
int main()
{
    n = read(); k = read();
    //getPrime();
	for(int i = 1; i <= n; ++i) solve(read());
	printf("%lld",ans);
    return 0;
}