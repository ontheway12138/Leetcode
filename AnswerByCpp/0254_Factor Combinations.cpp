#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
254. 因子的组合
 
整数可以被看作是其因子的乘积。

例如：

8 = 2 x 2 x 2;
  = 2 x 4.
请实现一个函数，该函数接收一个整数 n 并返回该整数所有的因子组合。

注意：

你可以假定 n 为永远为正数。
因子必须大于 1 并且小于 n。
示例 1：     输入: 1     输出: []
示例 2：     输入: 37    输出: []
示例 3：
输入: 12
输出:
[
  [2, 6],
  [2, 2, 3],
  [3, 4]
]
示例 4:

输入: 32
输出:
[
  [2, 16],
  [2, 2, 8],
  [2, 2, 2, 4],
  [2, 2, 2, 2, 2],
  [2, 4, 4],
  [4, 8]
]
*/

class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<int> sub;
        vector<vector<int>> res;
        if(n<2){
            return res;
        }
        helper(n,2,sub,res);
        return res;
    }
private:
    void helper(int n,int start,vector<int>& sub,vector<vector<int>>& res){
        for(int i=start;i<=sqrt(n);i++){
            if(n%i==0){
                sub.push_back(i);
                sub.push_back(n/i);
                res.push_back(sub); 
                sub.pop_back();
                helper(n/i,i,sub,res);
                sub.pop_back();
            }
        }
    }
};