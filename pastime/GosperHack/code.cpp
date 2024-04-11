#include <cstdlib>
#include <iostream>
#include <bitset>
// static inline auto lowbit(auto x) {
//     return x & -x;
// }
int main()
{
    int n;
    int k;
    std::cin >> n >> k;
    int start = (1 << k) - 1;
    int limit = 1 << n;
    for (int i = start; i < limit;) {
        std::cout << std::bitset<10>(i) << std::endl;
        int lb = i & -i;
        // int tail = i & ~(i + lb);
        // tail -= (tail + lb) >> 1;
        // i = (i + lb) | tail / lb;
        /// Gosper's Hack
        int r = i + lb;
        i = ((i ^ r) >> 2) / lb | r;
    }
    return 0;
}