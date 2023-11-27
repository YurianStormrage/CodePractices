#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    #define l pos[ch][0]
    #define m pos[ch][1]
    int uniqueLetterString(string s) 
    {
        int ans = 0, now = 0, pos[26][2];
        memset(pos, -1, sizeof(pos));
        for (int r = 0; r < s.size(); ++r) {
            char ch = s[r] - 'A';
            now += r + l - (m << 1); // now += (r - m) - (m - l)
            ans += now; // 同时统计当前所有字符的贡献值
        }
        return ans;
    }
    #undef m
    #undef l
};