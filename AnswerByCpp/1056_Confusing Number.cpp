#include<iostream>
#include<limits.h>
using namespace std;
/*
1056. 易混淆数

给定一个数字 N，当它满足以下条件的时候返回 true：
把原数字旋转180°以后得到新的数字。
如 0, 1, 6, 8, 9 旋转 180° 以后，得到了新的数字 0, 1, 9, 8, 6 。
2, 3, 4, 5, 7 旋转 180° 后,得到的不是数字。
易混淆数字 (confusing number) 就是一个数字旋转180°以后，得到和原来不同的数字，且新数字的每一位都是有效的。

示例 1：   输入：6    输出：true
解释： 把 6 旋转 180° 以后得到 9，9 是有效数字且 9!=6 。
示例 2：   输入：89   输出：true
解释:  把 89 旋转 180° 以后得到 68，86 是有效数字且 86!=89 。
示例 3：   输入：11   输出：false
解释： 把 11 旋转 180° 以后得到 11，11 是有效数字但是值保持不变，所以 11 不是易混淆数字。 
示例 4：   输入：25   输出：false
解释： 把 25 旋转 180° 以后得到的不是数字。 

提示： 0 <= N <= 10^9
可以忽略掉旋转后得到的前导零，例如，如果我们旋转后得到 0008 那么该数字就是 8 。
*/

class Solution {
public:
    bool confusingNumber(int N) {
        if(!N)return false;
        long long tem = 0, num = N;
        int arr[10] = {0,1,-1,-1,-1,-1,9,-1,8,6};
        while(num){
            int cur = num%10;
            if(arr[cur] == -1)return false;
            tem = tem*10 + arr[cur];
            num /= 10;
        }
        return tem != N;
    }
};

int main(){
    Solution* so = new Solution();
    int N;
    while(cin>>N){
        bool bl = so->confusingNumber(N);
        cout<<bl<<endl;
        string name = "";
        getline(cin, name, '#');
        cout<<name<<endl;
    }
    return 0;
}
