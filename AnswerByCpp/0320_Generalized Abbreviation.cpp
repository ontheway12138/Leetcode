#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
320. 列举单词的全部缩写

请你写出一个能够举单词全部缩写的函数。
注意：输出的顺序并不重要。

示例： 输入: "word"
输出: ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d",
       "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
*/

class Solution {
public:
   string bmToString(int  mask,string & word){
        string ans;
        int idx = 0;
        while(idx < word.size()){
            int last = idx;
            while(idx < word.size() && ((mask&(1<<idx))>>idx)) idx++;
              
            if(last != idx)
                ans += to_string(idx-last);
            else ans.push_back(word[idx++]);
        }
        return ans;
   }
   vector<string> generateAbbreviations(string word) {
        int n = word.size();
        int mask = 1<<n;  
        vector<string> ans;
        for(int i = 0;i < mask; ++i)
            ans.push_back(bmToString(i,word));  
        return ans;
    }
};