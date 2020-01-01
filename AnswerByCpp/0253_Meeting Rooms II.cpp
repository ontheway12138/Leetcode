#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
253. 会议室 II
 
给定一个会议时间安排的数组，每个会议时间都会包括开始和结束的时间 [[s1,e1],[s2,e2],...] (si < ei)，
为避免会议冲突，同时要考虑充分利用会议室资源，请你计算至少需要多少间会议室，才能满足这些会议安排。

示例 1:       输入: [[0, 30],[5, 10],[15, 20]]      输出: 2
示例 2:       输入: [[7,10],[2,4]]                  输出: 1
*/

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int count = 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {return a[0] < b[0]; });
        list<vector<int>*> myList;
        for (vector<int>& i : intervals) myList.push_back(&i);
        while (myList.size()) {
            list<vector<int>*>::iterator iter = myList.begin();
            int time = 0;
            while (iter != myList.end()) {
                if ((*iter)->at(0) >= time) {
                    time = (*iter)->at(1);
                    iter = myList.erase(iter);
                }
                else
                    iter++;
            }
            count++;
        }
        return count;
    }
};