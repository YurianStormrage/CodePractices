#include <bits/stdc++.h>
#include <cstdio>
#include <string>
using namespace std;

class Solution {
public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        constexpr int mod = (int)1e9 + 7;
        map<tuple<int, int, bool, bool>, int> mem;
        // string now;
        int cur = 0;
        int sum = 0;
        bool greater = false;
        bool less = false;
        num1 = string(num2.size() - num1.size(), '0') + num1;
        auto dfs = [
            _dfs = [&](auto&& self) {
                static auto update = [&](char c) {
                    // now += c;
                    sum += c - '0';
                    ++cur;
                };
                static auto fallback = [&](char c) {
                    sum -= c - '0';
                    // now.pop_back();
                    --cur;
                };
                // static auto not_less_than = [&](string const& num) {
                //     return now.size() > num.size() ||
                //            (now.size() == num.size() && now >= num);
                // };
                static auto check = [&]() {
                    return sum >= min_sum &&
                           sum <= max_sum;
                };

                if (cur >= num2.size()) {
                    // cout << "end " << now
                    //      << " = " << check()
                    //      << endl;
                    return (int)check();
                }

                if (mem.find({cur, sum, less, greater}) != mem.end()) {
                    // cout << "mem " << now
                    //      << " = " << mem[{cur, sum, less, greater}]
                    //      << endl;
                    return mem[{cur, sum, less, greater}];
                }

                int res = 0;

                // static auto mod_add = [&](int val) {
                //     res += val;
                //     if (res >= mod)
                //         res -= mod;
                // };
                #define mod_add(val) do { \
                    res += val; \
                    if (res >= mod) \
                        res -= mod; \
                } while (false)
                // static auto do_search = [&](char l, char r) {
                //     for (char i = l; i <= r; ++i) {
                //         update(i);
                //         if (sum > max_sum) {
                //             fallback(i);
                //             break;
                //         }
                //         mod_add(self(self));
                //         fallback(i);
                //     }
                // };
                #define do_search(l, r) do { \
                    for (char i = l; i <= r; ++i) { \
                        update(i); \
                        if (sum > max_sum) { \
                            fallback(i); \
                            break; \
                        } \
                        mod_add(self(self)); \
                        fallback(i); \
                    } \
                } while (false)

                if (less && greater) {
                    do_search('0', '9');
                } else if (!less && greater) {
                    do_search(num1[cur], num1[cur]);
                    less = true;
                    do_search(num1[cur] + 1, '9');
                    less = false;
                } else if (less && !greater) {
                    do_search(num2[cur], num2[cur]);
                    greater = true;
                    do_search('0', num2[cur] - 1);
                    greater = false;
                } else {
                    if (num1[cur] == num2[cur]) {
                        do_search(num1[cur], num1[cur]);
                    } else {
                        greater = true;
                        do_search(num1[cur], num1[cur]);
                        less = true;
                        do_search(num1[cur] + 1, num2[cur] - 1);
                        greater = false;
                        do_search(num2[cur], num2[cur]);
                        less = false;
                    }
                }

                // cout << "res " << now << " = " << res << endl;
                return mem[{cur, sum, less, greater}] = res;
            }
        ]() { return _dfs(_dfs); };
        return dfs();
    }
};

int main() {
    // freopen("out.txt", "w", stdout);
    struct Test : Solution {
        string num1, num2;
        int min_sum, max_sum;
        void run() {
            auto ans = count(num1, num2, min_sum, max_sum);
            cout << ans << endl;
        }
    };

    Test t1 {
        .num1 = "1",
        .num2 = "12",
        .min_sum = 1,
        .max_sum = 8
    };
    Test t2 {
        .num1 = "1",
        .num2 = "5",
        .min_sum = 1,
        .max_sum = 5
    };

    t1.run();
    t2.run();

    Test e1 {
        .num1 = "4179205230",
        .num2 = "7748704426",
        .min_sum = 8,
        .max_sum = 46
    };
    e1.run();

    return 0;
}