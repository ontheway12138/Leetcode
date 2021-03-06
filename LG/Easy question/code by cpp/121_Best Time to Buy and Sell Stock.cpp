#include<iostream>
#include<vector>
using namespace std;
/*
121. 买卖股票的最佳时机

给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。

注意你不能在买入股票前卖出股票。

示例 1:

输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
示例 2:

输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
*/
int maxProfit(vector<int>& prices) {
    if(prices.size() == 0) return 0;
    int max_price = prices.back();
    int max_profit = 0;
    // 从后往前找，先找最大值，再找最大利润
    for(int i = prices.size() - 1; i--; i >= 0){
        max_price = max(max_price, prices[i]);
        max_profit = max(max_profit, max_price - prices[i]);
    }
    return max_profit;
}

int main(){
    int x[7] = {7,1,5,3,6,4};
    vector<int>nums(x,x+7);
    int n = maxProfit(nums);
    cout<<n<<endl;
	return 0;
}
