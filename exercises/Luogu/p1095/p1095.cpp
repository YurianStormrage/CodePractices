#include <cstdio>
#include <cstdlib>

#define Min(a,b) ((a)<(b)?(a):(b))

int m, s, t, T;
int tmp, now, ans;

inline int re() {
    bool f = true; int x = 0; char ch = getchar();
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-')f = false;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1) + (x<<3) +ch -48;
    if(f)return x;
    return -x;
}

inline void check_t() {if(t<=0) {printf("No\n%d\n",now); exit(0);}}
inline void check_s() {if(now>=s) {printf("Yes\n%d\n",T-t); exit(0);}}

inline void calc()
{
	tmp = Min((s-now+16)/17, t);
	now += tmp*17; t -= tmp;
	check_s(); printf("No\n%d\n",now);
	exit(0);
}

int main()
{
    m = re(); s = re(); t = re(); T = t;
	tmp = Min(m/10, t); now += 60*tmp; t -= tmp;
	check_s(); check_t();
	m %= 10; if(m&1) m^=1;
	if(m)
	{
		tmp = (13-m)>>2;
		if(t<=tmp) calc();
		now += 60; t -= tmp+1;
		check_s(); check_t();
		m = m+(tmp<<2)-10;
	}
	if(m)
	{
		tmp = (13-m)>>2;
		if(t<=tmp) calc();
		now += 60; t -= tmp+1;
		check_s(); check_t();
	}
	if(t>=7&&s-now>=120)
	{
		tmp = Min(t/7,(s-now)/120);
		now += 120*tmp; t -= tmp*7;
		check_s(); check_t();
	}
	calc();
}
