#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
314. 二叉树的垂直遍历

给定一个二叉树，返回其结点 垂直方向（从上到下，逐列）遍历的值。
如果两个结点在同一行和列，那么顺序则为 从左到右。

示例 1：

输入: [3,9,20,null,null,15,7]

   3
  /\
 /  \
9   20
    /\
   /  \
  15   7 

输出:

[
  [9],
  [3,15],
  [20],
  [7]
]
示例 2:

输入: [3,9,8,4,0,1,7]

     3
    /\
   /  \
  9    8
  /\   /\
 /  \ /  \
4   0 1   7 

输出:

[
  [4],
  [9],
  [3,0,1],
  [8],
  [7]
]
示例 3:

输入: [3,9,8,4,0,1,7,null,null,null,2,5]（注意：0 的右侧子节点为 2，1 的左侧子节点为 5）

     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7
    /\
   /  \
   5   2

输出:

[
  [4],
  [9,5],
  [3,0,1],
  [8,2],
  [7]
]
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        map<int, vector<int>> hash;
        queue<pair<TreeNode*, int>> Q;
        
        if(!root) return res;
        
        Q.push(make_pair(root,1));
        while(!Q.empty()){
            auto node = Q.front();
            Q.pop();
            hash[node.second].push_back(node.first->val);
            auto left = node.first->left, right = node.first->right;
            if(left) Q.push(make_pair(left, node.second-1));
            if(right) Q.push(make_pair(right, node.second+1));
        }
        for(auto val:hash) res.push_back(val.second);
        return res;
    }
};
