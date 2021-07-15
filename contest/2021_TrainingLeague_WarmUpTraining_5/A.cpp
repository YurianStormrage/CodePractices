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
int stu[42];
double ans;
int main()
{
    n = read();
    for(int i = 1; i <= n; ++i) stu[i] = read();
    sort(stu+1, stu+n+1, greater<int>());
    double pro = 1;
    for(int i = 1; i <= n; ++i) {
        pro *= 0.5;
        ans += pro * stu[i];
    }
    printf("%.5lf", ans);
    return 0;
}
