#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += cardPoints[i];
        }
        int ans = sum;
        for (int i = 0; i < k; ++i) {
            sum -= cardPoints[k - i - 1];
            sum += cardPoints[n - i - 1];
            ans = max(ans, sum);
        }
        return ans;
    }
};

int main() {
    struct Test : Solution {
        vector<int> cardPoints;
        int k;
        void run() {
            auto ans = maxScore(cardPoints, k);
            cout << ans << endl;
        }
    };

    Test t1 {
        .cardPoints = {1,2,3,4,5,6,1},
        .k = 3
    };
    Test t2 {
        .cardPoints = {2,2,2},
        .k = 2
    };
    Test t3 {
        .cardPoints = {9,7,7,9,7,7,9},
        .k = 7
    };
    Test t4 {
        .cardPoints = {1,1000,1},
        .k = 1
    };
    Test t5 {
        .cardPoints = {1,79,80,1,1,1,200,1},
        .k = 3
    };

    t1.run();
    t2.run();
    t3.run();
    t4.run();
    t5.run();

    return 0;
}