#include <bits/stdc++.h>
using namespace std;
class MagicDictionary {
    unordered_map<size_t, vector<string>> lens;
    bool check(string& x, string& y) {
        short cnt = 0;
        for (int i = x.size() - 1; ~i; --i) {
            if (x[i] != y[i] && ++cnt > 1)
                return false;
        }
        return cnt == 1;
    }
public:
    MagicDictionary() { }

    void buildDict(vector<string> dictionary) {
        for (auto& s : dictionary) {
            lens[s.size()].emplace_back(s);
        }
    }

    bool search(string searchWord) {
        for (auto& s : lens[searchWord.size()]) {
            if (check(searchWord, s))
                return true;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
