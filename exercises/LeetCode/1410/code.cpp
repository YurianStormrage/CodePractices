#include <bits/stdc++.h>
#include <ostream>
using namespace std;

class Solution {
public:
    string entityParser(string text) {
        map<string, string> dictionary {
            {"&quot;", "\""},
            {"&apos;", "\'"},
            {"&amp;", "&"},
            {"&gt;", ">"},
            {"&lt;", "<"},
            {"&frasl;", "/"}
        };
        size_t len = text.length();
        string ans; ans.reserve(len);
        size_t i = 0, j;
        while(i < len) {
            j = text.find('&', i);
            if (j >= len) [[unlikely]]
                break;
            ans += text.substr(i, j - i);
            i = text.find(';', j);
            if (i >= len) [[unlikely]] {
                i = j;
                break;
            }
            auto tmp = text.substr(j, ++i - j);
            do {
                if (dictionary.contains(tmp)) [[likely]] {
                    ans += dictionary.at(tmp);
                    break;
                }
                else {
                    auto k = tmp.find('&', 1);
                    if (k >= tmp.length()) {
                        ans += tmp;
                        break;
                    }
                    ans += tmp.substr(0, k);
                    tmp = tmp.substr(k);
                }
            } while (tmp.size());
        }
        if (i < len) [[likely]]
            return ans + text.substr(i);
        return ans;
    }
};

int main() {
    struct Test : Solution {
        string text;
        void run() {
            auto ans = entityParser(text);
            cout << ans << endl;
        }
    };

    Test t1 {.text = "&amp; is an HTML entity but &ambassador; is not."};
    Test t2 {.text = "and I quote: \"...\""};
    Test t3 {.text = "Stay home! Practice on Leetcode :)"};
    Test t4 {.text = "x &gt; y &amp;&amp; x &lt; y is always false"};
    Test t5 {.text = "leetcode.com&frasl;problemset&frasl;all"};

    t1.run();
    t2.run();
    t3.run();
    t4.run();
    t5.run();

    Test e1 {.text = "&&gt;"};
    Test e2 {.text = "&&&"};
    e1.run();
    e2.run();

    return 0;
}