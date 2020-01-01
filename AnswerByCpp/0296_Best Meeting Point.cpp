#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
296. 最佳的碰头地点

有一队人（两人或以上）想要在一个地方碰面，他们希望能够最小化他们的总行走距离。
给你一个 2D 网格，其中各个格子内的值要么是 0，要么是 1。
1 表示某个人的家所处的位置。这里，我们将使用 曼哈顿距离 来计算，
其中 distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|。

示例： 输入: 
1 - 0 - 0 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0

输出: 6 

解析: 给定的三个人分别住在(0,0)，(0,4) 和 (2,2):
     (0,2) 是一个最佳的碰面点，其总行走距离为 2 + 2 + 2 = 6，最小，因此返回 6。
*/

class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> vx;
        vector<int> vy;
        for(int i = 0;i<grid.size();i++)
            for(int j = 0;j<grid[0].size();j++)
                if(grid[i][j]==1) vx.push_back(i), vy.push_back(j);
                
        sort(vx.begin(),vx.end());
        sort(vy.begin(),vy.end());
        int ans = 0;
        int midx = vx[vx.size()/2];
        int midy = vy[vy.size()/2];
        for(int i = 0;i<vx.size();i++) ans += abs(midx-vx[i]);
        
        for(int i = 0;i<vy.size();i++) ans += abs(midy-vy[i]);
        
        return ans;
    }
};