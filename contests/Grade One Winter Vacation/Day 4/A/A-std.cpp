#include <iostream>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;
const int maxn = 20010, maxm = 50010;
struct node
{
	int v, next;
}e[maxm];
int head[maxm];
int k;
int dfn[maxn], belong[maxn], low[maxn];
int indegree[maxn], outdegree[maxn];
bool ins[maxn];
stack <int> s;
int n, m;
int idx, scc;
int in, out;
void adde(int u, int v)
{
	e[k].v = v;
	e[k].next = head[u];
	head[u] = k++;
}
void init()
{
	k = 1;
	memset(head, -1, sizeof(head));
	memset(dfn, 0, sizeof(dfn));
	memset(ins, 0, sizeof(ins));
	memset(belong, 0, sizeof(belong));
	memset(indegree, 0, sizeof(indegree));
	memset(outdegree, 0, sizeof(outdegree));
	idx = scc = in = out = 0;
}
void input()
{
	int u, v;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		adde(u, v);
	}
}
void tarjan(int u)
{
	int v;
	low[u] = dfn[u] = ++idx;
	s.push(u);
	ins[u] = 1;
	for (int i = head[u]; i != -1; i = e[i].next)
	{
		v = e[i].v;
		if (!dfn[v])
		{
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if (ins[v])
			low[u] = min(low[u], dfn[v]);
	}
	if (low[u] == dfn[u])
	{
		scc++;
		do
		{
			v = s.top();
			s.pop();
			ins[v] = 0;
			belong[v] = scc;
		}
		while (u != v);
	}
}
void solve()
{
	for (int i = 1; i <= n; i++)
		if (!dfn[i])
			tarjan(i);
	if (scc == 1)
	{
		cout << "0\n";
		return;
	}
	for (int u = 1; u <= n; u++)
		for (int i = head[u]; i != -1; i = e[i].next)
		{
			int &v = e[i].v;
			if (belong[u] != belong[v])
			{
				indegree[belong[v]]++;
				outdegree[belong[u]]++;
			}
		}
	for (int i = 1; i <= scc; i++)
	{
		if (!indegree[i])
			in++;
		if (!outdegree[i])
			out++;
	}
	cout << max(in, out) << endl;
}
int main()
{
	while (cin >> n >> m)
	{
		init();
		input();
		solve();
	}
	return 0;
}