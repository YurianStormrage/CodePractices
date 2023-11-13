#include <cstdio>
#include <queue>
using namespace std;
typedef long long ll;
int n, k;

inline ll rea()
{
    ll x = 0; char ch = getchar();
    for(; ch > '9' || ch < '0'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x;
}

struct fly
{
    ll time = 0,fee = 0;
    bool operator < (const fly & a)const {return fee < a.fee;}
}q[300000];

int main()
{
    n = rea(); k = rea();
    priority_queue<fly> q1;
    for(int i = 1;i <= n; ++i)
    {
        q[i].time = i;
        q[i].fee = rea();
        if(i <= k)
            q1.push(q[i]);
    }
    ll sum=0;
    for(int i = k+1;i <= k+n; ++i)
    {
        if(i <= n)
            q1.push(q[i]);
        sum += 1ll*(i-q1.top().time)*q1.top().fee;
        q[q1.top().time].time = i;
        q1.pop();
    }
    printf("%d\n", sum);
    for (int i = 1;i <= n; ++i) printf("%d ", q[i].time);
    return 0;
}
