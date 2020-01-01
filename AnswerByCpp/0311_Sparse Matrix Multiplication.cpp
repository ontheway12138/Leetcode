#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
311. 稀疏矩阵的乘法

给定两个 稀疏矩阵 A 和 B，请你返回 AB。你可以默认 A 的列数等于 B 的行数。
请仔细阅读下面的示例。

示例：

输入:

A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]

B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]

输出:

     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |
*/

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        const int m1 = A.size();
        if (A[0].size() == 0) return {};
        const int n1 = A[0].size();
        const int m2 = B.size();
        const int n2 = B[0].size();
        vector<vector<int>> C(m1, vector<int>(n2, 0));
        for (int i = 0; i < m1; ++i) 
            for (int j = 0; j < n2 ; ++j) {
                int sum = 0;
                for (int k = 0; k < n1; ++k) sum += A[i][k] * B[k][j];

                C[i][j] = sum;
            }
        
        return C;

    }
};