package LCP;

/*
	你有一块棋盘，棋盘上有一些格子已经坏掉了。
	你还有无穷块大小为1 * 2的多米诺骨牌，
	你想把这些骨牌不重叠地覆盖在完好的格子上，
	请找出你最多能在棋盘上放多少块骨牌？
	这些骨牌可以横着或者竖着放。 
	
	输入：
		n, m代表棋盘的大小；
		broken是一个b * 2的二维数组，
		其中每个元素代表棋盘上每一个坏掉的格子的位置。
	
	输出：
		一个整数，代表最多能在棋盘上放的骨牌数。
	
	 
	
	示例 1：
		输入：n = 2, m = 3, broken = [[1, 0], [1, 1]]
		输出：2
		解释：我们最多可以放两块骨牌：[[0, 0], [0, 1]]以及[[0, 2], [1, 2]]。（见下图）
		https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/09/09/domino_example_1.jpg
	示例 2：
		输入：n = 3, m = 3, broken = []
		输出：4
		解释：下图是其中一种可行的摆放方式
		https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/09/09/domino_example_2.jpg
	
	限制：
		1 <= n <= 8
		1 <= m <= 8
		0 <= b <= n * m
		
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/broken-board-dominoes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

//LCP 4. 覆盖
public class LCP_004_BrokenBoardDominoes {
	int n;
	int m;
	int ret;
	int max;
	public int domino(int n, int m, int[][] broken) {
		ret = 0;
		max = 0;
		
		int[][] board = new int[n][m];
		for(int[] bro:broken) {
			board[bro[0]][bro[1]] = 2;
		}
		this.n = n;
		this.m = m;
		dfs(board,0,0);
		return max;
	}

	private void dfs(int[][] board, int i, int j) {
		if(i>=n) {
			//最后一行
			max =Math.max(max, ret);
			return;
		}
		if(j>=m) {
			//最后一列
			dfs(board,i+1,0);
			return;
		}
		if(board[i][j]>0) {
			dfs(board,i,j+1);
			return;
		}
		//横着放
		boolean h = false;
		if(i<n-1&&board[i][j+1]==0) {
			h = true;
			board[i][j]++;
			board[i][j+1]++;
			ret++;
			dfs(board,i,j+2);
			ret--;
			board[i][j]--;
			board[i][j+1]--;
		}
		//竖着放
		boolean v = false;
		if(i<m-1&&board[i+1][j]==0) {
			h = true;
			board[i][j]++;
			board[i+1][j]++;
			ret++;
			dfs(board,i,j+1);
			ret--;
			board[i][j]--;
			board[i+1][j]--;
		}
		if(!h&&!v) {
			dfs(board,i,j+2);
		}
	}
}
