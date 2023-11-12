#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
int n;
string a[2], olds, news;
int main() {
	cin >> a[0] >> a[1];
	scanf("%d",&n);
	cout << a[0] << ' ' << a[1] << endl;
	for(int i = 1; i <= n; ++i) {
		cin >> olds >> news;
		if(a[0] == olds)a[0] = news;
		else a[1] = news;
		cout << a[0] << ' ' << a[1] << endl;
	}
	return 0;
}
