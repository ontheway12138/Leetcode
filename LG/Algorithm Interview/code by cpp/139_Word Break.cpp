#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
/*
139. 单词拆分

给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

说明：
拆分时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。
示例 1：
输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
示例 2：
输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
     注意你可以重复使用字典中的单词。
示例 3：
输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // 动态规划，判断能否找到
        vector<bool> dp(s.size()+1,false);
        // 存到hash数组，方便查找
        unordered_set<string> hash(wordDict.begin(),wordDict.end());
        dp[0] = true;
        int maxWordLength = 0;
        // 找出最长字符包含的个数，简化运算
        for(auto it:wordDict)maxWordLength = max(maxWordLength,(int)it.size());
        for(int i=1;i<=s.size();i++)
            // 从i之前找匹配
            for(int j=max(0,i-maxWordLength);j<i;j++){
                // dp[j]为当前可以匹配到的最长位置，若后面也可以匹配，则为i匹配
                if(dp[j] && hash.find(s.substr(j,i-j)) != hash.end() ){
                    dp[i] = true;
                    break;
                }
            }
        return dp[s.size()];
    }
};

int main(){
    vector<string> a({"cats", "dog", "sand", "and", "cat"});

    Solution* so = new Solution();
    bool n = so->wordBreak("catsanddog",a);
    cout<<n<<endl;
    return 0;
}

