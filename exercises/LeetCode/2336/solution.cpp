#include <bits/stdc++.h>
using namespace std;

class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
        threshold_ = 1;
    }
    
    int popSmallest() {
        if(!nums_set_.empty()) {
            int val = *nums_set_.begin();
            nums_set_.erase(nums_set_.begin());
            return val;
        }
        // 如果nums_set为空了，就只能把当前的threshold给弹出去了
        return threshold_++;
    }
    
    void addBack(int num) {
        if(num < threshold_) {
            nums_set_.insert(num);
        }
        // else 如果大于则不用管，因为都有
    }
private:
    // 表示当前无限集中大于等于这个数的都有
    int threshold_;
    // 表示小于threshold的零散集合
    set<int> nums_set_;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */