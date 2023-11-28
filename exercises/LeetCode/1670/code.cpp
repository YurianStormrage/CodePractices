#include <bits/stdc++.h>
#include <deque>
#include <vector>
using namespace std;

class FrontMiddleBackQueue {
public:
    FrontMiddleBackQueue() {
    }
    
    void pushFront(int val) {
        q.push_front(val);
    }
    
    void pushMiddle(int val) {
        q.insert(q.begin() + (q.size() >> 1), val);
    }
    
    void pushBack(int val) {
        q.push_back(val);
    }
    
    int popFront() {
        if (q.empty())
            return -1;
        int res = q.front();
        q.pop_front();
        return res;
    }
    
    int popMiddle() {
        if (q.empty())
            return -1;
        int res = *(q.begin() + ((q.size() - 1) >> 1));
        q.erase(q.begin() + ((q.size() - 1) >> 1));
        return res;
    }
    
    int popBack() {
        if (q.empty())
            return -1;
        int res = q.back();
        q.pop_back();
        return res;
    }
private:
    deque<int> q;
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */