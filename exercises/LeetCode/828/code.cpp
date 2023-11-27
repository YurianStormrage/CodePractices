#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> pos_[26];
    inline vector<int> & pos(char ch) noexcept {
        return pos_[ch - 'A'];
    }
public:
    int uniqueLetterString(string s) {
        long long n = s.length();
        for (int i = 0; i < n; ++i) {
            pos(s[i]).emplace_back(i);
        }
        /* sum((n - i + 1) * i), i = 1, ..., n */
        long long ans = ((n + 1) * n * (n + 1) >> 1) - (n * (n + 1) * ((n << 1) + 1)) / 6;
        for (char ch = 'A'; ch <= 'Z'; ++ch) {
            if (pos(ch).size() <= 1) continue;
            ans -= (pos(ch)[0] + 1) * (n - pos(ch)[1]);
            int lim = pos(ch).size() - 1;
            for (int i = 1; i < lim; ++i) {
                int a = pos(ch)[i - 1];
                int b = pos(ch)[i];
                int c = pos(ch)[i + 1];
                ans -= (a + 1) * (n - b);
                ans -= (b + 1) * (n - c);
                ans += (a + 1) * (n - c);
            }
            ans -= (pos(ch)[lim - 1] + 1) * (n - pos(ch)[lim]);
        }
        return ans;
    }
};

int main()
{
    struct Test : Solution {
        string s;
        void run() {
            auto ans = uniqueLetterString(s);
            cout << ans << endl;
        }
    };

    Test t1 {
        .s = "ABC"
        // 10
    };
    Test t2 {
        .s = "ABA"
        // 8
    };
    Test t3 {
        .s = "LEETCODE"
        // 92
    };

    t1.run();
    t2.run();
    t3.run();
    
    return 0;
}