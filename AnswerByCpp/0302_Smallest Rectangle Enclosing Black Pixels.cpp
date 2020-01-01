#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
302. 包含全部黑色像素的最小矩形

图片在计算机处理中往往是使用二维矩阵来表示的。
假设，这里我们用的是一张黑白的图片，那么 0 代表白色像素，1 代表黑色像素。
其中黑色的像素他们相互连接，也就是说，图片中只会有一片连在一块儿的黑色像素（像素点是水平或竖直方向连接的）。
那么，给出某一个黑色像素点 (x, y) 的位置，你是否可以找出包含全部黑色像素的最小矩形（与坐标轴对齐）的面积呢？

示例:

输入:
[
  "0010",
  "0110",
  "0100"
]
和 x = 0, y = 2

输出: 6
*/

class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int R = image.size();
        if (!R) return 0;
        int C = image[0].size();
        vector<int> rowSum(R, 0);
        vector<int> colSum(C, 0);
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++) {
                rowSum[i] += image[i][j] - '0';
                colSum[j] += image[i][j] - '0';
            }
        int r1 = 0, r2 = R-1, c1 = 0, c2 = C-1;
        while (rowSum[r1] == 0 && r1 < r2) r1++;
        while (rowSum[r2] == 0 && r2 > r1) r2--;
        while (colSum[c1] == 0 && c1 < c2) c1++;
        while (colSum[c2] == 0 && c2 > c1) c2--;
        return max((c2 - c1 + 1) * (r2 - r1 + 1), 0);
    }
};
