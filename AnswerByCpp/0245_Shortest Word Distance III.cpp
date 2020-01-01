#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
245. 最短单词距离 III

给定一个单词列表和两个单词 word1 和 word2，返回列表中这两个单词之间的最短距离。
word1 和 word2 是有可能相同的，并且它们将分别表示为列表中两个独立的单词。

示例:
假设 words = ["practice", "makes", "perfect", "coding", "makes"].

输入: word1 = “makes”, word2 = “coding”
输出: 1
输入: word1 = "makes", word2 = "makes"
输出: 3
注意: 你可以假设 word1 和 word2 都在列表里。
*/

class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        map<string,vector<int>> dict;
        int ans = words.size();
        
        for(int i = 0;i < words.size(); ++i){
            dict[words[i]].push_back(i);
        }
        
        if(word1 == word2){
            auto v = dict[word1];
            for(int i = 1;i < v.size(); ++i){
                ans = min(ans,v[i] - v[i-1]);
            }
        }else{
            auto v1 = dict[word1];
            auto v2 = dict[word2];
            for(int i = 0;i < v1.size(); ++i){
                for(int j = 0;j < v2.size(); ++j){
                    ans = min(ans,abs(v2[j] - v1[i]));
                }
            }
        }
        
        return ans;
    }
};