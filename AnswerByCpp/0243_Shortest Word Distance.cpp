#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
243. 最短单词距离
 
给定一个单词列表和两个单词 word1 和 word2，返回列表中这两个单词之间的最短距离。

示例:
假设 words = ["practice", "makes", "perfect", "coding", "makes"]

输入: word1 = “coding”, word2 = “practice”
输出: 3
输入: word1 = "makes", word2 = "coding"
输出: 1
注意:
你可以假设 word1 不等于 word2, 并且 word1 和 word2 都在列表里。
*/

class Solution {
public:
    int shortestDistance(vector<string> &words, string word1, string word2) {
        int pos1 = -1, pos2 = -1, res = INT_MAX;
        
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) {
                pos1 = i;
                if (pos2 >= 0) res = min(res, i - pos2);
            } else if (words[i] == word2) {
                pos2 = i;
                if (pos1 >= 0) res = min(res, i - pos1);
            }
        }
        
        return res;
    }
};