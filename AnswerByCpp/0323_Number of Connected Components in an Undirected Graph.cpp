#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
323. 无向图中连通分量的数目

给定编号从 0 到 n-1 的 n 个节点和一个无向边列表（每条边都是一对节点），
请编写一个函数来计算无向图中连通分量的数目。

示例 1:
输入: n = 5 和 edges = [[0, 1], [1, 2], [3, 4]]
     0          3
     |          |
     1 --- 2    4 
输出: 2
示例 2:
输入: n = 5 和 edges = [[0, 1], [1, 2], [2, 3], [3, 4]]

     0           4
     |           |
     1 --- 2 --- 3

输出:  1
注意:
你可以假设在 edges 中不会出现重复的边。而且由于所以的边都是无向边，[0, 1] 与 [1, 0]  相同，所以它们不会同时在 edges 中出现。
*/

class Solution {
public:
    vector<int> F;
    int father(int i) {
        if (i != F[i])
            F[i] = father(F[i]);
        return F[i];
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        F.resize(n);
        for (int i = 0; i < n; ++i)
            F[i] = i;
        for (auto& e : edges) {
            int f1 = father(e[0]);
            int f2 = father(e[1]);
            if (f1 == f2)
                continue;
            if (f1 < f2) {
                F[f1] = f2;
            } else {
                F[f2] = f1;
            }
        }
        set<int> s;
        for (int i = 0; i < n; ++i) {
            s.insert(father(i));
        }
        return s.size();
    }
};
