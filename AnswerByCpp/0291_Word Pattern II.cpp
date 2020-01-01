#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
291. 单词规律 II

给你一种规律 pattern 和一个字符串 str，请你判断 str 是否遵循其相同的规律。
这里我们指的是 完全遵循，例如 pattern 里的每个字母和字符串 str 中每个 非空 单词之间，存在着双向连接的对应规律。

示例1:    输入: pattern = "abab", str = "redblueredblue"        输出: true
示例2:    输入: pattern = "aaaa", str = "asdasdasdasd"          输出: true
示例2:    输入: pattern = "aabb", str = "xyzabcxzyabc"          输出: false
说明:     你可以默认 pattern 和 str 都只会包含小写字母。
*/

class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        unordered_map<char, string> m;
        set<string> s;
        return helper(pattern, 0, str, 0, m, s);
    }
    bool helper(string pattern, int p, string str, int r, unordered_map<char, string> &m, set<string> &s) {
        if (p == pattern.size() && r == str.size()) return true;
        if (p == pattern.size() || r == str.size()) return false;
        char c = pattern[p];
        for (int i = r; i < str.size(); ++i) {
            string t = str.substr(r, i - r + 1);
            if (m.count(c) && m[c] == t) {
                if (helper(pattern, p + 1, str, i + 1, m, s)) return true;
            } else if (!m.count(c)) {
                if (s.count(t)) continue;
                m[c] = t;
                s.insert(t);
                if (helper(pattern, p + 1, str, i + 1, m, s)) return true;
                m.erase(c);
                s.erase(t);
            }
        }
        return false;
    }
};