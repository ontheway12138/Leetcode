#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
248. 中心对称数 III

中心对称数是指一个数字在旋转了 180 度之后看起来依旧相同的数字（或者上下颠倒地看）。
写一个函数来计算范围在 [low, high] 之间中心对称数的个数。

示例:
输入: low = "50", high = "100"
输出: 3 
解释: 69，88 和 96 是三个在该范围内的中心对称数
注意:
由于范围可能很大，所以 low 和 high 都用字符串表示。
*/

class Solution {
public:
    vector<char> A = {'0', '1', '8'};
    unordered_map<char, char> B = {{'6', '9'}, {'9', '6'}};
    int num_less(string n1, string n2) {
        if (n1.size() != n2.size()) return n1.size() < n2.size();
        return n1 <= n2;
    }
    int strobogrammaticInRange(string low, string high) {
        int len1 = low.size();
        int len2 = high.size();
        int res = 0;
        vector<string> dp1 = {""};
        vector<string> dp2 = {"0", "1", "8"};
        for(auto& s : dp2) res += (num_less(s, high) && num_less(low, s));
        for (int i = 2; i <= len2; ++i) {
            vector<string> dp;
            for (auto& s : dp1) {
                for (auto& c : A) dp.push_back(c + s + c);
                for (auto& p : B) dp.push_back(p.first + s + p.second);
            }
            dp1 = dp2;
            dp2 = dp;
            if (i >= len1) for(auto& s : dp) res += num_less(s, high) && num_less(low, s) && s[0] != '0';
        }
        return res;
    }
};