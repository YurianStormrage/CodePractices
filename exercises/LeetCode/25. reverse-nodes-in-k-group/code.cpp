#include <bits/stdc++.h>
using namespace std;


/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * 2025/3/6的写法
 */
class Solution_0 {
    int k;
    // auto fetch_k_node(ListNode* head, int k) -> pair<ListNode*, ListNode*> {
    //     auto cur = head;
    //     while (k-- && cur) {
    //         cur = cur->next;
    //     }
    //     return {head, cur};
    // }
    // auto reverse(ListNode* head) -> ListNode* {
    //     auto cur = head;

    // }
    auto reverse_k(auto& head) {
        if (!head) return 1;
        auto cur = head->next, lst = head;
        auto tail = head;
        int k = this->k - 1;
        while (k-- && tail) {
            tail = tail->next;
        }
        if (!tail) return 1;
        k = this->k - 1;
        while (k--) {
            // printf("cur: %d\n", cur->val);
            auto tmp = cur->next;
            cur->next = lst;
            lst = cur;
            cur = tmp;
        }
        head->next = cur;
        // printf("head nxt: %d\n", head->next->val);
        head = lst;
        return 0;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        this->k = k;
        auto tail = head;
        reverse_k(head);
        // printf("head: %d\n", head->val);
        // cout << "tail: " << tail->val << endl;
        while (tail) {
            auto tmp = tail->next;
            // printf("tmp: %d\n", tmp->val);
            if (reverse_k(tail->next)) {
                break;
            }
            tail = tmp;
            // cout << "tail: " << tail->val << endl;
        }
        return head;
    }
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k <= 1) return head;
        auto cur = head;
        ListNode FA(0, head);
        auto fa = &FA;

        int cnt = 0;
        while (cur) {
            // 枚举每个节点
            // 获取k个节点后翻转整段链表
            // 并重置状态机
            auto nxt = cur->next;
            if (++cnt == k) {
                // 翻转链表
                auto pre = fa->next;
                // 从pre->next开始，令i->next=fa(i)
                // 特殊处理头尾两个节点，即pre和cur
                auto i = pre->next;
                while (--cnt) {
                    auto tmp = i->next;
                    i->next = pre;
                    pre = i;
                    i = tmp;
                }
                fa->next->next = nxt;
                auto tmp = fa->next;
                fa->next = cur;
                fa = tmp;
            }
            cur = nxt;
        }
        return FA.next;
    }
};

int main() {
    struct Test : Solution {
        vector<int> nums;
        int target;
        auto createList(const vector<int>& nums) -> ListNode* {
            ListNode* head = nullptr;
            ListNode* tail = nullptr;
            for (auto n: nums) {
                auto node = new ListNode(n);
                if (!head) {
                    head = node;
                    tail = node;
                } else {
                    tail->next = node;
                    tail = node;
                }
            }
            return head;
        }
        void run() {
            auto ans = reverseKGroup(createList(nums), target);
            while (ans) {
                cout << ans->val << " ";
                ans = ans->next;
            }
            cout << endl;
        }
    };

    Test t1 {
        .nums = {1,2,3,4,5},
        .target = 2
    };
    Test t2 {
        .nums = {1,2,3,4,5},
        .target = 3
    };

    t1.run();
    t2.run();

    return 0;
}