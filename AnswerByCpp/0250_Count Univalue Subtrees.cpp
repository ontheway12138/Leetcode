#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
250. 统计同值子树
 
给定一个二叉树，统计该二叉树数值相同的子树个数。
同值子树是指该子树的所有节点都拥有相同的数值。

示例：

输入: root = [5,1,5,5,5,null,5]

              5
             / \
            1   5
           / \   \
          5   5   5

输出: 4
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
    int count = 0;
    bool _countUnivalSubtrees(TreeNode* root)
    {
        if(root == nullptr)
            return true;
        
        bool l = _countUnivalSubtrees(root->left);
        bool r = _countUnivalSubtrees(root->right);
        bool cur = true;
        
        if(root->left && root->val != root->left->val)
            cur = false;
        if(root->right && root->val != root->right->val)
            cur = false;
        if(cur && l && r) count++;
        
        return cur && l && r;
    }
    int countUnivalSubtrees(TreeNode* root) {
        _countUnivalSubtrees(root);
        return count;
    }
};