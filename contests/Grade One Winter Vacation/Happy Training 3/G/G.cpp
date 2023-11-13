#include<iostream>
#include<cstdio>
#include<cstring>
#define Max 1000
using namespace std;
int n, k, pos[1000];
int  x, a, b, c;
struct {
	int v, id;
}can[Max*10+4][2];
bool vis[1000];
int main()
{
	freopen("generators.in", "r", stdin);
	freopen("generators.out","w",stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{
		cin >> x >> a >> b >> c;
		int t = x;
		can[i][0].id = can[i][0].v = can[i][1].id = can[i][1].v = -1;
        memset(vis, 0, sizeof(vis));
		memset(pos, 0, sizeof(pos));
		vis[x] = 1;
		pos[x] = 0;
		for (int p = 1; ; p++)
		{
			t = (a * t + b) % c;
			if (vis[t]) break;
			vis[t] = 1;
			pos[t] = p;
		}
		for (int p = c - 1; p >= 0 ; p--)
		{
			if (!vis[p])continue;
			if (p >= can[i][0].v)
			{
				if (p % k != can[i][0].v % k)can[i][1] = can[i][0];
				can[i][0].v = p, can[i][0].id = pos[p];
			}
			else if (p > can[i][1].v&& p% k != can[i][0].v % k)
				can[i][1].v = p, can[i][1].id = pos[p];
			if (can[i][1].v != -1 && can[i][0].v!= -1)break;
		}	
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		ans += can[i][0].v;
	}
	if (ans % k)
	{
		cout << ans << endl;
		for (int i = 1; i <= n; ++i)
			cout << can[i][0].id << ' ';
	}
	else
	{
		int p = 0;
		can[0][0].v = 0x7f7f7f7f;
		can[0][1].v = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (can[i][1].v == -1) continue;
			if (can[i][0].v - can[i][1].v < can[p][0].v - can[p][1].v)
				p = i;
		}
		if (p == 0)
		{
			cout << -1;
			return 0;
		}
		ans -= can[p][0].v - can[p][1].v;
		cout << ans << endl;
		can[p][0] = can[p][1];
		for (int i = 1; i <= n; ++i)
			cout << can[i][0].id << ' ';
	}
}
