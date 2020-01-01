#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
266. 回文排列

给定一个字符串，判断该字符串中是否可以通过重新排列组合，形成一个回文字符串。
示例 1：
输入: "code"
输出: false
示例 2：
输入: "aab"
输出: true
示例 3：
输入: "carerac"
输出: true
*/

class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> m;
        for (char i : s) ++m[i];
        int odd = 0;
        for (auto i : m) odd += i.second & 1;
        return odd <= 1;
    }
};