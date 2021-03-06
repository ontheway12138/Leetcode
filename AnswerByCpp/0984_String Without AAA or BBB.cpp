#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
/*
984. 不含 AAA 或 BBB 的字符串

给定两个整数 A 和 B，返回任意字符串 S，要求满足： S 的长度为 A + B，
且正好包含 A 个 'a' 字母与 B 个 'b' 字母； 子串 'aaa' 没有出现在 S 中； 子串 'bbb' 没有出现在 S 中。

示例 1：   输入：A = 1, B = 2     输出："abb"
解释："abb", "bab" 和 "bba" 都是正确答案。
示例 2：   输入：A = 4, B = 1     输出："aabaa"

提示：     0 <= A <= 100       0 <= B <= 100       对于给定的 A 和 B，保证存在满足要求的 S。
*/

class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string res = "";
        while(A != 0 && B != 0 ){
            if(A > B) res += "aab", A -= 2, B -= 1;
            else if(B > A) res += "bba", A -= 1, B -= 2;
            else res += "ab", A -= 1, B -= 1;
        }
        if(A != 0) res += string(A, 'a');
        if(B != 0) res += string(B, 'b');
        return res;
    }
};

int main(){
    string res = Solution().strWithout3a3b(3, 6);
    cout<<res<<endl;

    return 0;
}