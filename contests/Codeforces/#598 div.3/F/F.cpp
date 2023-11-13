#include <cstdio>
#include <cstring>
typedef long long ll;
const int N = (int)2e5+2;
int q, n;
int cnt[26];
char s[N], a[N];
bool used[26];
inline ll read()
{
    ll x = 0; char ch = getchar();
    for(; ch > '9' || ch < '0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}
int main()
{
    q = read();
    while(q--)
    {
        n = read();
        scanf("%s%s",s,a);
        bool flag = 0, Fail = 0;
        memset(used, 0, sizeof(used));
        for(int i = 0; i < n; ++i)
        {
            if(used[s[i]-'a']) flag = true;
            used[s[i]-'a'] = 1;
        }
        for(int i = 0; i < n; ++i) if(!used[a[i]-'a']) {Fail = true; break;}
        if(Fail) {puts("NO"); continue;}
        if(flag) {puts("YES"); continue;}
        int res_1 = 0, res_2 = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = s[i]-'a'-1; j >= 0; j--) res_1 += cnt[j];
            cnt[s[i]-'a']++;
        }
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < n; ++i)
        {
            for(int j = a[i]-'a'-1; j >= 0; j--) res_2 += cnt[j];
            cnt[a[i]-'a']++;
        }
        memset(cnt, 0, sizeof(cnt));
        if((res_1&1) == (res_2&1)) puts("YES");
        else puts("NO");
    }
    return 0;
}