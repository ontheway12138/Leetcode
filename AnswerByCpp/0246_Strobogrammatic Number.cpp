#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
246. 中心对称数

中心对称数是指一个数字在旋转了 180 度之后看起来依旧相同的数字（或者上下颠倒地看）。
请写一个函数来判断该数字是否是中心对称数，其输入将会以一个字符串的形式来表达数字。

示例 1:       输入:  "69"       输出: true
示例 2:       输入:  "88"       输出: true
示例 3:       输入:  "962"      输出: false
*/

class Solution {
public:
    bool isStrobogrammatic(string num) {
        int s=num.size();
        if(s%2==1) 
        {
            char mid=num[s/2];
            if(mid!='0'&&mid!='1'&&mid!='8') return false;
        }
       unordered_map<char,char> a{{'0','0'}, {'1','1'}, {'6','9'}, {'8','8'}, {'9','6'}};
        for(int i=0;i<s/2;i++)
        {
            char p=num[i];
            if(a[p]!=-1&&a[p]==num[s-i-1])
               continue;
            else return false;
        }
        return true;
    }
};