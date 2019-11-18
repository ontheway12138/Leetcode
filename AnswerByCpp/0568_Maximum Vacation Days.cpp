#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
using namespace std;
/*
568. 最大休假天数

力扣想让一个最优秀的员工在 N 个城市间旅行来收集算法问题。 但只工作不玩耍，聪明的孩子也会变傻，所以您可以在某些特定的城市和星期休假。
您的工作就是安排旅行使得最大化你可以休假的天数，但是您需要遵守一些规则和限制。
规则和限制： 您只能在 N 个城市之间旅行，用 0 到 N-1 的索引表示。一开始，您在索引为0的城市，并且那天是星期一。
这些城市通过航班相连。这些航班用 N*N 矩阵 flights（不一定是对称的）表示，flights[i][j] 代表城市i到城市j的航空状态。
如果没有城市i到城市j的航班，flights[i][j] = 0；否则，flights[i][j] = 1。同时，对于所有的i，flights[i][i] = 0。
您总共有 K 周（每周7天）的时间旅行。您每天最多只能乘坐一次航班，并且只能在每周的星期一上午乘坐航班。
由于飞行时间很短，我们不考虑飞行时间的影响。
对于每个城市，不同的星期您休假天数是不同的，给定一个 N*K 矩阵 days 代表这种限制，days[i][j] 代表您在第j个星期在城市i能休假的最长天数。
给定 flights 矩阵和 days 矩阵，您需要输出 K 周内可以休假的最长天数。
示例 1:   输入:flights = [[0,1,1],[1,0,1],[1,1,0]], days = [[1,3,1],[6,0,3],[3,3,3]]    输出: 12
解释:     Ans = 6 + 3 + 3 = 12. 
最好的策略之一： 第一个星期 : 星期一从城市0飞到城市1，玩6天，工作1天。 
（虽然你是从城市0开始，但因为是星期一，我们也可以飞到其他城市。） 
第二个星期 : 星期一从城市1飞到城市2，玩3天，工作4天。
第三个星期 : 呆在城市2，玩3天，工作4天。
示例 2:   输入:flights = [[0,0,0],[0,0,0],[0,0,0]], days = [[1,1,1],[7,7,7],[7,7,7]]    输出: 3
解释:     Ans = 1 + 1 + 1 = 3. 
由于没有航班可以让您飞到其他城市，你必须在城市0呆整整3个星期。 
对于每一个星期，你只有一天时间玩，剩下六天都要工作。 所以最大休假天数为3.
示例 3:   输入:flights = [[0,1,1],[1,0,1],[1,1,0]], days = [[7,0,0],[0,7,0],[0,0,7]]    输出: 21
解释: Ans = 7 + 7 + 7 = 21
最好的策略之一是： 第一个星期 : 呆在城市0，玩7天。 
第二个星期 : 星期一从城市0飞到城市1，玩7天。
第三个星期 : 星期一从城市1飞到城市2，玩7天。

注意: N 和 K 都是正整数，在 [1, 100] 范围   矩阵 flights 的所有值都是 [0, 1] 范围内的整数。
矩阵 days 的所有值都是 [0, 7] 范围内的整数。
超过休假天数您仍可以呆在那个城市，但是在额外的日子您需要 工作 ，这些日子不会算做休假日。
如果您从城市A飞往城市B并在当天休假日，这个休假会被算作是城市B的休假日。
我们不考虑飞行时间对计算休假日的影响。
*/

class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int city = flights.size(), day = days[0].size(), res = 0;
        vector<int> restDays(city, -1);
        vector<int> nextDays(city, -1);
        restDays[0] = 0;
        for (int i=0; i<day; i++) {
            for (int j=0; j<city; j++) {
                if (restDays[j] == -1) continue;
                nextDays[j] = max(nextDays[j], restDays[j] + days[j][i]);
                for (int k = 0; k<city; k++) if (flights[j][k] == 1) 
                    nextDays[k] = max(nextDays[k], restDays[j] + days[k][i]);
            }
            restDays = nextDays;
        }
        for (auto &it : restDays) res = max(res, it);
        return res;
    }
};

int main(){
    vector<vector<int>> flights1{{0,1,1},{1,0,1},{1,1,0}};
    vector<vector<int>> days1{{1,3,1},{6,0,3},{3,3,3}};
    vector<vector<int>> flights2{{0,0,0},{0,0,0},{0,0,0}};
    vector<vector<int>> days2{{1,1,1},{7,7,7},{7,7,7}};
    vector<vector<int>> flights3{{0,1,1},{1,0,1},{1,1,0}};
    vector<vector<int>> days3{{7,0,0},{0,7,0},{0,0,7}};
    int res1 = Solution().maxVacationDays(flights1, days1);
    int res2 = Solution().maxVacationDays(flights2, days2);
    int res3 = Solution().maxVacationDays(flights3, days3);
    cout << res1 << " " << res2 << " " << res3 << endl;
    return 0;
}