// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

int f[10001][101]{};//f[r][b_num] = maxV
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> r(n), v(n);
    int tot{};
    for (auto &x: r)cin >> x, tot += x;
    for (auto &x: v)cin >> x;
    vector<int> vv{v};
    sort(vv.begin(), vv.end(), greater<>());

    int b_num{}, sum{tot};
    for (int i{}; i < n; ++i) {
        if (sum > vv[i])sum -= vv[i], b_num++;
        else {
            b_num++;
            break;
        }
    }
    cout << b_num << ' ';

    memset(f, -1, sizeof(f));
    f[0][0] = 0;
    for (int i{}; i < n; ++i)
        for (int j{tot}; j >= r[i]; --j)
            for (int k{1}; k <= b_num; ++k)
                if(f[j-r[i]][k-1]!=-1)f[j][k] = max(f[j][k], f[j-r[i]][k-1] + v[i]);
    int min_trans = 1e9;
    for (int j{};j<=tot;++j)
        if(f[j][b_num]>=tot)
            min_trans = min(min_trans, tot - j);
    cout << min_trans;
    return 0;
}