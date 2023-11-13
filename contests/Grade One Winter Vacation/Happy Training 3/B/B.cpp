#include<queue>
#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
#define N  10004
#define Max  504
int n, len, sum;
queue<int>q, q1, q2;
int num[N][Max], power[Max];
void add(int *x, int *y, int *z)
{
	for (int i = 0; i < Max ; ++i) 
		z[i] = x[i] + y[i];
	for (int i = 0; i < Max ; ++i)
	{
		z[i + 1] += (z[i] >> 1);
		z[i] &= 1;
	}
}
void ten_two(int *a)
{
	for (int i = Max - 4; i >=0; --i) 
		if (a[i])
		{
			a[i] = 0;
			a[i + 1]++;
			a[i + 3]++;
		}
	for (int i = 0; i < Max - 5; ++i)
	{
		a[i + 1] += (a[i] >> 1);
		a[i] &= 1;
	}
}

int main()
{
	freopen("binary.in", "r", stdin);
	freopen("binary.out", "w", stdout);
	cin >> n;
	if (n == 1) 
	{ 
		cout << '1';
		return 0; 
	}
	num[++sum][0] = 0;
	num[++sum][0] = 1;
	power[0] = 1;
	q.push(1); 
	q.push(2);
	while (1)
	{
		++len; 
		ten_two(power);
		while (!q.empty())
		{
			int x = q.front(); 
			q.pop();
			if (num[x][len] == 1) continue;
			--n; 
			++sum;
			q1.push(x); q2.push(sum);
			add(num[x], power, num[sum]);
			if (n==1)
			{
				for (int i = len; i>=0; --i) cout << num[sum][i];
				return 0;
			}
			
		}
		while (!q1.empty()) q.push(q1.front()), q1.pop();
		while (!q2.empty()) q.push(q2.front()), q2.pop();
	}
	return 0;
}
