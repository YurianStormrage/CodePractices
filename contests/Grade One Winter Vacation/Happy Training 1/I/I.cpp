#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

struct bignum
{
    int num[1002];
    int len;

    bignum(){len = 0; memset(num, 0, sizeof(num));}

    inline void pushup()
    {
        while(num[len] > 9)
        {
            num[len+1] = num[len]/10;
            num[len] %= 10;
            ++len;
        }
    }

    inline void input()
    {
        char tmp[1002];
        scanf("%s", tmp);
        len = strlen(tmp);
        for(int i = 0, j = len; j; ++i, --j) num[j] = tmp[i]^48;
    }
    inline void print() {for(int i = len; i; --i) putchar(num[i]^48);}

    inline void operator =(int val)
    {
        num[1] = val;
        len = 1;
        pushup();
    }
    inline void operator *=(int val)
    {
        for(int i = 1; i <= len; ++i) num[i] *= val;
        for(int i = 1; i < len; ++i)
            if(num[i] > 9)
            {
                num[i+1] += num[i]/10;
                num[i] %= 10;
            }
        pushup();
    }
    inline void operator -=(bignum x)
    {
        for(int i = x.len; i; --i)
        {
            num[i] -= x.num[i];
            int j = i;
            while(num[j] < 0)
            {
                num[j++] += 10;
                num[j]--;
            }
        }
        for(; len > 1 && !num[len];) --len;
    }
    inline bool operator >(bignum x)
    {
        if(len > x.len) return 1;
        if(len < x.len) return 0;
        for(int i = len; i; --i)
        {
            if(num[i] > x.num[i]) return 1;
            if(num[i] < x.num[i]) return 0;
        }
        return 0;
    }
    inline bool operator >=(bignum x)
    {
        if(len > x.len) return 1;
        if(len < x.len) return 0;
        for(int i = len; i; --i)
        {
            if(num[i] > x.num[i]) return 1;
            if(num[i] < x.num[i]) return 0;
        }
        return 1;
    }
    inline bool operator ==(bignum x)
    {
        if(len != x.len) return 0;
        for(int i = len; i; --i)
            if(num[i] != x.num[i]) return 0;
        return 1;
    }
};

struct people
{
    char name[21];
    bignum v;
}p[1002];

inline bool cmp(people a, people b) {return a.v > b.v;}

inline ll read()
{
    ll x = 0; char ch = getchar();
    for(; ch > '9' || ch <'0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}

int ans[1002];

int main()
{
	int n = read();
    bignum sum;
    sum.input();
    for(int i = 1; i <= n; ++i)
    {
        scanf("%s", p[i].name);
        p[i].v.input();
    }
    sort(p+1, p+1+n, cmp);
    /*
    for(int i = 1; i <= n; ++i)
    {
        printf("%s ", p[i].name);
        p[i].v.print();
        puts("");
    }
    */
    bignum zero;
    zero = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(sum >= p[i].v)
        {
            sum -= p[i].v;
            ans[++ans[0]] = i;
            if(sum == zero)
            {
                printf("%d\n", ans[0]);
                for(int j = 1; j <= ans[0]; ++j)
                    printf("%s\n", p[ans[j]].name);
                return 0;
            }
        }
    }
    putchar('0');
    return 0;
}