#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
272. 最接近的二叉搜索树值 II

给定一个不为空的二叉搜索树和一个目标值 target，请在该二叉搜索树中找到最接近目标值 target 的 k 个值。

注意： 给定的目标值 target 是一个浮点数
你可以默认 k 值永远是有效的，即 k ≤ 总结点数
题目保证该二叉搜索树中只会存在一种 k 个值集合最接近目标值
示例： 输入: root = [4,2,5,1,3]，目标值 = 3.714286，且 k = 2

    4
   / \
  2   5
 / \
1   3

输出: [4,3]
拓展：
假设该二叉搜索树是平衡的，请问您是否能在小于 O(n)（n 为总结点数）的时间复杂度内解决该问题呢？
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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> result;
        queue<int> q;
        stack<TreeNode*> s;
        TreeNode* node = root;
        do{
            while(node){
                s.push(node);
                node = node->left;                
            }
            node = s.top();
            s.pop();
            if(q.size() < k || abs(q.front() - target) > abs(node->val - target))
                q.push(node->val);
            else
                break;
            if(q.size() > k)
                q.pop();
            
            node = node->right;
        }while(!s.empty() || node);
        for(int i = 0; i < k; i++){
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};