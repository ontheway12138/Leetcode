#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
259. 较小的三数之和
 
给定一个长度为 n 的整数数组和一个目标值 target，寻找能够使条件 
nums[i] + nums[j] + nums[k] < target 成立的三元组  i, j, k 个数（0 <= i < j < k < n）。

示例：
输入: nums = [-2,0,1,3], target = 2
输出: 2 
解释: 因为一共有两个三元组满足累加和小于 2:
     [-2,0,1]
     [-2,0,3]
进阶：是否能在 O(n2) 的时间复杂度内解决？
*/

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort( nums.begin(), nums.end());
    
        //O(N^2)的解决方法
        int res = 0;
        for( int i = 0; i < nums.size() ; i++)
            for( int j = i + 1, k = nums.size() - 1; j < k; ){
                if( nums[i] + nums[j] + nums[k] < target)
                    res += k - j, ++j;
                else 
                    k--;
            }

        return res;
    }
};