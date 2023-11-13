#include<iostream>
#define ll long long
#define MAX 100000
using namespace std;
ll sumx, sumy;
ll n, q,x,y;
bool vis[2][10 * MAX + 5];
int main()
{
    freopen("adjustment.in", "r", stdin);
    freopen("adjustment.out", "w", stdout);
	cin >> n >> q;
	x = y = n;
	sumx = sumy = n * (n + 1) / 2;
	for (int i = 1; i <= q; ++i)
	{
		char k;
		int a;
		cin >> k >> a;
		if (k == 'R')
		{
			if (vis[0][a])
			{
				cout << '0'<<endl;
				continue;
			}
			vis[0][a] = 1;
			cout << sumx + a * x<<endl;
			sumy -= a;
			y--;
		}
		if (k == 'C')
		{
			if (vis[1][a])
			{
				cout << '0'<<endl;
				continue;
			}
			vis[1][a] = 1;
			cout << sumy + a * y<<endl;
			sumx -= a;
			x--;
		}
	}
    fclose(stdin);
    fclose(stdout);
}
