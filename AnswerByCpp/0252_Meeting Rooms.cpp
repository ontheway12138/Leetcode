#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
252. 会议室
 
给定一个会议时间安排的数组，每个会议时间都会包括开始和结束的时间 [[s1,e1],[s2,e2],...] (si < ei)，
请你判断一个人是否能够参加这里面的全部会议。

示例 1:       输入: [[0,30],[5,10],[15,20]]     输出: false
示例 2:       输入: [[7,10],[2,4]]              输出: true
*/

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.empty() || intervals[0].empty()) 
        return true;

        sort(intervals.begin(), intervals.end(), 
            [] (const vector<int>& a, const vector<int>& b) { return (a[0] < b[0]); });

        for (int i = 0; i < intervals.size() - 1; ++i) {
            if (intervals[i][1] > intervals[i+1][0])
                return false;
        }
        return true;
    }
};