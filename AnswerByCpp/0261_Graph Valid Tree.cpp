#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
261. 以图判树

给定从 0 到 n-1 标号的 n 个结点，和一个无向边列表（每条边以结点对来表示），
请编写一个函数用来判断这些边是否能够形成一个合法有效的树结构。

示例 1： 输入: n = 5, 边列表 edges = [[0,1], [0,2], [0,3], [1,4]]
输出: true
示例 2: 输入: n = 5, 边列表 edges = [[0,1], [1,2], [2,3], [1,3], [1,4]]
输出: false
注意：你可以假定边列表 edges 中不会出现重复的边。由于所有的边是无向边，
边 [0,1] 和边 [1,0] 是相同的，因此不会同时出现在边列表 edges 中。
*/

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto& v: edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        
        using P = pair<int,int>;
        queue<P> q;
        q.push(P(0,0));
        set<int> visited;
            
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                P curr = q.front();
                if(visited.count(curr.first)) return false;
                visited.insert(curr.first);
                q.pop();
                for(int i: adj[curr.first]){
                    if(i != curr.second){
                        q.push(P(i, curr.first));
                    }
                }
            }
        }
        
        return visited.size() == n;
    }
};