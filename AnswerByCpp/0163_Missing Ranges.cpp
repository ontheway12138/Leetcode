#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
163. 缺失的区间
 
给定一个排序的整数数组 nums ，其中元素的范围在 闭区间 [lower, upper] 当中，返回不包含在数组中的缺失区间。

示例：
输入: nums = [0, 1, 3, 50, 75], lower = 0 和 upper = 99,
输出: ["2", "4->49", "51->74", "76->99"]
*/

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> result;
        int n = nums.size();
        int left = lower;
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            
            if (num < left) continue;
            
            if (num != left) {
                if (num == left + 1) result.push_back(to_string(left));
                else result.push_back(to_string(left) + "->" + to_string(num - 1));
            }
            
            if (num == upper) return result;
            
            left = num + 1;
        }
        
        if (left == upper) result.push_back(to_string(upper));
        else result.push_back(to_string(left) + "->" + to_string(upper));
        
        return result;
    }
};
