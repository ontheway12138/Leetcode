#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
159. 至多包含两个不同字符的最长子串
 
给定一个字符串 s ，找出 至多 包含两个不同字符的最长子串 t 。
示例 1:       输入: "eceba"         输出: 3
解释: t 是 "ece"，长度为3。
示例 2:       输入: "ccaabbb"       输出: 5
解释: t 是 "aabbb"，长度为5。
*/

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if (s.size() < 3) return s.size();
        int l = 0, r = 0, res = 2, n = s.size();
        while (l < n) {
            r = l;
            while (r+1 < n && s[r+1] == s[l]) r++;
            int tmp = r+1;
            while (r+1 < n && (s[r+1] == s[tmp] || s[r+1] == s[l])) r++;
            res = max(res, r-l+1);
            l = tmp;
        }
        return res;
    }
};