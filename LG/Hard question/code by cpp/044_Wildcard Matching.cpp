#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
/*
44. 通配符匹配

给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。

'?' 可以匹配任何单个字符。
'*' 可以匹配任意字符串（包括空字符串）。
两个字符串完全匹配才算匹配成功。
说明:
s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。
示例 1:
输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。
示例 2:
输入:
s = "aa"
p = "*"
输出: true
解释: '*' 可以匹配任意字符串。
示例 3:
输入:
s = "cb"
p = "?a"
输出: false
解释: '?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
示例 4:
输入:
s = "adceb"
p = "*a*b"
输出: true
解释: 第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".
示例 5:
输入:
s = "acdcb"
p = "a*c?b"
输入: false
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        // 当前s的位置，和p的位置
        int curS = 0, curP = 0, match = 0, star = -1;
        while(curS < s.length()){
            // 正常匹配
            if(curP < p.length() && (s[curS]==p[curP] || p[curP]=='?'))
                curS++,curP++;
            // 遇到*号时，先暂存星号的位置，match为当前匹配的距离
            else if(curP < p.length() && p[curP]=='*')
                star = curP, match = curS,curP++;
            else if(star!=-1)
                curP = star+1, match++, curS = match;
            else return false;
        }
        while(curP < p.length() && p[curP]=='*')
            curP++;
        return curP == p.length();
    }
};

int main(){
    Solution* so = new Solution();
    bool n = so->isMatch("acdcb","a*c?b");
    cout<<n<<endl;
    return 0;
}
