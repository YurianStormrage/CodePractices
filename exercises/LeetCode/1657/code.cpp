#include <bits/stdc++.h>
#include <set>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        auto get_num = [](string const& str) {
            int num[26] = {0};
            multiset<int> res;
            for (auto & ch : str) {
                ++num[ch - 'a'];
            }
            for (int i = 0; i < 26; ++i) {
                if (num[i]) {
                    res.emplace(num[i]);
                    res.emplace(i);
                }
            }
            return res;
        };
        return get_num(word1) == get_num(word2);
    }
};

/// error1: 字符种类必须相同
/// solution: 先统计字符数判断字符种类是否相同，再排序统计数组判断字符数量是否相等
///           multiset常数稍大一些