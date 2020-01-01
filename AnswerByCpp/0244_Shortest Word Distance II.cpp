#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
244. 最短单词距离 II
 
请设计一个类，使该类的构造函数能够接收一个单词列表。然后再实现一个方法，
该方法能够分别接收两个单词 word1 和 word2，并返回列表中这两个单词之间的最短距离。
您的方法将被以不同的参数调用 多次。

示例:
假设 words = ["practice", "makes", "perfect", "coding", "makes"]

输入: word1 = “coding”, word2 = “practice”
输出: 3
输入: word1 = "makes", word2 = "coding"
输出: 1
注意:
你可以假设 word1 不等于 word2, 并且 word1 和 word2 都在列表里。
*/

class WordDistance {
private:
    unordered_map<string, vector<int> > mp;
public:
    WordDistance(vector<string>& ws) {
        int index = 0;
        for(auto w : ws) mp[w].push_back(index++);
    }
    
    int shortest(string word1, string word2) {
        vector<int> index1 = mp[word1], index2 = mp[word2];
        int minDist = INT_MAX;
        for(auto i : index1) for(auto j : index2) minDist = min(minDist, abs(i - j));
        return minDist;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */
