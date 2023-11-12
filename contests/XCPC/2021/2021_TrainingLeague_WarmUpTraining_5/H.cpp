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
const int N = 1e4 + 2;
int n;
vector<string> num;
vector<string> ans;

void trans_to_min(string& s, const int& p) {
    int len = s.length();
    for(int i = p; i < len; ++i)
        if(s[i] == '9')
            s[i] = '6';
}

int main()
{
    n = read();
    for(int i = 0; i < n; ++i) {
        string tmp;
        cin >> tmp;
        num.emplace_back(tmp);
    }
    string last = "0";
    for(string now : num) {
        if(now.length() < last.length()) {
            printf("impossible");
            return 0;
        }
        if(now.length() > last.length()) {
            trans_to_min(now, 0);
            ans.emplace_back(now);
            last = now;
            continue;
        }
        int len = now.length(), pos = -1;
        for(int i = 0; i < len; ++i) {
            if(now[i] == '6') pos = i;
            else if(now[i] == '9') now[i] = '6', pos = i;
            if(last[i] > now[i]) {
                if(pos == -1) {
                    printf("impossible");
                    return 0;
                }
                now[pos] = '9';
                if(pos == i && last[i] == '9') {
                    for(pos -= 1; pos >= 0; --pos)
                        if(now[pos] == '6')
                            break;
                    continue;
                }
                trans_to_min(now, pos + 1);
                break;
            }
            else if(last[i] < now[i]) {
                trans_to_min(now, i + 1);
                break;
            }
        }
        ans.emplace_back(now);
        last = now;
    }
    puts("possible");
    for(auto & s : ans) cout << s << endl;
    return 0;
}