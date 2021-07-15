#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read()
{
    ll x = 0; char ch = getchar(); bool f = 1;
    while(ch > '9' || ch < '0') {if(ch == '-') f = 0; ch = getchar();}
    while(ch >= '0' && ch <= '9') {x = (x<<1)+(x<<3)+(ch^48); ch = getchar();}
    return f ? x : -x;
}
int n;
map<string, int> bd;
int def;
string ans;
int main()
{
    string name;
    n = read();
    for(int i = 1; i <= n; ++i)
        cin >> name,
        bd[name] = i;
    for(int i = 1; i <= n; ++i) {
        cin >> name;
        int tmp = bd[name] - i;
        if(tmp > def) {
            def = tmp;
            ans = name;
        }
    }
    if(def == 0) puts("suspicious");
    else cout << ans;
    return 0;
}