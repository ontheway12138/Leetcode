#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
280. 摆动排序

给你一个无序的数组 nums, 将该数字 原地 重排后使得 nums[0] <= nums[1] >= nums[2] <= nums[3]...。

示例:
输入: nums = [3,5,2,1,6,4]
输出: 一个可能的解答是 [3,5,1,6,2,4]
*/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i+=2){
            if(i==nums.size()-1)break;
            auto temp=nums[i];
            nums[i]=nums[i+1];
            nums[i+1]=temp;
        }
    }
};