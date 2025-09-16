#include <bits/stdc++.h>
using namespace std;
using Vec = vector<uint8_t>; // equal to String
// using Vec = string;
// given Vec a, b; if a < b, s.t. f(a) > f(b)
// {} must be the minimum, but how to make f({}) be the maximum?
class ReverseVec: public Vec {
public:
    ReverseVec(auto&& args): Vec(std::forward<decltype(args)>(args)) {}
    virtual bool operator <(const Vec& rhs) const {
        return Vec(*this) > Vec(rhs);
    }
    virtual bool operator >(const Vec& rhs) const {
        return Vec(*this) < Vec(rhs);
    }
};

unordered_set<const Vec*> memo;
Vec f(const Vec& x) {
    auto y(x);
    cout << "x address: " << &x << ", y address: " << &y << endl;
    memo.insert(&y);
    return y;
}

auto operator<(const Vec& lhs, const Vec& rhs) -> bool {
    bool is_memoized = memo.contains(&lhs) && memo.contains(&rhs);
    cout << "is_memoized: " << is_memoized << endl;
    if (is_memoized) {
        cout << "lhs address: " << &lhs << ", rhs address: " << &rhs << endl;
        cout << "comparing memoized\n" << endl;
        for (auto& v: memo) {
            cout << "memo address: " << v << endl;
        }
        return lhs > rhs; // Error: infinite recursion. Need to call the original operator.
        // TODO: implement a for loop to compare each element.
    }
    return lhs < rhs;
}
auto operator>(const Vec& lhs, const Vec& rhs) -> bool {
    bool is_memoized = memo.contains(&lhs) && memo.contains(&rhs);
    cout << "is_memoized: " << is_memoized << endl;
    if (is_memoized) {
        cout << "lhs address: " << &lhs << ", rhs address: " << &rhs << endl;
        cout << "comparing memoized\n" << endl;
        for (auto& v: memo) {
            cout << "memo address: " << v << endl;
        }
        return lhs < rhs;
    }
    return lhs > rhs;
}

int main()
{
    Vec a{1, 2, 3, 4};
    Vec b{1};
    auto c = f(a);
    auto d = f(b);
    cout << "a address: " << &a << ", b address: " << &b << endl;
    cout << "a < b: " << (a < b) << endl;
    cout << "f(a) > f(b): " << (c > d) << endl;
    return 0;
}