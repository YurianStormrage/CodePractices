#include <vector>
#include <ranges>
#include <algorithm>    // sort
#include <numeric>      // reduce
using namespace std;
using namespace views;  // take, drop
class Solution {
public:
    int maxmiumScore(vector<int>& cards, int cnt) {
        ranges::sort(cards, greater{});
        int ans = reduce(cards.begin(), cards.begin() + cnt, 0);
        auto odd = [] (int i) { return i & 1; };
        auto evn = [&](int i) { return !odd(i); };
        if (evn(ans)) return ans;
        auto a = ranges::find_if(cards | take(cnt) | views::reverse, odd);
        auto b = ranges::find_if(cards | take(cnt) | views::reverse, evn);
        auto c = ranges::find_if(cards | drop(cnt), odd);
        auto d = ranges::find_if(cards | drop(cnt), evn);
        auto m = a == cards.rend() || d == cards.end() ? 0 : ans - *a + *d;
        auto n = b == cards.rend() || c == cards.end() ? 0 : ans - *b + *c;
        return max(m, n);
    }
};
