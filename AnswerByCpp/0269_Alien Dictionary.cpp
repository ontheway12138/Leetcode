#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
269. 火星词典

现有一种使用字母的全新语言，这门语言的字母顺序与英语顺序不同。
假设，您并不知道其中字母之间的先后顺序。但是，会收到词典中获得一个 不为空的 单词列表。
因为是从词典中获得的，所以该单词列表内的单词已经 按这门新语言的字母顺序进行了排序。
您需要根据这个输入的列表，还原出此语言中已知的字母顺序。

示例 1：

输入:
[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]

输出: "wertf"
示例 2：

输入:
[
  "z",
  "x"
]

输出: "zx"
示例 3：

输入:
[
  "z",
  "x",
  "z"
] 

输出: "" 

解释: 此顺序是非法的，因此返回 ""。
注意：
你可以默认输入的全部都是小写字母
假如，a 的字母排列顺序优先于 b，那么在给定的词典当中 a 定先出现在 b 前面
若给定的顺序是不合法的，则返回空字符串即可
若存在多种可能的合法字母顺序，请返回其中任意一种顺序即可
*/

class Solution {
private:
    int cnt;
    vector<int> in_degree;
    vector<vector<int>> graph;
    
    void init_graph(vector<string>& words) {
        for (char c : words[0]) 
            if (in_degree[c - 'a'] == -1) ++cnt,in_degree[c - 'a'] = 0;
        for (int i = 0; i < words.size() - 1; i++) {
            for (char c : words[i + 1]) 
                if (in_degree[c - 'a'] == -1) ++cnt,in_degree[c - 'a'] = 0;
            for (int j = 0; j < words[i].size(); j++) {
                char from = words[i][j], to = words[i + 1][j];
                if (from == to) continue;
                graph[from - 'a'].push_back(to - 'a');
                ++in_degree[to - 'a'];
                break;
            }
        }
    }
    
    string topology_sort() {
        string ans = "";
        
        queue<int> q;
        for (int i = 0; i < in_degree.size(); i++) {
            if (in_degree[i] > 0 || in_degree[i] == -1) continue;
            q.push(i);
            ans += (i + 'a');
        }
        
        while (!q.empty()) {
            for (int i = q.size(); i > 0; --i) {
                int from = q.front(); q.pop();
                for (int to : graph[from]) {
                    if (in_degree[to] == 1) {
                        q.push(to);
                        ans += (to + 'a');
                    }
                    --in_degree[to];
                }
            }
        }
        
        return ans.size() == cnt ? ans : "";
    }
    
public:
    Solution():cnt (0), in_degree(26, -1), graph(26) {}
    
    string alienOrder(vector<string>& words) {
        
        init_graph(words);
        
        return topology_sort();
    }
};