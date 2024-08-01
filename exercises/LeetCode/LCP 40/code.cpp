#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxmiumScore(vector<int>& cards, int cnt) {
        sort(cards.begin(), cards.end(), greater());
        int odd = 0, even = 0;
        int ans = 0, cur = 0;
        const int n = cards.size();
        for (int i = 0; i < cnt; ++i) {
            if (cards[i] & 1) ++odd;
            cur += cards[i];
        }
        if ((odd & 1) == 0) return cur;
        if (cnt == n) return 0;
        int i = cnt - 1, j = cnt;
        for (; i >= 0 && 0 == (cards[i] & 1); --i);
        for (; j < n && 0 == (cards[j] & 1); ++j);
        if (cnt > odd && j < n) {
            if (i == cnt - 1) {
                int l = i;
                for (; l >= 0 && (cards[l] & 1) == 1; --l);
                ans = cur - cards[l] + cards[j];
            }
            else ans = cur - cards[cnt - 1] + cards[j];
        }
        if (j > cnt) {
            ans = max(ans, cur - cards[i] + cards[cnt]);
        } else {
            for (; j < n && (cards[j] & 1) == 1; ++j);
            if (j < n)
                ans = max(ans, cur - cards[i] + cards[j]);
        }
        return ans;
    }
};
