#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
294. 翻转游戏 II

你和朋友玩一个叫做「翻转游戏」的游戏，游戏规则：给定一个只有 + 和 - 的字符串。
你和朋友轮流将 连续 的两个 "++" 反转成 "--"。 当一方无法进行有效的翻转时便意味着游戏结束，则另一方获胜。
请你写出一个函数来判定起始玩家是否存在必胜的方案。

示例：     输入: s = "++++"          输出: true 
解析:     起始玩家可将中间的 "++" 翻转变为 "+--+" 从而得胜。
延伸： 请推导你算法的时间复杂度。
*/

class Solution {
public:
    bool canWin(string s) {
        for(int i  = 0; i < s.size(); ++i){
            if(i + 1 < s.size() && s[i] == '+' && s[i + 1] == '+'){
                string tmp = s;
                tmp[i] = '-', tmp[i + 1] = '-';
                if(!canWin(tmp)) return true;
            }
        }
        return false;
    }
};