#include <bits/stdc++.h>
#include <bitset>
using namespace std;

class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
        s.set();
        s.reset(0);
    }
    
    int popSmallest() {
        int res = s._Find_first();
        s.reset(res);
        return res;
    }
    
    void addBack(int num) {
        s.set(num);
    }
private:
    bitset<1002> s;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
