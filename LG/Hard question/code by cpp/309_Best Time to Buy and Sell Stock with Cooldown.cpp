#include<iostream>
#include<vector>
using namespace std;
/*
309. 最佳买卖股票时机含冷冻期

给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。​

设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
示例:

输入: [1,2,3,0,2]
输出: 3 
解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(!prices.size())return 0;
        int pre=0,res=0,cur=prices[0];
        for(int i=1;i<prices.size();i++){
            cur = min(cur,prices[i]-pre);
            pre = res;
            res = max(res,prices[i]-cur);
        }
        return res;
    }
};

int main(){
    vector<int> a({0,9,34,214});

    Solution* so = new Solution();
    string n = so->largestNumber(a);
    cout<<n<<endl;
    return 0;
}
