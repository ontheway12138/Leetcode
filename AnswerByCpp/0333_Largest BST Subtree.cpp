#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
333. 最大 BST 子树

给定一个二叉树，找到其中最大的二叉搜索树（BST）子树，其中最大指的是子树节点数最多的。
注意: 子树必须包含其所有后代。
示例: 输入: [10,5,15,1,8,null,7]

   10 
   / \ 
  5  15 
 / \   \ 
1   8   7

输出: 3
解释: 高亮部分为最大的 BST 子树。
     返回值 3 在这个样例中为子树大小。
进阶: 你能想出用 O(n) 的时间复杂度解决这个问题吗？
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
    bool helper(TreeNode* root,vector<int> & res,int & maxTree){
        bool lbst = true;
        bool rbst = true;
        bool bst = true;
        int l = res.size();
        int r = res.size();
        if(!root){ return true; }
        /*left Tree*/
        if(root->left){
            lbst = helper(root->left,res,maxTree);
            if(!lbst||root->val <= res.back()){  bst = false;}
        } 
        /*root node*/
        res.push_back(root->val);
        r = res.size();
        /*right Tree*/
        if(root->right){
            rbst = helper(root->right,res,maxTree);
            if(!rbst||root->val >= res[r]){bst = false; }
        }
        r = res.size();
        if(bst){ maxTree = max(maxTree,r-l);}
        return bst;
    }
    int largestBSTSubtree(TreeNode* root) {
        vector<int> nums;
        int ans = 0;
        helper(root,nums,ans);
        return ans;
    }
};