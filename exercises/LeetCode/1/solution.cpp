#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<int, int> exists;
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        exists.reserve(nums.size());
        int i = 0;
        for (auto x : nums) {
            if (exists.contains(target - x)) [[unlikely]]
                return {exists[target - x], i};
            exists.insert({x, i++});
        }
        return {-1, -1};
    }
};